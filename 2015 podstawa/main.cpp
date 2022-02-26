#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

ofstream out("wynik5.txt");
const int Slowa = 1000, Nowe = 25;
string s[Slowa], n[Nowe];

void z1()
{
    int T[13], dl;
    for(int i=1; i<13; i++)
        T[i] = 0;
    for(int i=0; i<Slowa; i++)
    {
        dl = s[i].size();
        T[dl]++;
    }
    out<<"5.1\n";
    for(int i=1; i<13; i++)
        out<<"Liczba: "<<i<<", ilosc wierszy: "<<T[i]<<'\n';
}

void z2()
{
    map<string, int> wystapienia;
    for(int i=0; i<Slowa; i++)
        wystapienia[s[i]] = (wystapienia.find(s[i]) == wystapienia.end()) ? 1 : wystapienia[s[i]] + 1;
    out<<"\n5.2\n";
    for(int i=0; i<Nowe; i++)
    {
        out<<n[i]<<" ";
        if(wystapienia.find(n[i]) == wystapienia.end())
            out<<0<<" ";
        else
            out<<wystapienia[n[i]]<<" ";

        reverse(n[i].begin(), n[i].end());

        if(wystapienia.find(n[i]) == wystapienia.end())
            out<<0<<" ";
        else
            out<<wystapienia[n[i]]<<" ";

        out<<endl;
    }

}

int main()
{
    ifstream in("slowa.txt");
    for(int i=0; i<Slowa; i++)
        in >> s[i];
    in.close();

    ifstream in1("nowe.txt");
    for(int i=0; i<Nowe; i++)
        in1 >> n[i];
    in1.close();

    z1();
    z2();

    out.close();
    return 0;
}
