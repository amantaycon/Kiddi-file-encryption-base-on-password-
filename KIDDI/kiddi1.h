
#include <iostream>
#include <fstream>
#include <String>
#include <time.h>
#include <cstring>
#ifndef array_size
#define array_size 10000   // Speed control Array size (safe zone speed)
#endif 
#ifndef skey
#define skey 1654   // secure compilation key
#endif 
class KIDDI
{
public:
    short kiddi(char*, std::string&, bool);
private:
    unsigned char rpass1;
    unsigned long long pass, fpass, rpass;
    void kiddi(std::string& protect)
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
        srand(rpass ^ fpass);
        rpass += rand() * (long long)rand() * 16 * rand() * 54 * skey;
        return rpass ^ pass;
    }
    inline unsigned char kiddi_nano()
    {
        srand(rpass1 ^ fpass);
        rpass1 += rand() * skey;
        return rpass1 ^ pass;
    }
};
short KIDDI::kiddi(char* argv, std::string& password, bool ultra_secure = false) {
    std::ifstream fr(argv, std::ios::binary);
    if (!fr) {
        return 1;
    }
    long long pos;
    char temp_name[L_tmpnam];
    tmpnam(temp_name);
    fr.seekg(0, std::ios::end);
    pos = fr.tellg();
    fr.seekg(size_kiddi_short, std::ios::beg); // tell size_kiddi_main to skip Decrypta program file
    kiddi(password);
    if (!ultra_secure) {
        long long pass1;
        fr.read((char*)&pass1, sizeof(pass1));
        if (fpass != pass1) {
            return 2;
        }
    }
    char exten[10] = {"kiddi"};
    fr.read(exten, sizeof(exten));
    strcat(temp_name, ".");
    strcat(temp_name, exten);
    short i1 = -2, i2;
    std::ofstream fw(temp_name, std::ios::binary);
    if (!fw) {
        return -1;
    }
    {
        unsigned long long am[array_size], previous = 0;
        char am1;
        int countn = 0, j;
        long long temp3, temp4, pos1 = 0;
        if (ultra_secure) {
            temp4 = size_kiddi_short + sizeof(exten);
        }
        else
        {
            temp4 = sizeof(long long) + size_kiddi_short + sizeof(exten);
        }
        while (pos != pos1)
        {
            fr.read((char*)&am, sizeof(am));
            pos1 = fr.tellg();
            if (pos1 == -1)
            {
                pos1 = pos;
            }
            for (j = 0; j < array_size; j++)
            {
                am[j] ^= kiddi();
                am[j] ^= kiddi();
                am[j] ^= kiddi();
                am[j] ^= kiddi();
                am[j] ^= kiddi();
                am[j] ^= kiddi();
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
                    fw.write((char*)&am[j], sizeof(am[j]));
                }
                if (temp4 = (temp3 % sizeof(long long)))
                {
                    temp3 = pos - (sizeof(am1) * temp4);
                    fr.clear();
                    fr.seekg(temp3, std::ios::beg);
                    for (j = 0; j < temp4; j++)
                    {
                        fr.read(&am1, sizeof(am1));
                        am1 ^= kiddi_nano();
                        am1 ^= kiddi_nano();
                        am1 ^= kiddi_nano();
                        am1 ^= kiddi_nano();
                        am1 ^= kiddi_nano();
                        am1 ^= kiddi_nano();
                        fw.write(&am1, sizeof(am1));
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            fw.write((char*)&am, sizeof(am));
        }
    }
    fr.close();
    fw.close();
    i2 = system(temp_name);
    std::cout << "\n**Important Instruction :- please don,t kill this Application. Manually close this Application**\n";
    if (i2 == 0)
    {
        std::cout << "  ---> Your File Is Successfully Opened <--- \n  ---> Enter any key close this Application<--- \n";
        _getch();
    }
    else
    {
        std::cout << "  ---> Sorry Your File Is Not Opened <--- if you want to show file location(n/y)\n";
        if (_getch() == 'y') {
            std::cout << "--->you file is present directory--->" << temp_name << "\n  --->Enter any key close this Application < --- \n";
            _getch();
        }
    }
    remove(temp_name);
    return 0;
}

