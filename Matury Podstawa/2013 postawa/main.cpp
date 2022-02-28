#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ofstream out("zadanie4.txt");
const int SIZE = 1000;
string s[SIZE];

bool sameZera(string s)
{
    for(int i=0; i<s.size(); i++)
        if(s[i] != '0')
            return false;
    return true;
}

bool sameJedynki(string s)
{
    for(int i=0; i<s.size(); i++)
        if(s[i] != '1')
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(s[i].size() % 2 == 0)
            ile++;
    out<<"4.\na)\n"<<ile<<'\n';
}

void z2()
{
    int ile = 0, ileZer, ileJedynek;
    for(int i=0; i<SIZE; i++)
    {
        ileZer = 0; ileJedynek = 0;
        for(int j=0; j<s[i].size(); j++)
            if(s[i][j] == '0')
                ileZer++;
            else
                ileJedynek++;
        if(ileZer == ileJedynek)
            ile++;
    }
    out<<"\nb)\n"<<ile<<'\n';
}

void z3()
{
    int ileZer = 0, ileJedynek = 0;
    for(int i=0; i<SIZE; i++)
    {
        if(sameZera(s[i]))
        {
            ileZer++;
            continue;
        }
        if(sameJedynki(s[i]))
            ileJedynek++;
    }
    out<<"\nc)\nSame zera: "<<ileZer<<"\nSame jedynki: "<<ileJedynek<<'\n';
}

void z4()
{
    out<<"\nd)\nLiczba napisow o:\n";
    map<int, int> dl;
    for(int i=0; i<SIZE; i++)
        dl[s[i].size()] = (dl.find(s[i].size()) == dl.end()) ? 1 : dl[s[i].size()] + 1;
    for(auto itr = dl.begin(); itr != dl.end(); ++itr)
        out<<"dlugosci "<<itr->first<<", ilosc: "<<itr->second<<'\n';
}

int main()
{
    ifstream in("napisy.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();
    z4();

    out.close();
    return 0;
}
