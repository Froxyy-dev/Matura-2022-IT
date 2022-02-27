#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream out1("wyniki4_1.txt");
ofstream out2("wyniki4_2.txt");
ofstream out3("wyniki4_3.txt");
const int SIZE = 300, SIZE1 = 200;
int l[SIZE];
int p[SIZE1];

int ileCyfr(int n)
{
    int ile=0;
    while(n > 0)
    {
        n/=10;
        ile++;
    }
    return ile;
}

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n%10;
        n/=10;
    }
    return suma;
}

int waga(int n)
{
    int waga = sumaCyfr(n);
    while(ileCyfr(waga) > 1)
    {
        waga = sumaCyfr(waga);
    }
    return waga;
}

int odwrocona(int n)
{
    int k = pow(10,ileCyfr(n)-1), suma = 0;
    while(n > 0)
    {
        suma += k*(n%10);
        k/=10;
        n/=10;
    }
    return suma;
}

bool czyPierwsza(int n)
{
    if(n < 2) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

void z1()
{
    for(int i=0; i<SIZE; i++)
        if(l[i] >= 100 && l[i] <=5000)
            if(czyPierwsza(l[i]))
                out1<<l[i]<<"\n";

}

void z2()
{
    for(int i=0; i<SIZE1; i++)
        if(czyPierwsza(odwrocona(p[i])))
            out2<<p[i]<<endl;

}

void z3()
{
    int ile=0;
    for(int i=0; i<SIZE1; i++)
        if(waga(p[i]) == 1)
            ile++;
    out3<<ile;
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> l[i];
    in.close();

    ifstream in1("pierwsze.txt");
    for(int i=0; i<SIZE1; i++)
        in1 >> p[i];
    in1.close();

    z1();
    z2();
    z3();
    out1.close();
    out2.close();
    out3.close();
    return 0;
}
