#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream out("wyniki4.txt");
const int SIZE = 1000;
int a[SIZE], b[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 ==0 && n!= 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

bool czyPodobne(int a, int b)
{
    int tab[10001];
    for(int i=0; i<10001; i++) tab[i] = 0;
    int tab1[10001];
    for(int i=0; i<10001; i++) tab1[i] = 0;
    while(a > 0)
    {
        tab[a%10]++;
        a/=10;
    }
    while(b > 0)
    {
        tab1[b%10]++;
        b/=10;
    }
    for(int i=0; i<10001; i++)
        if((tab1[i] > 0 && tab[i] == 0) || (tab[i] > 0 && tab1[i] == 0))
            return false;
    return true;

}

int odleglosc(int xa, int ya, int xb, int yb)
{
    return round(sqrt(pow(xb-xa, 2) + pow(yb-ya, 2)));
}

void z1()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(a[i]) && czyPierwsza(b[i]))
            ile++;
    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    int ile=0;
    for(int i=0; i<SIZE-1; i++)
        if(czyPodobne(a[i], b[i]))
            ile++;
    out<<"4.2\n"<<ile<<endl;
}

void z3()
{
    int max_odleglosc = 0, indeks1, indeks2;
    for(int i=0; i<SIZE-1; i++)
        for(int j=i+1; j<SIZE; j++)
            if(odleglosc(a[i],b[i],a[j],b[j]) > max_odleglosc)
            {
                max_odleglosc = odleglosc(a[i],b[i],a[j],b[j]);
                indeks1 = i;
                indeks2 = j;
            }
    out<<"4.3\n"<<max_odleglosc<<endl<<a[indeks1]<<" "<<b[indeks1]<<endl<<a[indeks2]<<" "<<b[indeks2]<<endl;
}

void z4()
{
    int ile_w = 0, ile_b = 0, ile_z = 0;
    for(int i=0; i<SIZE; i++)
    {
        /*
        if(odleglosc(a[i], b[i], 0, 0) < 5000)
            ile_w++;
        if(odleglosc(a[i], b[i], 0, 0) == 5000)
            ile_b++;
        if(odleglosc(a[i], b[i], 0, 0) > 5000)
            ile_z++;
            */
        if(a[i] > 5000 || b[i] > 5000)
                ile_z++;
        if(a[i] < 5000 && b[i] < 5000)
                ile_w++;
        if(a[i] == 5000 || b[i] == 5000)
                ile_b++;

    }
    out<<"4.4\na: "<<ile_w<<"\nb: "<<ile_b<<"\nc: "<<ile_z<<endl;
}

int main()
{
    ifstream in("punkty.txt");
    for(int i=0; i<SIZE; i++)
        in >> a[i] >> b[i];
    in.close();

    z1();
    z2();
    z3();
    z4();
    out.close();
    return 0;
}
