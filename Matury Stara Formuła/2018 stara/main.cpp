#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

ofstream out("wyniki6.txt");
const int SIZE = 1000;
string s[SIZE][2];

bool czyZawiera(string tekst, string wzorzec)
{
    int dl_t = tekst.size(), dl_w = wzorzec.size();
    for(int i=0; i<=dl_t - dl_w; i++)
    {
        bool ok = true;
        for(int j=0; j<dl_w; j++)
            if(tekst[j+i] != wzorzec[j])
            {
                ok =false;
                break;
            }
        if(ok)
            return true;
    }
    return false;
}

bool czyZawiera_v2(string tekst, string wzorzec)
{
    if(tekst.find(wzorzec) != string::npos)
        return true;
    return false;
}

bool czyAnagram(string a, string b)
{
    int dl_a = a.size(), dl_b = b.size();
    if(dl_a != dl_b) return false;
    map<char, int> mp;
    for(const auto &c:a)
    {
        mp[c] = (mp.find(c) == mp.end()) ? 1 : mp[c]+1;
    }
    for(const auto &c:b)
    {
        if(mp.find(c) == mp.end())
            return false;
        mp[c]--;
    }
    for(map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
        if(itr->second != 0)
            return false;
    return true;
}

bool czyAnagram_v2(string a, string b)
{
    int dl_a = a.size(), dl_b = b.size();
    if(dl_a != dl_b) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<dl_a; i++)
        if(a[i] != b[i])
            return false;
   return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        int dl_a = s[i][0].size(), dl_b = s[i][1].size();
        if(s[i][0][dl_a-1] == 'A')
            ile++;
        if(s[i][1][dl_b-1] == 'A')
            ile++;
    }
    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyZawiera(s[i][1], s[i][0]))
            ile++;
    out<<"\n4.2\n"<<ile<<endl;
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyAnagram(s[i][0], s[i][1]))
            ile++;
    out<<"\n4.3\n"<<ile<<endl;
}

int main()
{
    ifstream in("slowa.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i][0] >> s[i][1];
    in.close();

    z1();
    z2();
    z3();
    out.close();

    return 0;
}
