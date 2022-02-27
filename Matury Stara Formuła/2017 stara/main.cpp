#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream out("zadanie4.txt");
const int SIZE =  500;
string s[SIZE];

int binToDec(string s)
{
    int wynik = 0;
    for(int i=0; i<s.size(); i++)
        wynik = wynik*2 + (s[i] - '0');
    return wynik;
}


bool czyDwucykliczny(string s)
{
    int pol = (s.size()/2) - 1;
    string pom1 = s.substr(0, pol+1), pom2 = s.substr(pol+1, pol+1);
    /*
    string pom1, pom2;
    for(int i =0; i<=pol; i++)
        pom1 += s[i];
    for(int i=pol+1; i<s.size(); i++)
        pom2 +=s[i];
        */
    return pom1 == pom2;
}

void z1()
{
    int ile = 0, max_dl = 0, indeks;
    for(int i=0; i<SIZE; i++)
        if(czyDwucykliczny(s[i]))
        {
            ile++;
            if(s[i].size() > max_dl)
            {
                max_dl = s[i].size();
                indeks = i;
            }
        }
    out<<"4.1\nLiczba dwucyklicznych: "<<ile<<"\nNapis: "<<s[indeks]<<"\nJego dlugosc: "<<max_dl<<endl;
}

void z2()
{
    int ile = 0, min_dl = 999999;
    bool ok;
    for(int i=0; i<SIZE; i++)
    {
        ok = false;
        int dl = s[i].size();
        for(int j=0; j<dl; j+=4)
        {
            string pom = s[i].substr(j, 4);
            if(binToDec(pom) > 9)
            {
                ok = true;
                break;
            }
        }
        if(ok)
        {
            ile++;
            if(dl < min_dl)
                min_dl = dl;
        }
    }
    out<<"\n4.2\nLiczba niepoprawnych napisow: "<<ile
    <<"\nNajmniejsza dlugosc niepoprawnego napisu: "<<min_dl<<endl;
}

void z3()
{
    int indeks, max_l = 0;
    for(int i=0; i<SIZE; i++)
    {
        string p = s[i];
        reverse(p.begin(), p.end());
        while(p.back() == '0')
            p.pop_back();
        reverse(p.begin(), p.end());
        if(p.size() > 16)
            continue;
        int pom = binToDec(p);
        if(pom > max_l)
        {
            max_l = pom;
            indeks = i;
        }
    }
    out<<"\n4.3\n"<<s[indeks]<<", "<<max_l;
}

int main()
{
    ifstream in("binarne.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
