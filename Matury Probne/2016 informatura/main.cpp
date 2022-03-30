#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

ofstream out("wyniki4.txt");
const int SIZE = 2000;
string hasla[SIZE];
vector<string> perm;
vector<string> zad2;

bool czyAnagram(string a, string b)
{
    if(a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int wyszukajWzorzec(string tekst, string wzorzec)
{
    int ile = 0;
    int dl_t = tekst.size(), dl_w = wzorzec.size();
    bool ok;
    for(int i=0; i<=dl_t-dl_w; i++)
    {
        ok = true;
        for(int j=0; j<dl_w; j++)
            if(tekst[i+j] != wzorzec[j])
            {
                ok = false;
                break;
            }
        if(ok)
            ile++;
    }
    return ile;
}

void permutuj(string slowo, int poz = 0)
{
    if(poz + 1 == slowo.size())
    {
        out<<slowo<<endl;
        perm.push_back(slowo);
    }
    else
    {
        for(int i=poz; i<slowo.size(); i++)
        {
            swap(slowo[i], slowo[poz]);
            permutuj(slowo, poz + 1);
            swap(slowo[i], slowo[poz]);
        }
    }
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE-1; i++)
        for(int j=i+1; j<SIZE; j++)
            if(czyAnagram(hasla[i], hasla[j]))
                ile++;

    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    int T[6] = {};
    for(int i=0; i<SIZE; i++)
    {
        bool ok = true;
        for(int j=0; j<6; j++)
        {
            int ilosc = wyszukajWzorzec(hasla[i], perm[j]);
            T[j] += ilosc;
            if(ilosc > 1 && ok)
            {
                ok = false;
                out<<hasla[i]<<endl;
            }
        }
    }
    out<<endl;
    for(int i=0; i<6; i++)
    {
        out<<perm[i]<<" - "<<T[i]<<endl;
    }
}

void z3()
{
    out<<"\n4.3\n";
    map<char, int> mp;
    for(int i=0; i<SIZE; i++)
    {
        for(auto c : hasla[i])
            mp[c] = (mp.find(c) == mp.end()) ? 1 : mp[c] + 1;
    }
    int il_max = 0, il_min = INT_MAX;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        if(itr->second > il_max)
            il_max = itr->second;
        if(itr->second < il_min)
            il_min = itr->second;
    }
    vector<char> najw, najmn;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        if(itr->second == il_max)
            najw.push_back(itr->first);
        if(itr->second == il_min)
            najmn.push_back(itr->first);
    }
    if(najw.size() == 1)
        out<<"Litera wystepujacej najczesciej: "<<najw[0]<<endl;
    else
        out<<"Brak litery wystepujacej najczesciej"<<endl;
    if(najmn.size() == 1)
        out<<"Litera wystepujacej najrzadziej: "<<najmn[0]<<endl;
    else
        out<<"Brak litery wystepujacej najrzadziej"<<endl;

}

int main()
{
    ifstream in("hasla.txt");
    for(int i=0; i<SIZE; i++)
        in >> hasla[i];
    in.close();

    z1();
    out<<"\n4.2\n";
    permutuj("ABC");
    out<<"\n";
    z2();
    z3();

    out.close();
    return 0;
}
