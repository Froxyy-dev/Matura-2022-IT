#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wyniki4.txt");
const int SIZE = 1000;
int t[SIZE][3];

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
        if(t[i][0] < t[i][1] && t[i][1] < t[i][2])
            ile++;
    out<<"4.1\n"<<ile<<'\n';
}

void z2()
{
    int suma_d = 0, pom;
    for(int i=0; i<SIZE; i++)
    {
        pom = NWD(t[i][0], t[i][1]);
        pom = NWD(pom, t[i][2]);
        suma_d += pom;
    }
    out<<"\n4.2\n"<<suma_d<<'\n';
}

int tab[SIZE];

void z3()
{
    int global_max = 0, suma, ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        suma = sumaCyfr(t[i][0]) + sumaCyfr(t[i][1]) + sumaCyfr(t[i][2]);
        tab[i] = suma;
        if(suma == 35)
            ile++;
        if(suma > global_max)
            global_max = suma;
    }
    out<<"\n4.3\nLiczba wierszy o sumie cyfr 35: "<<ile<<"\nNajwieksza suma: "<<global_max;
    int wystapienia = 0;
    for(int i=0; i<SIZE; i++)
        if(tab[i] == global_max)
            wystapienia++;
    out<<"\nWystapila ona "<<wystapienia<<" razy";
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<3; j++)
            in >> t[i][j];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
