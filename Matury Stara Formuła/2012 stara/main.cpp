#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wynik4a.txt");
ofstream out1("wynik4b.txt");
const int SIZE = 120;
string tj[SIZE], klucze1[SIZE], sz[SIZE], klucze2[SIZE];

string szyfruj(string tekst, string klucz)
{
    int dl = klucz.size();
    for(int i=0; i<tekst.size(); i++)
    {
        int k = int(klucz[i%dl]) - int('A') + 1;
        if(tekst[i] + k > 'Z')
            tekst[i] += k - 26;
        else
            tekst[i] += k;
    }
    return tekst;
}

string deszyfruj(string tekst, string klucz)
{
    int dl = klucz.size();
    for(int i=0; i<tekst.size(); i++)
    {
        int k = int(klucz[i%dl]) - int('A') + 1;
        if(tekst[i] - k < 'A')
            tekst[i] = tekst[i] - k + 26;
        else
            tekst[i] = tekst[i] - k;
    }
    return tekst;
}

void z1()
{
    for(int i=0; i<SIZE; i++)
        out<<szyfruj(tj[i], klucze1[i])<<endl;
}

void z2()
{
    for(int i=0; i<SIZE; i++)
        out1<<deszyfruj(sz[i], klucze2[i])<<endl;
}

int main()
{
    ifstream in("tj.txt");
    for(int i=0; i<SIZE; i++)
        in >> tj[i];
    in.close();

    ifstream in1("klucze1.txt");
    for(int i=0; i<SIZE; i++)
        in1 >> klucze1[i];
    in1.close();

    ifstream in2("sz.txt");
    for(int i=0; i<SIZE; i++)
        in2 >> sz[i];
    in2.close();

    ifstream in3("klucze2.txt");
    for(int i=0; i<SIZE; i++)
        in3 >> klucze2[i];
    in3.close();

    z1();
    z2();

    out.close();
    out1.close();
    return 0;
}
