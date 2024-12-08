#define size_kiddi_short 35328 // File size in byte (Kiddi_Short_Image.exe)
#define password_lenght 100    // Maximum password lenght (pa_lenght - 3)
#define array_size 10000   // Speed control Array size (safe zone speed)
#define skey 1654   // secure compilation 
#include <conio.h>
#include <Windows.h>
#include "kiddi1.h"
using namespace std;
int main(int argc, char* argv[])
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    if (argc > 3)
    {
        SetConsoleTextAttribute(hc, 4);
        cerr << "Error... too many arguments entered. ";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    KIDDI* aman;
    aman = new KIDDI;
    bool ultra_secure = false, pass_cmd = false;
    string protect;
    SetConsoleTextAttribute(hc, 11);
    short i;
    if (argc == 1) // welcome condition on manual mode
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "\n\n** Important Instruction :- please don,t kill this Application. Manually close this Application **\n\n             *** I Am Also Kiddi 2.010 Short Image, Creator = Aman Taycon *** \n";
    }
    else if(argc == 2) {
        if (strcmp(argv[1], "-u") == 0)
        {
            ultra_secure = true;
        }
        else {
            protect = argv[1];
            pass_cmd = true;
            
        }
    }
    else {
        for ( i = 2; i > 0; i--)
        {
            if (strcmp(argv[i], "-u") == 0)
            {
                ultra_secure = true;
                break;
            }
        }
        if (i == 2) {
            protect = argv[1];
            pass_cmd = true;
        }
        else if (i == 1) {
            protect = argv[2];
            pass_cmd = true;
        }
        else {
            SetConsoleTextAttribute(hc, 4);
            std::cerr << " Some error...\n";
            SetConsoleTextAttribute(hc, 7);
            exit(1);
        }
    
    }
    if (!pass_cmd)
    {
        short temp3;
    repeat3:             // ---> repeat3 = password error looping
        char exit1[] = "exit";
        (protect).clear();
        SetConsoleTextAttribute(hc, 11);
        cout << "Enter Password " << endl << ")--->>";
        char temp_protect[password_lenght];
        for (i = 0, temp3 = 0; 1; i++)
        {
            temp_protect[i] = _getch();
            if (i < 5)
            {
                if (temp_protect[i] == exit1[i])
                {
                    temp3++;
                }
            }
            if (temp3 == 4)
            {
                SetConsoleTextAttribute(hc, 7);
                exit(0);
            }
            if (temp_protect[i] == 13 || (i == password_lenght - 2))
            {
                break;
            }
        }
        cout << endl;
        protect = temp_protect;
    }
    Sleep(1000);
    SetConsoleTextAttribute(hc, 11);
    i = (*aman).kiddi(argv[0], protect, ultra_secure);
    SetConsoleTextAttribute(hc, 7);
    if (i == 2) {
        Sleep(1000);
        SetConsoleTextAttribute(hc, 4);
        cerr << "Error... your password is wrong please enter correct password\n";
        if (!pass_cmd) {
            goto repeat3;
        }
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == 1) {
        SetConsoleTextAttribute(hc, 4);
        cerr << "Sorry your system not support portable mode or you directory error.. \n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -1)
    {
        SetConsoleTextAttribute(hc, 4);
        std::cerr << "Your directory error\n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    delete aman;
    return 0;
}