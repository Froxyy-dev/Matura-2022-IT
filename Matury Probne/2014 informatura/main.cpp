#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ofstream out("wynik_5.txt");
    long long silnia[21] = {};
    silnia[1] = 1;
    for(int i=2; i<21; i++)
        silnia[i] = silnia[i-1] * i;

    double zad1 = 1;
    int n = 10;
    for(int i=1; i<=n; i++)
        zad1 += 1.0/(double)silnia[i];

    out<<"5.1\n"<<zad1<<endl;


    long double ep = 2.71828182, delta_min = INT_MAX;
    int e1 = 0, e2 = 0, e3 = 0;
    int indeks;
    for(int i=1; i<=20; i++)
    {
        long double e = 1, delta;
        for(int j=1; j<=i; j++)
            e += 1.0/(long double)silnia[j];

        delta = fabs(e-ep);
        if(e1 == 0 && delta < 0.001)
            e1 = i;
        if(e2 == 0 && delta < 0.000001)
            e2 = i;
        if(e3 == 0 && delta < 0.000000001)
            e3 = i;

        if(delta < delta_min)
        {
            delta_min = delta;
            indeks = i;
        }
    }
    out<<"\n5.2\nNajmniej sie rozni dla: "<<indeks<<endl;
    out<< "\n5.3.\n10^3 przy n=" << e1 << endl;
    out<< "\n10^6 przy n=" << e2 << endl;
    out<< "\n10^9 przy n=" << e3 << endl;

    out.close();
    return 0;
}
