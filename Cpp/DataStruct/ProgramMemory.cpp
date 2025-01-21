#include <iostream>
using namespace std;

void draw()
{
    int size = 20;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            // Drawing the code section at the top
            if (i < 5 && j < 15)
            {
                if (i == 0 || i == 4)
                    cout << "_";
                else if (j == 0 || j == 14)
                    cout << "|";
                else
                    cout << " ";
            }
            // Drawing the stack section in the middle
            else if (i >= 5 && i < 12 && j < 15)
            {
                if (i == 5 || i == 11)
                    cout << "_";
                else if (j == 0 || j == 14)
                    cout << "|";
                else
                    cout << " ";
            }
            // Drawing the heap section at the bottom
            else if (i >= 12 && j < 15)
            {
                if (i == 12 || i == 19)
                    cout << "_";
                else if (j == 0 || j == 14)
                    cout << "|";
                else
                    cout << " ";
            }
            // Filling empty space on the right side
            else
            {
                cout << " ";
            }
        }
        // add Labels
        if (i == 2)
            cout << " Heap Section";
        if (i == 8)
            cout << " Stack Section";
        if (i == 16)
            cout << " Code Section";

        cout << endl;
    }
}

int main()
{
    draw();
    return 0;
}
