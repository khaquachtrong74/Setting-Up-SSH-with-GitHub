#!/bin/bash

# Create directories if they don't exist
mkdir -p Folder_File.s Folder_o  

# Move .s files into Folder_File.s folder
mv *.s Folder_File.s/ 2>/dev/null # 2>/dev/null  is mean alert error when no file move?

# Move .o files into Folder_o folder
mv *.o Folder_o/ 2>/dev/null

# Move all executable files (those without extensions and not directories) into Folder_o
find . -maxdepth 1 -type f ! -name "*.*" -exec mv {} Folder_o/ \; #excute imediately
#!/bin/bash
#when update, please run it on terminal "./organize_files.sh"