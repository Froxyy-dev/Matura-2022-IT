#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream out("wyniki3.txt");
const int SIZE = 1000;
int M[SIZE], a[SIZE], b[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

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

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(M[i]))
            ile++;
    out<<"3.3\n"<<ile<<endl;
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(NWD(M[i], a[i]) == 1)
            ile++;
    out<<"3.4\n"<<ile<<endl;
}

long long potega(int a, int x, int M)
{
    long long w = 1;
    while(x > 0)
    {
        if(x%2 == 1)
            w = w*a%M;
        a = a*a%M;
        x /= 2;
    }
    return w;
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        for(int x=0; x<M[i]; x++)
        {
            int pom = potega(a[i], x, M[i]);
            if(pom % M[i] == b[i])
            {
                ile++;
                break;
            }
        }

    }
    out<<"3.5\n"<<ile<<endl;
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> M[i] >> a[i] >> b[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
