#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ofstream out("wyniki.txt");
const int SIZE = 1000;
string s[SIZE];

bool czyPalindrom(string s)
{
    int dl = s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}

void z1()
{
    int ile = 0, global_max = 0;
    string slowo;
    map<string, int> mp;
    for(int i=0; i<SIZE; i++)
        mp[s[i]] = (mp.find(s[i]) == mp.end()) ? 1 : mp[s[i]] + 1;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
        if(itr->second > 1)
        {
            ile++;
            if(itr->second > global_max)
            {
                global_max = itr->second;
                slowo = itr->first;
            }
        }
    out<<"c)\n"<<palin<<endl;
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if((s[i][s[i].size()-1] - 'A') % 2 == 0)
            ile++;
    out<<"\nb)\n"<<ile<<'\n';
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyPalindrom(s[i]))
            ile++;
    out<<"\nc)\n"<<ile<<'\n';
}

int main()
{
    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
