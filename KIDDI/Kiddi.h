
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <String>
#ifndef size_kiddi_main
#define size_kiddi_main 0 // File size in byte (Kiddi_main.exe)
#endif
#ifndef size_kiddi_short
#define size_kiddi_short 0 // File size in byte (Kiddi_Short_Image.exe)
#endif
#ifndef array_size
#define array_size 10000 // Speed control Array size (safe zone speed)
#endif
#ifndef skey
#define skey 1654 // secure compilation key
#endif
class KIDDI
{
public:
    short kiddi(std::string, std::string, short, char *);
    void kiddi(char *);
    inline void logo()
    {
        std::cout << "----------------------------------------------------\n"
                  << "   _    _     _     _ _         _^___^_          ____\n"
                  << "  | | _( ) __| | __| (_)        ( o o )         /    ',_________\n"
                  << "  | |/ / |/ _' |/ _' | |        (_ = _)     ,-->| I am so smart \\ \n"
                  << "  |   <| | (_| | (_| | | ===>>  __|_|__  ---'   |and intelligent| \n"
                  << "  |_|\\_\\_|\\__,_|\\__,_|_|     __| I am  |__      ',______________|\n"
                  << "  ____   ___  _  ___        |  | kiddi |  |\n"
                  << " |___ \\ / _ \\/ |/ _ \\      /|\\ |_______| /|\\ \n"
                  << "   __) | | | | | | | | <-VERSION |   |\n"
                  << "  / __/| |_| | | |_| |          /|\\ /|\\ \n"
                  << " |____(_)___/|_|\\___/          '''''''''\n"
                  << "----------------------------------------------------- \n";
    };
    inline void help()
    {
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout.width(10);
        std::cout << "Command"
                  << "Description\n"
                  << std::endl;
        std::cout.width(10);
        std::cout << "  -a"
                  << " Aman Taycon special\n";
        std::cout.width(10);
        std::cout << "  -c"
                  << " Show creater name\n";
        std::cout.width(10);
        std::cout << "  -f"
                  << " Give me a file location(C:\\Users\\user_name\\video.mp4)\n";
        std::cout.width(10);
        std::cout << "  -h"
                  << " Help\n";
        std::cout.width(10);
        std::cout << "  -m"
                  << " Give me a mode(0,1,2,3,4,5,6)\n";
        std::cout.width(10);
        std::cout << "  -p"
                  << " Give me a password( Larger then 8 and maximum size 60)\n";
        std::cout.width(10);
        std::cout << "  -s"
                  << " Secret (about of kiddi)\n";
        std::cout.width(10);
        std::cout << "  -v"
                  << " Version \n\n";
        std::cout << "  mode \n\n  0 --> ultra secure mode encryption and decryption but its dengerous because if you enter wrong password you data again encrypted. this mode no check password error. \n\n  1 --> this mode your data encrypted very hard algorithm in password base if you use multiple password your deta will be even more secure.\n\n  2 --> this mode decrypted data file if your data encrypted on mode 1.(opposite to mode 1)\n\n  3 --> this mode encrypt your data file and convert in exe file. so that you can use this file anywhere without this application because kiddi attach on your encrypted data file.\n\n  4 --> this mode opposite to mode 3 . this mode decrypt your data file and kiddi removed on your data.\n\n 5 --> this mode mixture mode 0 and mode 3\n\n  6 --> this mode mixture mode 0 and mode 4 . opposite to mode 5 . \n";
    }

private:
    unsigned char rpass1;
    unsigned long long pass, fpass, rpass;
    void kiddi(std::string &protect)
    {
        fpass = pass = 0;
        short i;
        for (i = 0; protect[i] != 13 && protect[i] != '\0'; i++)
        {
            srand((unsigned int)protect[i] * skey * i);
            pass = ~pass;
            pass += rand() * 2010 * rand() * i;
            pass <<= (protect[i] % 10);
            pass = ~pass;
            pass ^= (~rand() * 867);
            pass >>= (protect[i] % 10);
            pass = ~pass;
            pass ^= (~protect[i] * rand());
        }
        srand(pass % 584848);
        for (i = 1; i < 5; i++, pass += (((((rand() * (long long)rand()) * 16) * skey) * 54) * i))
            ;
        for (i = 0; protect[i] != 13 && protect[i] != '\0'; i++)
        {
            srand((unsigned int)protect[i] * (pass % skey) * i);
            fpass = ~fpass;
            fpass += rand() * 2010 * rand() * i;
            fpass <<= (protect[i] % 10);
            fpass = ~fpass;
            fpass ^= (~rand() * 867);
            fpass >>= (protect[i] % 10);
            fpass += pass;
            fpass ^= (~protect[i] * rand());
        }
        srand(fpass % 264864);
        for (i = 1; i < 5; i++, fpass += (((((rand() * (long long)rand()) * 16) * skey) * 54) * i))
            ;
        rpass = 1;
        rpass1 = 1;
    }
    inline unsigned long long kiddi()
    {
        srand((int)(rpass ^ fpass));
        rpass += (((((rand() * (long long)rand()) * 16) * rand()) * 54) * skey);
        return rpass ^ pass;
    }
    inline unsigned char kiddi_nano()
    {
        srand((short)(rpass1 % skey));
        rpass1 += (rand() * skey);
        return rpass1 ^ (char)pass;
    }
};
short KIDDI::kiddi(std::string file_name, std::string password, short mode = 0, char *argv = NULL /*argv only use portable(portable = true) mode*/)
{
    if (mode > 6 || mode < 0)
    {
        return -3;
    }
    std::ifstream fr(file_name, std::ios::binary);
    if (!fr)
    {
        return -1;
    }
    long long pos, pos1 = 0, temp3, temp4;
    unsigned long long am[array_size];
    char temp_name[L_tmpnam], am1;
    int i, j;
    tmpnam(temp_name);
    std::ofstream fw(temp_name, std::ios::binary);
    if (!fw)
    {
        return -5;
    }
    if (mode == 3 || mode == 5)
    {
        std::ifstream pt(argv, std::ios::binary);
        if (!pt)
        {
            fw.close();
            fr.close();
            remove(temp_name);
            return -4;
        }
        pt.seekg(0, std::ios::end);
        pos = pt.tellg();
        pt.seekg(size_kiddi_main, std::ios::beg);
        // decrypta program add curser position
        while (pos != pos1)
        {
            pt.read((char *)&am, sizeof(am));
            pos1 = pt.tellg();
            if (pos1 == -1)
            {
                pos1 = pos;
            }
            if ((temp3 = ((pos1 - size_kiddi_main) % (sizeof(long long) * array_size))) != 0)
            {
                temp4 = temp3 / sizeof(long long);
                for (j = 0; j < temp4; j++)
                {
                    fw.write((char *)&am[j], sizeof(am[j]));
                }
                if (temp4 = (temp3 % sizeof(long long)))
                {
                    temp3 = pos - (sizeof(am1) * temp4);
                    pt.clear();
                    pt.seekg(temp3, std::ios::beg);
                    for (i = 0; i < temp4; i++)
                    {
                        pt.read(&am1, sizeof(am1));
                        fw.write(&am1, sizeof(am1));
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            fw.write((char *)&am, sizeof(am));
        }
        pt.close();
    }
    fr.seekg(0, std::ios::end);
    pos = fr.tellg();
    if (mode == 4 || mode == 6)
    {
        fr.seekg(size_kiddi_short, std::ios::beg); // tell size_kiddi_main to skip Decrypta program file
    }
    else
    {
        fr.seekg(0, std::ios::beg);
    }
    kiddi(password);
    if (mode == 1 || mode == 3)
    {
        fw.write((char *)&fpass, sizeof(fpass));
    }
    if (mode == 2 || mode == 4)
    {
        long long pass1;
        fr.read((char *)&pass1, sizeof(pass1));
        if (fpass != pass1)
        {
            return -2;
        }
    }
    char exten[10];
    if (mode == 3 || mode == 5)
    {
        size_t len = file_name.find_last_of('.');
        char exten[10];
        for (j = 0, len++; j < 10 && file_name[len] != '\0'; j++, len++)
        {
            exten[j] = file_name[len];
        }
        exten[j] = '\0';
        fw.write(exten, sizeof(exten));
    }
    if (mode == 4 || mode == 6)
    {
        fr.read(exten, sizeof(exten));
    }
    unsigned int a, b;
    long long previous = 0;
    short i1 = -2, i2;
    if (mode == 6)
    {
        temp4 = size_kiddi_short + sizeof(exten);
    }
    else if (mode == 4)
    {
        temp4 = sizeof(long long) + size_kiddi_short + sizeof(exten);
    }
    else if (mode == 0 || mode == 1 || mode == 3 || mode == 5)
    {
        temp4 = 0;
    }
    else if (mode == 2)
    {
        temp4 = sizeof(long long);
    }
    else
    {
        return -6;
    }
    while (pos != pos1)
    {
        fr.read((char *)&am, sizeof(am));
        pos1 = fr.tellg();
        if (pos1 == -1)
        {
            pos1 = pos;
        }
        for (j = 0; j < array_size; j++)
        {
            am[j] += kiddi();
            am[j] = ~am[j];
            am[j] -= kiddi();
            am[j] = ~am[j];
            am[j] += kiddi();
            am[j] = ~am[j];
        }
        i2 = time(NULL) % 10;
        if (i1 != i2)
        {
            i1 = i2;
            printf(" ---> Complete %.2fmb(%.2f%c) : Speed %.2fmb/s : Left %.f second <---\n", (double)pos1 / (1024 * 1024), ((double)pos1 / pos) * 100, '%', (double)(pos1 - previous) / (1024 * 1024), ((double)(pos - pos1)) / ((pos1 - previous)));
            previous = pos1;
        }
        temp3 = ((pos1 - temp4) % (sizeof(long long) * array_size));
        if (temp3)
        {
            temp4 = temp3 / sizeof(long long);
            for (j = 0; j < temp4; j++)
            {
                fw.write((char *)&am[j], sizeof(am[j]));
            }
            if (temp4 = (temp3 % sizeof(long long)))
            {
                temp3 = pos - (sizeof(am1) * temp4);
                fr.clear();
                fr.seekg(temp3, std::ios::beg);
                for (i = 0; i < temp4; i++)
                {
                    fr.read(&am1, sizeof(am1));
                    am1 += kiddi_nano();
                    am1 = ~am1;
                    am1 -= kiddi_nano();
                    am1 = ~am1;
                    am1 += kiddi_nano();
                    am1 = ~am1;
                    fw.write(&am1, sizeof(am1));
                }
                break;
            }
            else
            {
                break;
            }
        }
        fw.write((char *)&am, sizeof(am));
    }
    fr.close();
    fw.close();
    i2 = remove(file_name.c_str());
    if (mode == 3 || mode == 5)
    {
        size_t len = file_name.find_last_of('.');
        file_name.erase(len + 1);
        file_name.append("exe");
    }
    if (mode == 4 || mode == 6)
    {
        size_t len = file_name.find_last_of('.');
        file_name.erase(len + 1);
        file_name.append(exten);
    }
    i1 = rename(temp_name, file_name.c_str());
    if (i1 != 0 || i2 != 0)
    {
        std::cout << "some unknow error so your file is present = " << temp_name << " in temp directory" << std::endl;
        return -6;
    }
    if (mode == 1 || mode == 3 || mode == 5)
        return 1;
    else if (mode == 2 || mode == 4 || mode == 6)
        return 2;
    else
        return 0;
}
void KIDDI::kiddi(char *key)
{
    if (strcmp(key, "143"))
    {
        exit(1);
    }
    system("color 0B");
    puts("----------------------------------------------------------");
    Sleep(1000);
    printf("        %c", 73);
    Sleep(1000);
    printf("   %c", 3);
    Sleep(1000);
    printf("   %c", 89);
    Sleep(100);
    printf("%c", 111);
    Sleep(100);
    printf("%c", 117);
    Sleep(100);
    puts("   ****Wait Three Second ****\n\n");
    Sleep(3000);
    system("color 04");
    printf("      ___     _                        _    _     _     _ _\n");
    Sleep(50);
    printf("     |_ _|   | |    _____    _____    | | _( ) __| | __| (_)\n");
    Sleep(50);
    printf("      | |    | |   / _ \\ \\  / / _ \\   | |/ / |/ _' |/ _' | |\n");
    Sleep(50);
    printf("      | |    | |__| (_) \\ \\/ /  __/   |   <| | (_| | (_| | |\n");
    Sleep(50);
    printf("     |___|   |_____\\___/ \\__/ \\___|   |_|\\_\\_|\\__,_|\\__,_|_|\n");
    Sleep(50);
    printf("\n-----------------------------------------------\n");
    Sleep(2000);
    system("cls");
    system("color 07");
    exit(0);
}
void story()
// int main()
{
    system("cls");
    system("color 03");
    {
        char temp[] = {"\n  **************************** Welcome to secret space *****************************"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n\n");
    }
    Sleep(1000);
    system("color 02");
    std::cout << "           , ,',',', ,        ____________     ,~,~,~, \n";
    Sleep(100);
    std::cout << "       ,',',',',''''''',     |  Hey I Am  |   /_'_'_'_\\ \n";
    Sleep(100);
    std::cout << "     ,',',',','(  O  O ) --> |  Encrypty  |  |  O  O   )\n";
    Sleep(100);
    std::cout << "    ,',',','' <(    =  )     |____________|   \\   =   /\n";
    Sleep(100);
    std::cout << "   ',',',','  ! ',_  _,'     |  Hey I Am  |<-- ',_ _,' \n";
    Sleep(100);
    std::cout << "    ,',',',    ___|  |___    |  Decrypta  |   ___| |___\n";
    Sleep(100);
    std::cout << "    ,',','    /   \\__/    \\  |____________| /     o __  \\ \n";
    Sleep(100);
    std::cout << "    ',',',   /  ^  -o-     \\      ,|,      /   * 'o|io|  \\ \n";
    Sleep(100);
    std::cout << "      ,','  /  /   -o-   \\  \\_..._/^\\_.___/   |* 'o|__|   \\ \n";
    Sleep(100);
    std::cout << "       '   /  / \\, -o- ,/ \\___|||_'^'_|______/|* 'o' * |.  \\ \n";
    Sleep(100);
    std::cout << "           \\  \\  |_____|                      |_ 'o' _ |'  /\n";
    Sleep(100);
    std::cout << "            \\  \\/       \\                     |_|'o'|_||  /\n";
    Sleep(100);
    std::cout << "             WW/====o====\\      _^___^_       |~~~o~~~~| /   \n";
    Sleep(100);
    std::cout << "              /           \\     ( o o )       |   |   (!#\n";
    Sleep(100);
    std::cout << "             |      ^     |     (_ = _)       |   | =  |\n";
    Sleep(100);
    std::cout << "              \\     |    /      __|_|__       |=  | =  |\n";
    Sleep(100);
    std::cout << "               |    |   |    __| I am  |__    |=  |    |   \n";
    Sleep(100);
    std::cout << "               |    |   |   |  | kiddi |  |   [   | [  ]   \n";
    Sleep(100);
    std::cout << "               [  ] | [ ]  /|\\ |_______| /|\\  |   |    |       \n";
    Sleep(100);
    std::cout << "               |    /   /        |   |        |   |    |\n";
    Sleep(100);
    std::cout << "               |---/---/        /|\\ /|\\       |   |    |\n";
    Sleep(100);
    std::cout << "               |   |___|___    '''''''''   ___|~~~/~~~~|    \n";
    Sleep(100);
    std::cout << "             __[,,,,,,,\\,,,\\______________/,,,,/,,,,,,,]__\n\n";
    system("color 0a");
    Sleep(1000);
    {
        char temp[] = {"*************************************************************************************"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    system("color 05");
    {
        char temp[] = {"-------------------------------------------------------------------------------------"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    Sleep(2000);
    {
        system("color 0d");
        char temp[] = {" Encrypty :--> Hey guys. I must be very smart because I encrypt any file very smartly. I encrypt any file use a very hard algorithm on password base. No one can read encrypty's files. My best friend decrypta can only read encrypty's files. If you are ultra secure your file only one condition you now repeat encryption process on multiple password.I am not able to decrypt any file. my best friend just like me. We are nothing without each other."};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    {
        char temp[] = {"-------------------------------------------------------------------------------------"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    Sleep(1000);
    system("color 01");
    {
        char temp[] = {" Decrypta :--> I am very intelligent because I decrypt encrypty's files but before give me a password because encrypty,s files password base algorithm to be used. If you give me a wrong password I am not able to decrypt encrypty's files and I have promised to encrypty that I will decrypt the file only if the password is correct. If I don't do this the file will get corrupted. We are nothing without each other."};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    {
        char temp[] = {"-------------------------------------------------------------------------------------"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    Sleep(1000);
    {
        char temp[] = {" KIDDI :--> VERSION 2.010"};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    Sleep(1000);
    // logo();
    {
        char temp[] = {" Hey I am not human or other object. I am a KIDDI VERSION 2.010 Which is a secret name. I am not born I am a vertual. I will make from meeting of Encrypty and Decrypta. I can do the work of both Encrypty and Decrypta. I keep the features of both within myself."};
        for (int i = 0; temp[i] != '\0'; i++)
        {
            printf("%c", temp[i]);
            Sleep(100);
        }
        printf("\n");
    }
    std::cout << "Enter any key for exit\n";
    _getch();
    system("color 07");
}