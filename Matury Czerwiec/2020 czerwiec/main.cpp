#include <iostream>
#include <fstream>

using namespace std;

ofstream out1("wyniki4_1.txt");
ofstream out2("wyniki4_2.txt");
ofstream out3("wyniki4_3.txt");
const int SIZE = 200;
string t[SIZE];
int suma[SIZE];

int sumaCyfr(string s)
{
    int t1 = s[3] - '0',
        t2 = s[4] - '0',
        t3 = s[5] - '0',
        t4 = s[6] - '0',
        t5 = s[7] - '0',
        t6 = s[8] - '0';
    return t1 + t2 + t3 + t4 + t5 + t6;
}

bool czyPalindrom(string s)
{
    bool ok = true;
    for(int i=3; i<=5; i++)
    {
        if(s[i] != s[11-i])
        {
            ok = false;
            break;
        }
    }
    return (s[0] == s[2] || ok);
}

bool czyPoprawny(string s)
{
    int suma = (s[0] -'A' + 10)*7 + (s[1] -'A' + 10)*3 + (s[2] -'A' + 10) +
               (s[4] -'0')*7 + (s[5] -'0')*3 + (s[6] -'0') + (s[7] -'0')*7 +
               (s[8] -'0')*3;
    suma%=10;
    return (suma + '0' == s[3]);
}

void z1()
{
    int max_suma = -1;
    for(int i=0; i<SIZE; i++)
        if(sumaCyfr(t[i]) >= max_suma)
        {
            max_suma = sumaCyfr(t[i]);
            suma[i] = max_suma;
        }
    for(int i=0; i<SIZE; i++)
        if(suma[i] == max_suma)
            out1<<t[i]<<endl;
}

void z2()
{
    for(int i=0; i<SIZE; i++)
    {
        if(czyPalindrom(t[i]))
            out2<<t[i]<<endl;
    }
}

void z3()
{
    for(int i=0; i<SIZE; i++)
        if(!czyPoprawny(t[i]))
            out3<<t[i]<<endl;

}

int main()
{
    ifstream in("identyfikator.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();
    out1.close();
    out2.close();
    out3.close();
    return 0;
}
