#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 200;
string s[SIZE];

bool czyPalindrom(string s)
{
    int dl = s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}

bool czyAscii(string s)
{
    for(int i=0; i<s.size()-1; i++)
        if(int(s[i] + s[i+1]) == 220)
            return true;
    return false;
}

void z1()
{
    ofstream out1("wynik4a.txt");
    int il_p = 0, il_np = 0;
    for(int i=0; i<SIZE; i++)
    {
        if(!(s[i].size() & 1))
            il_p++;
        else
            il_np++;

    }
    out1<<"Liczba znakow:\nparzysta: "<<il_p<<"\nnieparzysta: "<<il_np<<'\n';
    out1.close();
}

void z2()
{
    ofstream out2("wynik4b.txt");
    for(int i=0; i<SIZE; i++)
    {
        if(czyPalindrom(s[i]))
            out2<<s[i]<<'\n';
    }
    out2.close();
}

void z3()
{
    ofstream out3("wynik4c.txt");
    for(int i=0; i<SIZE; i++)
    {
        if(czyAscii(s[i]))
            out3<<s[i]<<'\n';
    }
    out3.close();
}

int main()
{
    ifstream in("hasla.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();

    return 0;
}
