#include <iostream>
#include <fstream>
#include <cmath>
#include <map>

using namespace std;

ofstream out("zadanie4.txt");
const int SIZE = 1000;
int t[SIZE];

void z1()
{
    int l_max = 0, l_min = INT_MAX;
    for(int i=1; i<SIZE; i++)
    {
        int luka = abs(t[i]-t[i-1]);
        l_max = max(l_max, luka);
        l_min = min(l_min, luka);
    }
    out<<"4.1\nWartosc najwiekszej luki: "<<l_max<<"\nWartosc najmniejszej luki: "<<l_min<<'\n';
}

void z2()
{
    int max_dl, dl, pocz, koniec, roznica;
    max_dl = dl = 2;
    pocz = t[0];
    koniec = t[1];
    roznica = abs(t[1]-t[0]);

    for(int i=2; i<SIZE; i++)
    {
        if(abs(t[i]-t[i-1]) == roznica)
            dl++;
        else
        {
            dl = 2;
            roznica = abs(t[i] - t[i-1]);
        }

        if(dl > max_dl)
        {
            max_dl = dl;
            koniec = t[i];
            pocz = t[i-dl+1];
        }
    }
    out<<"\n4.2\nDlugosc: "<<max_dl<<", Wartosc poczatkowa: "<<pocz<<", Wartosc koncowa: "<<koniec<<'\n';

}

void z3()
{
    map<int, int> mp;
    int roznica;
    for(int i=1; i<SIZE; i++)
    {
        roznica = abs(t[i] - t[i-1]);
        mp[roznica] = (mp.find(roznica) == mp.end()) ? 1 : mp[roznica] + 1;
    }
    int krotnosc = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
        if(itr->second > krotnosc)
            krotnosc = itr->second;

    out<<"\n4.3\nKrotnosc najczestszej luki: "<<krotnosc<<"\nWartosci najczestszych luk:\n";
    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
        if(itr->second == krotnosc)
            out<<itr->first<<'\n';
}

int main()
{
    ifstream in("dane4.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
