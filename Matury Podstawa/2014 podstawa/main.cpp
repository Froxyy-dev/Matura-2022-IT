#include <iostream>
#include <fstream>

using namespace std;

ofstream out("ZADANIE5.TXT");
const int SIZE = 1000;
int t[SIZE][2];

int NWD(int a, int b)
{
    int pom;
    while(b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }
    return a;
}

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n%10;
        n /= 10;
    }
    return suma;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(t[i][0] % t[i][1] == 0 || t[i][1] % t[i][0] == 0)
            ile++;
    out<<"5.\na)\n"<<ile<<'\n';
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(NWD(t[i][0], t[i][1]) == 1)
            ile++;
    out<<"\nb)\n"<<ile<<'\n';
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(sumaCyfr(t[i][0]) == sumaCyfr(t[i][1]))
            ile++;
    out<<"\nc)\n"<<ile<<'\n';
}

int main()
{
    ifstream in("PARY_LICZB.TXT");
    for(int i=0; i<SIZE; i++)
        in >> t[i][0] >> t[i][1];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
