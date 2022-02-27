#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ofstream out("wyniki_6.txt");
const int SIZE = 2000;
int t[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(t[i]))
            ile++;
    out<<"6.1\n"<<ile<<'\n';
}

void z2()
{
    int max_p = 0, min_p =30001;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(t[i]))
        {
            if(t[i] > max_p)
                max_p = t[i];
            if(t[i] < min_p)
                min_p = t[i];
        }
    out<<"\n6.2\nNajwieksza liczba pierwsza: "<<max_p<<"\nNajmniejsza liczba pierwsza: "<<min_p<<'\n';
}

void z3()
{
    vector<int> blizniacze;
    int ile = 0;
    for(int i=0; i<SIZE-1; i++)
    {
        if(czyPierwsza(t[i]) && czyPierwsza(t[i+1]) && abs(t[i] - t[i+1]) == 2)
        {
            ile++;
            blizniacze.push_back(t[i]);
            blizniacze.push_back(t[i+1]);
        }
    }
    out<<"\n6.3\nLiczba par blizniaczych: "<<ile<<"\nPary liczb:\n";

    for(int i=0; i<blizniacze.size()-1; i+=2)
        out<<blizniacze[i]<<" i "<<blizniacze[i+1]<<'\n';
}

int main()
{
    ifstream in("dane_6.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
