/*** includes ***/
#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <asm-generic/ioctls.h>
#include<unistd.h>
#include<stdarg.h>
#include<time.h>
/*
 * struct termios, tcgetattr(), tcsetattr(), ECHO, TCSAFLUSH
 * come from <termios.h>
 * */
#include<termios.h>

/*
 * Disable raw mode at exit
 * restore user terminal's original attributes when our program exit
 * copy of termios struct and use tcsetattr() to apply it to terminal 
 * when the program exits.
 * */
#include<stdlib.h>

// save editor
#include<fcntl.h>

/*
 * */

#include<ctype.h> // insctrl()
#include<stdio.h> // printf()

#include <errno.h> // errno and EAGAIN

#include<sys/ioctl.h> //Input/Ouput Control Get WINdow SiZe.

#include<string.h> // memcpy
// edit row
#include<sys/types.h>
/*** defines ***/
#define KILO_VERSION "0.0.1"
#define KILO_TAB_STOP 8
#define KILO_QUIT_TIMES 3
#define CTRL_KEY(k) ((k) & 0x1f)
// handling with arrow key
enum editorKey{
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	// Page up and Page down
	PAGE_UP,
	PAGE_DOWN,
	// HOME AND END
	HOME_KEY,
	END_KEY,
	// DELETE KEY
	DEL_KEY
};
enum editorHighlight{
	HL_NORMAL = 0, 
	HL_COMMENT,
	HL_MLCOMMENT,
	HL_KEYWORD1,
	HL_KEYWORD2,
	HL_NUMBER,
	HL_STRING,
	HL_MATCH
};

// detect file type
#define HL_HIGHLIGHT_NUMBERS (1<<0)
#define HL_HIGHLIGHT_STRINGS (1<<1)
/***DATA***/
// use global var to store the original terminal attributes
// text viewers
struct editorSyntax{
	char *filetype;
	char **filematch;
	char *singleline_comment_start;
	char **keywords;
	char *multiline_comment_start;
	char *multiline_comment_end;
	int flags;
};
typedef struct erow{
	int idx;
	int hl_open_comment;
	// rendering tabs
	int rsize;
	char *render;
	//
	int size;
	char *chars; 
	unsigned char *hl;
}erow;
//
struct editorConfig{
	int screenrows;
	int screencols;
	int rx;
	int coloff;
	int rowoff;
	// dirty flag
	int dirty;
	// move the cursor
	int cx, cy;

	// Text viewer
	int numrows;
	erow *row;
	char *filename;
	struct editorSyntax *syntax;
	struct termios orig_termios;

	// status message
	char statusmsg[80];
	time_t statusmsg_time;
};
struct editorConfig E;
/*** filetypes */
char *C_HL_extensions[] = {".c", ".h", ".cpp", NULL};
char *C_HL_keywords[] = {
  "switch", "if", "while", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "static", "enum", "class", "case",
  "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
  "void|", NULL
};
struct editorSyntax HLDB[] = {
	{
		"c",
		C_HL_extensions,
		C_HL_keywords,
		"//","/*", "*/",
		// we use in_string variable to keep track of wheter
		// we are currently inside a string. If we are, then 
		// we'll keep highlighting the current character as a string
		// until we hit the closing quote
		HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
	},
};
#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
/*** prototypes ***/
void editorSetStatusMessage(const char *fmt, ...);
void editorRefreshScreen();
char *editorPrompt(char *prompt, void (*callback)(char *, int));
/***TERMINAL***/
//Error handling
void die(const char *s){
	// Clear the screen on exit
	write(STDOUT_FILENO, "\x1b[2J",4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	//
	perror(s); // comes from stdio.h and exit from stdlib.h
	exit(1);
}


void disableRawMode(){

	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	//update
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1){
		die("tcsetattr");
	}
}

void enableRawMode(){
	// settings for disable raw mode
	// loading last terminal then up
	if(tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");
	/*
	 * atexit() comes from <stdlib.h>, use it to register disableRawMode() function
	 * called automatically when the program exits, whetber it exits by returning from main()
	 * or by calling the exit()
	 * */
	atexit(disableRawMode);

	//
	struct termios raw=E.orig_termios;
	

	// set a terminal's attributes
	// by using tcgetattr read current attributes into struct &raw
	//tcgetattr(STDIN_FILENO, &raw);
	
	
	// Disable Ctrl-S: IXON 19 byte and Ctrl-Q: 17 byte
	// Fix Ctrl-M: ICRNL : Inputflag, CarriageReturn, NewLine
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	// local flags
	// modifying the struct 
	// ICANON comes from termios.h
	// ICANON is not an input flag, it's a "local" flag with the c_lflag
	// ISIG same with ICANON, it's not c_lflag
	// use it to turn off Ctrl-C and Ctrl-Z
	// IEXTEN turn off Ctrl+V (Although it begin I but it not input flag : c_iflag)
	// by using the IEXTEN flag ( Ctrl-O with macOS)
	

	/*
	 * ECHO turn on display
	 * ICANON turn on canonical mode
	 * IEXTEN turn on Ctrl-V
	 * ISIG turn on Ctrl-C Ctrl-Z */
		
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG );
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME]= 1; 
	/*
	 * c_lflag -> local flags
	 * c_iflag -> input flags
	 * c_oflag -> ouput flags
	 * c_cflag -> control flags
	 *
	 * meanwhile:
	 * ECHO is a bitflag
	 * 00000000000000000000000000001000
	 * We use the bitwise-NOT operator(~) on this value to get
	 * 11111111111111111111111111110111	
	 *
	 * */

	// turn off all ouput processing
	// OPOST: Ouputflag, Post-Processing of output

	// passing the modified struct to tcsetattr
	// to write the new terminal attributes back out
	// TCSAFLUSH argument specifies when to apply the change
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

// function for low-level keypress reading, 
// function for mapping keypresses to editor operations
int editorReadKey(){
	int nread;
	char c;
	while((nread = read(STDIN_FILENO, &c, 1)) != 1){
		if(nread == -1 && errno != EAGAIN) die("read");
	}

	// read arrow key
	if(c == '\x1b'){
		// make the seq buffer 3 bytes long because we will
		// handling longer escape sequences in the future.
		char seq[3];
		if(read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
		if(read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
		if(seq[0] == '['){
			if(seq[1] >= '0' && seq[1] <= '9'){
				if(read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
				if(seq[2] == '~'){
	
					switch(seq[1]){
						case '1': return HOME_KEY;
						case '3': return DEL_KEY;
						case '4': return END_KEY;
						case '5': return PAGE_UP;
						case '6': return PAGE_DOWN;
						case '7': return HOME_KEY;
						case '8': return END_KEY;
					}
				}
			}
			else{
				switch (seq[1]) {
					case 'A': return ARROW_UP;
					case 'B': return ARROW_DOWN;
					case 'C': return ARROW_RIGHT;
					case 'D': return ARROW_LEFT;
					case 'H': return HOME_KEY;
					case 'F': return END_KEY;
				}
			}
		}
		else if(seq[0] == '0'){
			switch(seq[1]){
				case 'H': return HOME_KEY;
				case 'F': return END_KEY;
			}
		}
		return '\x1b';
	}
	else{
		return c;
	}
}
// get cursor position
int getCursorPosition(int *rows, int *cols){
	char buf[32];
	unsigned int i = 0;

	if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;
	
	printf("\r\n");
	char c;
	
	while(i < sizeof(buf)){
		// get cursor position
		// terminal would interpret when we want to print '\x1b'
		// So we skip the first character in buf by passing &buf[1] to printf()
		if(read(STDOUT_FILENO, &c, 1) != 1){
			break;
		}
		if(buf[i] == 'R') break;
		i++;
	}
	if(buf[0] != '\x1b' || buf[1] != '[') return -1;
	// sscanf comes from stdio.h
	if(sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;
	//editorReadKey();
	return 0;
}
int getWindowSize(int *rows, int *cols){
	// all of this comfrom sys/ioctl.h
	struct winsize ws;

	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col==0){
		// C command moves the cursor to the right
		// B command moves the cursor down
		// use 999 large value to ensure that the cursor reaches the right and bottom edges of the screen
		if(write(STDOUT_FILENO, "\x1b[999C\x1b[999B",12)!=12) return -1;
	//	editorReadKey();
	//	return -1;
		
		// get cursor position
		return getCursorPosition(rows, cols);
	}
	else{
		*cols=ws.ws_col;
		*rows=ws.ws_row;
		return 0;
	}
}
/*** syntax highlighting ***/

// takes a character and return true
int is_separator(int c){
	// strchr -> string.h
	// first occurence of a character in a string and returns a pointer
	// to the matching character in the stirng. if the string doesn't
	// contain the character, strchr() return NULL
	return isspace(c) || c == '\0' || strchr(",.()+-/*=%<>[];", c) != NULL;
	
}

void editorUpdateSyntax(erow *row){
	row->hl = realloc(row->hl, row->size); // allocate memory
	memset(row->hl, HL_NORMAL, row->size); // come from string.h
	// user memset to set all characters to HL_NORMAL by default
	if (E.syntax == NULL) return;
	char **keywords = E.syntax->keywords;
	char *scs = E.syntax->singleline_comment_start;
	char *mcs = E.syntax->multiline_comment_start;
  	char *mce = E.syntax->multiline_comment_end;
	int scs_len = scs?strlen(scs):0;
	int mcs_len = mcs ? strlen(mcs) : 0;
  	int mce_len = mce ? strlen(mce) : 0;

	int prev_sep = 1;
	int in_string=0;
	int in_comment = (row->idx > 0 && E.row[row->idx -1].hl_open_comment);
	// setting digits to HL_NUMER
	int i=0;
	while(i < row->rsize){
		char c = row->render[i];
		unsigned char prev_hl = (i > 0) ? row->hl[i-1]: HL_NORMAL;

		if(scs_len && !in_string && !in_comment){
			if(!strncmp(&row->render[i], scs, scs_len)){
				memset(&row->hl[i], HL_COMMENT, row->rsize - i);
				break;
			}
		}


		if (mcs_len && mce_len && !in_string) {
		if (in_comment) {
			row->hl[i] = HL_MLCOMMENT;
			if (!strncmp(&row->render[i], mce, mce_len)) {
			memset(&row->hl[i], HL_MLCOMMENT, mce_len);
			i += mce_len;
			in_comment = 0;
			prev_sep = 1;
			continue;
			} else {
			i++;
			continue;
			}
		} else if (!strncmp(&row->render[i], mcs, mcs_len)) {
			memset(&row->hl[i], HL_MLCOMMENT, mcs_len);
			i += mcs_len;
			in_comment = 1;
			continue;
		}
    }

		if (E.syntax->flags & HL_HIGHLIGHT_STRINGS) {
			if (in_string) {
				row->hl[i] = HL_STRING;
				if (c == '\\' && i + 1 < row->rsize){
					row->hl[i+1] = HL_STRING;
					i+=2;
					continue;
				}
				if(c == in_string) in_string = 0;
				i++;
				prev_sep = 1;
				continue;
			} else {
				if (c == '"' || c == '\'') {
				in_string = c;
				row->hl[i] = HL_STRING;
				i++;
				continue;
				}
			}
		}

	if(E.syntax->flags & HL_HIGHLIGHT_NUMBERS){
		if( (isdigit(c) && (prev_sep || prev_hl == HL_NUMBER)) ||
		(c == '.' && prev_hl == HL_NUMBER) ){
			row->hl[i] = HL_NUMBER;
			i++;
			prev_sep=0;
			continue;
		}
	}

	if (prev_sep) {
		int j;
		for (j = 0; keywords[j]; j++) {
			int klen = strlen(keywords[j]);
			int kw2 = keywords[j][klen - 1] == '|';
			if (kw2) klen--;
			if (!strncmp(&row->render[i], keywords[j], klen) &&
				is_separator(row->render[i + klen])) {
			memset(&row->hl[i], kw2 ? HL_KEYWORD2 : HL_KEYWORD1, klen);
			i += klen;
			break;
			}
		}
		if (keywords[j] != NULL) {
			prev_sep = 0;
			continue;
		}
    }
	prev_sep = is_separator(c);
	i++;
	}
	int changed = (row->hl_open_comment != in_comment);
	row->hl_open_comment = in_comment;
	if (changed && row->idx + 1 < E.numrows)
    editorUpdateSyntax(&E.row[row->idx + 1]);
}
int editorSyntaxToColor(int hl){
	switch(hl){
		// return ANSI code
		// numbers: foreground red
		// anything else that might slip: foreground white

		case HL_COMMENT:
		case HL_MLCOMMENT: return 36;
		case HL_KEYWORD1: return 33; // yellow
		case HL_KEYWORD2: return 32; // green
		case HL_STRING: return 35;
		case HL_NUMBER: return 31;
		case HL_MATCH: return 34;
		default: return 37;
	}
}

// function that tries to match the current filename to
// one of the filematch in HLDB
void editorSelectSyntaxHighlight(){
	E.syntax = NULL;
	if(E.filename == NULL) return;
	char *ext = strrchr(E.filename, '.');
	for(unsigned int j = 0; j < HLDB_ENTRIES; j++){
		struct editorSyntax *s = &HLDB[j];
		unsigned int i = 0;
		while(s->filematch[i]){
			int is_ext = (s->filematch[i][0] == '.');
			if((is_ext && ext && !strcmp(ext, s->filematch[i]))||
				(!is_ext && strstr(E.filename, s->filematch[i]))){
				E.syntax = s;

				int filerow;
				for (filerow = 0;filerow < E.numrows; filerow++){
					editorUpdateSyntax(&E.row[filerow]);
				}
				return;
			}
			i++;
		}
	}
}

/*** row operations ***/

int editorRowCxToRx(erow *row, int cx){
	int rx = 0;
	int j;
	for(j = 0; j < cx; j++){
		if(row->chars[j] == '\t')
			rx += (KILO_TAB_STOP -1) - (rx % KILO_TAB_STOP);
		rx++;
	}
	return rx;
}

int editorRowRxToCx(erow *row, int rx){
	int cur_rx = 0;
	int cx;
	for(cx = 0; cx < row->size; cx++){
		if(row->chars[cx] == '\t')
			cur_rx += (KILO_TAB_STOP - 1) - (cur_rx % KILO_TAB_STOP);
		cur_rx++;
		// stop when cur_rx hits the given rx value
		if(cur_rx > rx ) return cx;
	}
	return cx;
}

void editorUpdateRow(erow *row){
	//add code
	int tabs = 0;
	int j;
	for (j = 0; j < row->size; j++)
		if (row->chars[j] == '\t') tabs++;
	free(row->render);
	row->render = malloc(row->size + tabs*(KILO_TAB_STOP - 1) + 1);
	row->render = malloc(row->size + tabs*7 + 1);
	int idx = 0;
	for (j = 0; j < row->size; j++) {
		if (row->chars[j] == '\t') {
		row->render[idx++] = ' ';
		while (idx % KILO_TAB_STOP != 0) row->render[idx++] = ' ';
		} else {
		row->render[idx++] = row->chars[j];
		}
	}
	row->render[idx] = '\0';
	row->rsize = idx;

	// already has the job of updating the render array whenever the 
	// text of the row changes, so it makes sense that where we want
	// to update the hl array. So after updating render ->call editorUpdateSysntax()

	editorUpdateSyntax(row);
}

void editorInsertRow(int at, char *s, size_t len){
	if(at < 0 || at > E.numrows) return;

	E.row = realloc(E.row, sizeof(erow) * (E.numrows +1));
	memmove(&E.row[at+1], &E.row[at], sizeof(erow)*(E.numrows-at));
	for(int j = at + 1; j <= E.numrows; j++) E.row[j].idx++;
	E.row[at].idx = at;
	// int at = E.numrows;
	E.row[at].size = len;
	E.row[at].chars = malloc(len+1);
	memcpy(E.row[at].chars, s, len);
	E.row[at].chars[len] = '\0';

	// redering row
	E.row[at].rsize =0 ;
	E.row[at].render = NULL;
	E.row[at].hl = NULL;
	E.row[at].hl_open_comment = 0;
	//

	editorUpdateRow(&E.row[at]);
	E.numrows++;
	E.dirty++;
}

void editorFreeRow(erow *row){
	free(row->render);
	free(row->chars);
	free(row->hl); 
}
void editorDelRow(int at){
	if (at < 0  || at > E.numrows) return;
	editorFreeRow(&E.row[at]);
	memmove(&E.row[at], &E.row[at+1], sizeof(erow) * (E.numrows - at - 1));
	for(int j = at; j < E.numrows -1; j++) E.row[j].idx--;
	E.numrows--;
	E.dirty++;
}

void editorRowInsertChar(erow *row, int at, int c){
	if(at < 0 || at > row->size) at = row->size;
	row->chars = realloc(row->chars, row->size + 2);
	// like memcpy but is safe to use when the source and
	// destination arrays overlap
	memmove(&row->chars[at + 1], &row->chars[at], row->size -at + 1);
	row->size++;
	row->chars[at] = c;
	editorUpdateRow(row);
	E.dirty++;
}

void editorRowAppendString(erow *row, char *s, size_t len){
	row->chars = realloc(row->chars, row->size + len + 1);
	memcpy(&row->chars[row->size], s, len);
	row->size += len;
	row->chars[row->size] = '\0';
	editorUpdateRow(row);
	E.dirty++;
}

void editorRowDelChar(erow *row, int at){
	if(at < 0 || at >= row->size) return;
	memmove(&row->chars[at], &row->chars[at+1], row->size -at);
	row->size--;
	editorUpdateRow(row);
	E.dirty++;
}

/*** Editor operations ***/
void editorInsertChar(int c){
	if(E.cy == E.numrows){
		editorInsertRow(E.numrows,"", 0);
	}
	editorRowInsertChar(&E.row[E.cy], E.cx, c);
	E.cx++;
}
void editorInsertNewLine(){
	if(E.cx == 0) {
		editorInsertRow(E.cy,"",0);
	}
	else{
		erow *row = &E.row[E.cy];
		editorInsertRow(E.cy + 1, &row->chars[E.cx], row->size - E.cx);
		row = &E.row[E.cy];
		row->size = E.cx;
		row->chars[row->size] = '\0';
		editorUpdateRow(row);
	}
	E.cy++;
	E.cx = 0;
}
void editorDelChar(){
	if(E.cy == E.numrows) return;
	if(E.cx == 0 && E.cy ==0 ) return; 
	erow *row = &E.row[E.cy];
	if(E.cx > 0){
		editorRowDelChar(row, E.cx - 1);
		E.cx--;
	}
	else{
		E.cx = E.row[E.cy - 1].size;
		editorRowAppendString(&E.row[E.cy - 1], row->chars, row->size);
		editorDelRow(E.cy);
		E.cy--;
	}
}
/*** File I/O ***/
char *editorRowsToString(int *buflen){
	int totlen = 0;
	int j;
	for(j = 0; j < E.numrows; j++){
		totlen += E.row[j].size + 1;}
	*buflen = totlen;
	char *buf = malloc(totlen);
	char *p = buf;
	for(j = 0; j < E.numrows; j++){
		memcpy(p, E.row[j].chars, E.row[j].size);
		p+=E.row[j].size;
		*p = '\n';
		p++;
	}
	return buf;
	
}

void editorOpen(char *filename){
	free(E.filename);
	E.filename = strdup(filename);
	editorSelectSyntaxHighlight();
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) die("open");

		
		// editorAppendRow(line, linelen);
		char *line = NULL;
		size_t linecap = 0;
		ssize_t linelen;
		linelen = getline(&line, &linecap, fp);
		while((linelen = getline(&line, &linecap, fp)) != -1){
			while(linelen > 0 && (line[linelen-1] == '\n' || 
			line[linelen-1] == '\r'))
				linelen--;
			editorInsertRow(E.numrows,line, linelen);
		}
	free(line);
	fclose(fp);
	E.dirty=0;
}

void editorSave(){
	if(E.filename == NULL){
		E.filename = editorPrompt("Save as: %s (ESC to cancel)", NULL);
		if(E.filename == NULL){
			editorSetStatusMessage("Save aborted");
			return;
		}
		/*
		at this point, when user open C file in the editor
		you should see numbers getting highlighted and u should see
		C in the status bar where we display file type.
		*/
		editorSelectSyntaxHighlight();
	}
	int len;
	char *buf = editorRowsToString(&len);
	int fd = open(E.filename, O_RDWR | O_CREAT, 0644);
	if(fd != -1){
		if(ftruncate(fd, len) != -1){
			if(write(fd, buf, len) == len){
				close(fd);
				free(buf);
				E.dirty=0;
				editorSetStatusMessage("%d bytes written to disk", len);
				return;
			}
		}
		close(fd);
	}
	free(buf);
	editorSetStatusMessage("Can't save! I/O error: %s", strerror(errno));
	// ftruncate(fd, len);
	// write(fd, buf, len);
	// close(fd);
	// free(buf);
}

/*** find ***/
void editorFindCallback(char *query, int key){
	static int last_match = -1;
	
	static int direction = 1;
	// \r (Enter)
	// \x1b (Escape)

	// restore syntax highlighting after search
	static int saved_hl_line;
	static char *saved_hl = NULL;
	if(saved_hl){
		memcpy(E.row[saved_hl_line].hl, saved_hl, E.row[saved_hl_line].size);
		free(saved_hl);
		saved_hl=NULL;
	}
	//

	if(key == '\r' || key == '\x1b'){
		last_match = -1;
		direction = 1;
		return;
	}
	else if(key == ARROW_RIGHT || key == ARROW_DOWN){
		direction = 1;
	}
	else if(key == ARROW_LEFT || key == ARROW_UP){
		direction = -1;
	}
	else{
		last_match=-1;
		direction=1;
	}

	if(last_match == -1) direction =1;
	int current = last_match;
	int i;
	for(i = 0; i < E.numrows; i++){
		current += direction;
		if(current == -1) current = E.numrows -1;
		else if(current == E.numrows) current =0;
		erow * row = &E.row[current];
		char *match = strstr(row->render, query);
		if(match){
			last_match = current;
			E.cy = current;
			E.cx = editorRowRxToCx(row, match - row->render);
			E.rowoff = E.numrows;
			saved_hl_line = current;
			saved_hl = malloc(row->rsize);
			memcpy(saved_hl, row->hl, row->rsize);
			memset(&row->hl[match-row->render], HL_MATCH, strlen(query));
			break;
		}
	}
}
void editorFind(){
	// if User pressed Escape to cancel input prompt
	// then editorPrompt return null
	
	int save_cx = E.cx;
	int save_cy = E.cy;
	int save_coloff = E.coloff;
	int save_rowoff = E.rowoff;
	char *query = editorPrompt("Search: %s (Use ESC/Arrows/Enter)",editorFindCallback);
	// if query is NULL that means user pressed Esvcape so 
	// in that case we restore the values we saved
	if(query)
		free(query);
	else{
		E.cx = save_cx;
		E.cy = save_cy;
		E.coloff = save_coloff;
		E.rowoff = save_rowoff;
	}
}

/*** append buffer***/
struct abuf{
	char *b;
	int len;

};
#define ABUF_INIT {NULL, 0} // default constructor

void abAppend(struct abuf *ab, const char *s, int len){
	// ensure that we will have enough memory to hold new string
	// we ask realloc to give us a block memory of the size current string plus the size of string we are appending.
	char *nw=(char*) realloc(ab->b, ab->len + len);
	if(nw == NULL) return;
	memcpy(&nw[ab->len], s, len);
	ab->b = nw;
	ab->len += len;
}
// destructor
void abFree(struct abuf *ab){
	free(ab->b);
}

/*** INPUT ***/

char *editorPrompt(char *prompt, void (*callback)(char *, int)){
	size_t bufsize = 128;
	char *buf = malloc(bufsize);
	size_t buflen = 0;
	buf[0] = '\0';
	while(1){
		editorSetStatusMessage(prompt, buf);
		editorRefreshScreen();

		int c = editorReadKey();
		// allow user to press Escape to cancel the input prompt
		if(c == DEL_KEY || c == CTRL_KEY('h') || c == BACKSPACE){
			if(buflen != 0) buf[--buflen] = '\0';
		}
		else if(c == '\x1b'){
			editorSetStatusMessage("");
			if(callback) callback(buf, c);
			free(buf);
			return NULL;
		}
		else if(c == '\r'){
			if(buflen != 0){
				editorSetStatusMessage("");
				if(callback) callback(buf, c);
				return buf;
			}
		}
		else if(!iscntrl(c) && c < 128){
			if(buflen == bufsize-1){
				bufsize*=2;
				buf = realloc(buf, bufsize);
			}
			buf[buflen++] = c;
			buf[buflen] = '\0';
		}
		if(callback) callback(buf, c);
	}
}

// move cursor

void editorMoveCursor(int key){
	erow *row = (E.cy >= E.numrows) ? NULL : &E.row[E.cy];

	switch(key){
		case ARROW_LEFT:
			if(E.cx != 0){
				E.cx--;
			}
			else if(E.cy > 0){
				E.cy--;
				E.cx = E.row[E.cy].size;
			}
			
		break;
		case ARROW_RIGHT:
			if(row && E.cx < row->size){
			// if(E.cx != E.screencols -1){
				E.cx++;
			// }
			}
			else if(row && E.cx == row->size){
				E.cy++;
				E.cx=0;
			}
			
		break;
		case ARROW_UP:
			if(E.cy != 0) {
				E.cy--;
			}
			
		break;
		case ARROW_DOWN:
			if(E.cy < E.numrows){
				E.cy++;
			}
			
		break;
	}

	row = (E.cy >= E.numrows) ? NULL : &E.row[E.cy];
	int rowlen = row ? row->size : 0;
	if(E.cx > rowlen){
		E.cx = rowlen;
	}
}
//

void editorProcessKeypress(){
	static int quit_times = KILO_QUIT_TIMES;
	int c = editorReadKey();
	switch(c){
		case '\r':
			/* TODO */
			editorInsertNewLine();
			break;
		
		case CTRL_KEY('q'):
			// now we have two exit points we want to
			// clear the screen at die() or Ctrl+Q
			if(E.dirty && quit_times > 0){
				editorSetStatusMessage("WARNING!!! File has unsaved changes. "
          "Press Ctrl-Q %d more times to quit.", quit_times);
			quit_times--;
			return;
			}
			write(STDOUT_FILENO, "\x1b[2J", 4);
			write(STDOUT_FILENO, "\x1b[H", 3);
			exit(0);
			break;
		case CTRL_KEY('s'):
			editorSave();
			break;
		case HOME_KEY:
		E.cx = 0;
		break;
		case END_KEY:
		if(E.cy < E.numrows)
			E.cx = E.row[E.cy].size;
		break;
		
		case CTRL_KEY('f'):
			editorFind();
			break;

		case BACKSPACE:
		case CTRL_KEY('h'):
		case DEL_KEY:
			/* TODO */
			if(c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
			editorDelChar();
			break;

		case PAGE_UP:
		case PAGE_DOWN:

	// we create a code block with that pair of braces so that
	// we're allowed to declare the times variable
	// we simulate the user pressing the up arrow or down
	// arrow keys enough times to move the top or bottom of the screen
	{
		if(c == PAGE_UP){
			E.cy = E.rowoff;
		}
		else if(c == PAGE_DOWN){
			E.cy = E.rowoff + E.screenrows -1;
			if(E.cy > E.numrows) E.cy = E.numrows;
		}
		int times=E.screenrows;
		while(times--)
			editorMoveCursor(c == PAGE_UP?ARROW_UP:ARROW_DOWN);
	}
	break;

		case ARROW_UP:
		case ARROW_LEFT:
		case ARROW_RIGHT:
		case ARROW_DOWN:
			editorMoveCursor(c);
		break;
	case CTRL_KEY('l'):
	case '\x1b':
		break;
	default:
		editorInsertChar(c);
		break;
	}
	quit_times = KILO_QUIT_TIMES;
}

/*** OUTPUT ***/

void editorScroll(){
	E.rx = 0;
	if(E.cy < E.numrows){
		E.rx = editorRowCxToRx(&E.row[E.cy], E.cx);
	}
	if(E.cy < E.rowoff){
		E.rowoff = E.cy;
	}
	if(E.cy >= E.rowoff + E.screenrows){
		E.rowoff = E.cy - E.screenrows +1 ;
	}
	if (E.rx < E.coloff){
		E.coloff = E.rx;
	}
	if(E.rx >= E.coloff + E.screencols){
		E.coloff = E.rx - E.screencols + 1;
	}
}

// Time to start drawing with '~'
void editorDrawRows(struct abuf *ab){
	int y;
	for(y = 0; y < E.screenrows; y++){
		int filerow = y + E.rowoff;
		if(filerow >= E.numrows){
			//Welcome message **/
			if(y >= E.numrows){
				if(E.numrows == 0 &&  y == E.screenrows/3){
					char welcome[80];
					int welcomeLen=snprintf(welcome, sizeof(welcome), "Kilo editor -- version %s ", KILO_VERSION);
					if(welcomeLen > E.screencols) welcomeLen=E.screencols;
					int padding = (E.screencols - welcomeLen) /2;
					if(padding) {
						abAppend(ab, "~", 1);
						padding--;
					}
					while(padding--) abAppend(ab, " ", 1);
					abAppend(ab, welcome, welcomeLen);
				}
				else{
					abAppend(ab, "~", 1);
				}
			}
		}else{
			int len = E.row[filerow].rsize - E.coloff;
			if(len < 0) len = 0;
			if(len > E.screencols) len = E.screencols;
			char *c = &E.row[filerow].render[E.coloff];
			unsigned char *hl = &E.row[filerow].hl[E.coloff];
			int current_color = -1;
			int j;
			for(j = 0; j < len; j++){
				// use iscntrl to check if the current character is
				// a control character so we translate it into a printable
				// character by adding its values to '@' or using '?'
				if(iscntrl(c[j])){ 
					char sym = (c[j] <= 26) ? '@' + c[j] : '?';
					// <esc>[7m switch to inverted colors before
					// printing the translated symbol

					// use <esc>[m to turn off inverted colors again
					abAppend(ab, "\x1b[7m", 4);
					abAppend(ab, &sym, 1);
					abAppend(ab, "\x1b[m", 3);
					if(current_color != -1){
						char buf[16];
						int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", current_color);
						abAppend(ab, buf, clen);
					}
				}
				else if(hl[j] == HL_NORMAL){
					if(current_color != -1){
						abAppend(ab, "\x1b[39m", 5);
						current_color=-1;
					}
					abAppend(ab,&c[j], 1);

				}
				else{
					int color = editorSyntaxToColor(hl[j]);
					if(color != current_color){
						current_color = color;
						char buf[16];
						int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", color);
						abAppend(ab, buf, clen);
					}
					abAppend(ab, &c[j],1);
				}
			}
			abAppend(ab,"\x1b[39m",5);
		}
		// last line
		abAppend(ab, "\x1b[K", 3);
		// K commnad (erase in line )
		// erases part of the current line. 
		// Its argument is analogous to the J commnad's argument
		// 2 erases the whole line,
		// 1 erases the part of line the the left of the cursor
		// 0 erases the part of the line to the line of the cursor (default argument);

		// if(y < E.screenrows - 1){
			abAppend(ab, "\r\n", 2);
		// }
	}
}

void editorDrawStatusBar(struct abuf *ab){
	abAppend(ab, "\x1b[7m", 4);
	char status[80], rstatus[80];
	int len = snprintf(status, sizeof(status), "%.20s - %d lines %s",
	E.filename?E.filename:"[NO NAME]", E.numrows,
	E.dirty? "(modified) ":"");
	int rlen = snprintf(rstatus, sizeof(rstatus), "%s | %d/%d",
	E.syntax? E.syntax->filetype:"no file type" ,E.cy + 1, E.numrows);
	if(len > E.screencols) len = E.screencols;
	abAppend(ab, status, len);
	while(len < E.screencols){
		if(E.screencols - len == rlen){
			abAppend(ab, rstatus, rlen);
			break;
		}
		else{
			abAppend(ab, " ", 1);	
			len++;
		}
	}
	abAppend(ab, "\x1b[m", 3);
	abAppend(ab, "\r\n", 2);
}

void editorDrawMessageBar(struct abuf *ab){
	abAppend(ab, "\x1b[K", 3);
	int msglen= strlen(E.statusmsg);
	if(msglen > E.screencols) msglen = E.screencols;
	if(msglen && time(NULL) - E.statusmsg_time < 5)
		abAppend(ab, E.statusmsg, msglen); 
}
void editorRefreshScreen(){
	// append buffer
	editorScroll();
	struct abuf ab = ABUF_INIT;
	
	//hide cursor when repainting
	// h and l commands (set mode, reset mode) are used to turn
	// on and turn off various terminal features or "modes"

	// write and STDOUT_FILENO come from unistd.h
	// the first byte is \x1b, which is the escape character
	// Using J command (Erase in display) to clear the screen
	abAppend(&ab, "\x1b[?25l", 6); // hide cursor
	//abAppend(&ab, "\x1b[2J",4);// clear line one time
	// Reposition the cursor
	// 3 bytes long
	// Using H command (Curso position)
	abAppend(&ab, "\x1b[H",3);
	// drawing
	editorDrawRows(&ab);
	editorDrawStatusBar(&ab);
	editorDrawMessageBar(&ab);
	// editorDrawRows() will handle drwaing each row of the buffer
	// of text being edited.
	
	// move the cursor
	char buf[32];
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy-E.rowoff) + 1 ,
	(E.rx - E.coloff) + 1);
	abAppend(&ab, buf, strlen(buf));
	//


	abAppend(&ab, "\x1b[H", 3);
	abAppend(&ab, "\x1b[?25h", 6);
	write(STDOUT_FILENO, ab.b, ab.len);
	abFree(&ab);
}

void editorSetStatusMessage(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(E.statusmsg, sizeof(E.statusmsg), fmt, ap);
	va_end(ap);
	E.statusmsg_time = time(NULL);
}

/***INIT***/
void initEditor(){
	// cursor start at top-left
	E.cx=0;
	E.cy=0;
	// erow stands for "edit row"
	E.numrows = 0;
	E.coloff = 0;
	E.rx=0;
	E.row=NULL;
	E.rowoff = 0;
	E.dirty=0;
	E.filename = NULL;
	E.statusmsg[0] = '\0';
	E.statusmsg_time = 0;
	E.syntax = NULL;
	if(getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
	E.screenrows -=2;
}
int main(int argc, char *argv[]){
	// now u can press Ctrl-C to start a fresh line
	// then type reset will make ur terminal back to normal
	enableRawMode();

	initEditor(); // will be initialize all the fields int the E struct.
	if(argc >= 2){
		editorOpen(argv[1]);
	}

	editorSetStatusMessage("HELP: CTRL_S = save | CTRL-Q = quit | CTRL-F = find");
	//char c;
	while(1){
		editorRefreshScreen();
		editorProcessKeypress();	
	//	char c = '\0';
		// we won't treat EAGAIN as an error
	//	if(read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
		// Display keypresses
	//	
	//	if(iscntrl(c)){
	//		printf("%d\r\n", c);
	//	}
	//	else{
	//		printf("%d('%c')\r\n", c, c); // %d tells it to format the byte
	//	}
	//	if(c == CTRL_KEY('q')) break;
	}
	return 0;
}
