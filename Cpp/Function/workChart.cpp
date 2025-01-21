#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h> // sleep()
using namespace std;

char array[50][101];
bool f = false;
// Create simple tab on month
void drawLine()
{
    for (int i = 0; i < 20; i++)
    {
        cout << '_';
    }
    cout << endl;
}
void createTab()
{
    int i = 0;
    int j = 0;
    char nameTab[] = {'D', 'O', ' ', 'M', 'O', 'R', 'E', ' ', 'A', 'N', 'D', ' ', 'G', 'E', 'T', ' ', 'B', 'E', 'T', 'T', 'E', 'R'};
    int sizeName = sizeof(nameTab) / sizeof(nameTab[0]);
    for (int k = 0; k < 101; k++)
    {
        if (k > 38 && k - 39 < sizeName)
        {
            array[j][k] = nameTab[k - 39];
        }
        else
            array[j][k] = ' ';
    }
    // set up array
    for (;; i++)
    {
        if (j == 50)
            break;
        if (i == 101)
        {
            i = -1;
            j++;
            continue;
        }
        if (j == 0)
        {
            continue;
        }
        if (j == 1 || j == 49)
        {
            array[j][i] = '_';
            continue;
        }
        if ((i == 0 || i == 100 || i == 51) && j != 0)
        {
            array[j][i] = '|';
        }

        else
        {
            array[j][i] = ' ';
        }
    }
}
// reset your effort -> beginning
void resetTab()
{
    ofstream txtFile("work_chart.txt", ios::out);
    if (txtFile.is_open())
    {
        for (const auto &x : array)
        {
            for (char y : x)
            {
                txtFile << y;
            }
            txtFile << endl;
        }
    }
    txtFile.close();
}
// read file txt
void readFile()
{
    ifstream txtFile("work_chart.txt");
    string readLine;
    int j = 0;
    while (getline(txtFile, readLine))
    {
        for (int i = 0; i < readLine.size(); i++)
        {
            array[j][i] = readLine[i];
        }
        j++;
    }
}
// show your effort on month
void viewTab()
{
    // read file
    ifstream txtFile("work_chart.txt");
    string readLine;
    int index = 0;
    int i = 0;
    int j = 0;
    if (txtFile.is_open())
    {
        while (getline(txtFile, readLine))
        {

            for (auto c : readLine)
            {
                cout << c;
            }
            cout << endl;
        }
    }
    txtFile.close();
}

// stop watch
void stopWatch()
{
    int hour = 0, min = 0, sec = 0;
    while (true)
    {
        sleep(1);
        sec++;
        if (sec > 59)
        {
            min++;
            sec = 0;
        }
        if (min > 59)
        {
            hour++;
            min = 0;
            sec = 0;
        }
    }
    cout << hour << " : " << min << " : " << sec << endl;
}
// append new to file
void updateTab()
{
    ifstream txtFile("work_chart.txt");
    int dec, line = 1, index = 0;
    string readLine;
    string task;
    string deadline = "!Chưa Xong";
    string done = "!Da hoan Thanh";
    bool flag = false;
    drawLine();
    cout << "1. Up" << endl;
    cout << "2. View" << endl;
    cout << "3. Reset" << endl;
    cout << "4. Done" << endl;
    cout << "0. Pause" << endl;
    drawLine();
    cin >> dec;
    switch (dec)
    {
    case 1:
        cin.ignore();
        getline(cin, task);
        while (array[line][5] != ' ')
        {
            line++;
        }
        if (line - 1 < 10)
        {
            array[line][5] = '0';
            array[line][6] = char('0' + line - 1);
            array[line][7] = '.';
        }
        else
        {
            array[line][5] = '0' + line / 10;
            array[line][6] = '0' + line % 10;
            array[line][7] = '.';
        }
        for (int i = 0; i < task.size(); i++)
        {
            array[line][i + 10] = task[i];
        }
        for (int i = 56; i < 67; i++)
        {
            array[line][i] = deadline[i - 56];
        }

        resetTab();
        break;
    case 2:
        viewTab();
        break;
    case 3:
        createTab();
        resetTab();
        break;
    case 4:
        cin >> index;
        index += 1;
        if (array[index][56] != ' ')
        {
            for (int i = 56; i < 70; i++)
            {
                array[index][i] = done[i - 56];
            }
            resetTab();
        }

        break;
    case 0:
    default:
        f = true;
        break;
    }
    if (txtFile.is_open())
        txtFile.close();
}
int main()
{
    // 0: false | not good
    // 1: true  | good
    // press crtl C to escape program
    // createTab();
    // resetTab();
    stopWatch();
    readFile();
    viewTab();
    while (!f)
    {
        updateTab();
    }
    // u don't need worry about save, when u turn off program it will imediately save at file wort_chart.txt
    return 0;
}