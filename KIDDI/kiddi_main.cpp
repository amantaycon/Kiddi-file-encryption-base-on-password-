#define size_kiddi_main 51200  // File size in byte (Kiddi_main.exe)
#define size_kiddi_short 35328 // File size in byte (Kiddi_Short_Image.exe)
#define password_lenght 100    // Maximum password lenght (pa_lenght - 3)
#define array_size 10000    // Speed control Array size (safe zone speed)
#define skey 1654   // secure compilation 
#include "Kiddi.h"
using namespace std;
int main(int argc, char* argv[])
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    if (argc > 9)
    {
        SetConsoleTextAttribute(hc, 4);
        cout << "Error... too many arguments entered \n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    KIDDI* aman;
    aman = new KIDDI;
    bool file_cmd, mode_cmd, pass_cmd = file_cmd = mode_cmd = false;
    string file_name, mode, protect;
    SetConsoleTextAttribute(hc, 11);
    /* black 0, blue 1, green 2, aqua 3, red 4, purple 5, yellow 6, white 7, gray 8, light blue 9,light green 10, light aqua 11, light red 12, light purple 13, light yellow 14, white bright 15
    */
    short i;
    {
        char command;
        for (i = argc - 1; i > 0; i--)
        {
            if ((argv[i][0] == '-') && (strlen(argv[i]) == 2))
            {
                command = argv[i][1];
                command = tolower(command);
                switch (command)
                {
                case 'v':
                    cout << "-----------------------------------------------\n";
                    cout << "  ... version --->>  2.010  \n";
                    cout << "-----------------------------------------------\n";
                    if (argc != 2) {
                        SetConsoleTextAttribute(hc, 4);
                        cout << "Syntax Error... \n";
                        SetConsoleTextAttribute(hc, 7);
                        exit(1);
                    }
                    SetConsoleTextAttribute(hc, 7);
                    exit(0);
                case 'c':
                    cout << "-----------------------------------------------\n";
                    cout << "    creator name = Aman Taycon\n";
                    cout << "-----------------------------------------------\n";
                    if (argc != 2) {
                        SetConsoleTextAttribute(hc, 4);
                        cout << "Syntax Error... \n";
                        SetConsoleTextAttribute(hc, 7);
                        exit(1);
                    }
                    SetConsoleTextAttribute(hc, 7);
                    exit(0);
                case 'h':
                    (*aman).logo();
                    (*aman).help();
                    if (argc != 2) {
                        SetConsoleTextAttribute(hc, 4);
                        cout << "Syntax Error... \n";
                        SetConsoleTextAttribute(hc, 7);
                        exit(1);
                    }
                    SetConsoleTextAttribute(hc, 7);
                    exit(0);
                case 'a':
                    (*aman).kiddi(argv[i + 1]);
                case 's':
                    story();
                    exit(0);
                case 'f':
                    (file_name) = argv[i + 1];
                    file_cmd = true;
                    break;
                case 'p':
                    (protect) = argv[i + 1];
                    pass_cmd = true;
                    break;
                case 'm':
                    (mode) = argv[i + 1];
                    mode_cmd = true;
                    break;
                default:
                    SetConsoleTextAttribute(hc, 4);
                    cout << "Syntax Error...\n  Type command -h for help ";
                    SetConsoleTextAttribute(hc, 7);
                    exit(1);
                }
            }
            else
            {
                continue;
            }
        }
    }
    if (argc == 1) // welcome condition on manual mode
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "\n\n  ------> ***Welcome to our program*** <------ \n ***this program very hardly encrypted any files on password base***" << endl;
        (*aman).logo();
    }
loop: // ---> loop = infinite looping
    if (!file_cmd)
    {
        SetConsoleTextAttribute(hc,11);
        cout << "Enter File Name\n";
    repeat1: // ---> repeat1 = file name error looping
        cout << ")--->>";
        cin.clear();
        SetConsoleTextAttribute(hc, 7);
        getline(cin, file_name);
        if (file_name == "")
        {
            goto repeat1;
        }
        else if (file_name == "exit")
        {
            SetConsoleTextAttribute(hc, 7);
            exit(0);
        }
        else if (i == -11) 
        {
            goto skip;
        }
    }
    if (!mode_cmd)
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "Enter Mode (0,1,2,3,4,5,6)\n";
    repeat2: // ---> repeat2 = mode error looping
        cout << ")--->>";
        SetConsoleTextAttribute(hc, 7);
        getline(cin, mode);
        if (mode == "")
        {
            goto repeat2;
        }
        else if (mode == "exit")
        {
            SetConsoleTextAttribute(hc, 7);
            exit(0);
        }
        else if (i == -11) 
        {
            goto skip;
        }
    }
    if (!pass_cmd)
    {
        short temp3;
    repeat3:             // ---> repeat3 = password error looping
        char exit1[] = "exit";
        (protect).clear();
        SetConsoleTextAttribute(hc, 11);
        cout << "Enter Password 'larger than 8 '" << endl << ")--->>";
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
        if (i < 8 || i >(password_lenght - 3))
        {
            SetConsoleTextAttribute(hc, 4);
            cerr << "error.. Your password out of range\n";
            goto repeat3;
        }
        if (mode == "0" || mode == "1" || mode == "3" || mode == "5" || mode == "6")
        {
            cout << "Confirm your password" << endl << ")--->>";
            for (i = 0; 1; i++)
            {
                temp3 = _getch();
                if (temp_protect[i] != temp3)
                {
                    SetConsoleTextAttribute(hc, 4);
                    cerr << "  **Error.. Mismatch password**" << endl;
                    goto repeat3;
                }
                if (temp3 == 13)
                {
                    break;
                }
            }
            cout << endl;
        }
        protect = temp_protect;
        if (i == -11) {
            goto skip;
        }
    }
    else if ((protect).length() < 8 || (protect).length() > 60)
    {
        SetConsoleTextAttribute(hc, 4);
        cerr << "error.. Your password out of range\n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
skip:
    if (mode == "0" || mode == "5" || mode == "6") {
        SetConsoleTextAttribute(hc, 4);
        cout << " Alert... Ultra secure mode is on. its very risky\n if you enter wrong password your file data will be corrupted\n";
    }
    Sleep(1000);
    SetConsoleTextAttribute(hc, 10);
    i = (*aman).kiddi(file_name, protect,stoi(mode), argv[0]);
    SetConsoleTextAttribute(hc, 7);
    if (i == 0)
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "  ---> Your file operation is successful done <--- \n";
    }
    if (i == 1)
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "  ---> Your file is successful Encrypted <--- \n";
    }
    if (i == 2)
    {
        SetConsoleTextAttribute(hc, 11);
        cout << "  ---> Your file is successful Decrypted <--- \n";
    }
    else if (i == -1) 
    {
        SetConsoleTextAttribute(hc, 4);
        cerr << " Error.. Your file " << file_name << " doesn't exist Enter correct file name\n";
        if (!file_cmd) {
            i = -11;
            goto repeat1;
        }
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -2) 
    {
        Sleep(1000);
        SetConsoleTextAttribute(hc, 4);
        cerr << "Error... your password is wrong please enter correct password\n";
        if (!pass_cmd) {
            i = -11;
            goto repeat3;
        }
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -3) 
    {
        SetConsoleTextAttribute(hc, 4);
        cerr << "error...\nEnter valid mode\n";
        if (!mode_cmd)
        {
            i = -11;
            goto repeat2;
        }
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -4)
    {
        SetConsoleTextAttribute(hc, 4);
        cerr << "Sorry your system not support portable mode or you directory error.. \n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -5)
    {
        SetConsoleTextAttribute(hc, 4);
        std::cerr << "Your directory error\n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    else if (i == -6)
    {
        SetConsoleTextAttribute(hc, 4);
        std::cerr << " Some error...\n";
        SetConsoleTextAttribute(hc, 7);
        exit(1);
    }
    if (argc == 1)
    {
        string lo;
        SetConsoleTextAttribute(hc, 11);
        cout << "If you want to others file open in this apllication(y/n)\n";
    repeat4: // ---> repeat4 = final input(y/n) looping
        cout << ")--->>";
        SetConsoleTextAttribute(hc, 7);
        getline(cin,lo);
        fflush(stdin);
        if (lo == "y")
        {
            i = 0;
            goto loop;
        }
        else if (lo == "exit")
        {
            return 0;
        }
        else if (lo == "n")
        {
            return 0;
        }
        else if (lo == "")
        {
            goto repeat4;
        }
        else
        {
            cout << "enter wrong character\n";
            goto repeat4;
        }
    }
    return 0;
}