#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ofstream out1("odp_4a.txt");
ofstream out2("odp_4b.txt");
const int SIZE = 200;
string s[SIZE][5];

bool czyAnagram(string a, string b)
{
    if(a.size() != b.size()) return false;
    map<char, int> mp;

    for(auto const &c:a)
        mp[c] = (mp.find(c) == mp.end()) ? 1 : mp[c] + 1;
    for(auto const &c:b)
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

void z1()
{
    for(int i=0; i<SIZE; i++)
    {
        int dl1 = s[i][0].size(),
            dl2 = s[i][1].size(),
            dl3 = s[i][2].size(),
            dl4 = s[i][3].size(),
            dl5 = s[i][4].size();
        if(dl1 == dl2 && dl2 == dl3 && dl3 == dl4 && dl4 == dl5)
        {
            for(int j=0; j<5; j++)
                out1<<s[i][j]<<" ";
            out1<<endl;
        }
    }
}

void z2()
{
    for(int i=0; i<SIZE; i++)
    {
        bool b1 = czyAnagram(s[i][0], s[i][1]),
             b2 = czyAnagram(s[i][1], s[i][2]),
             b3 = czyAnagram(s[i][2], s[i][3]),
             b4 = czyAnagram(s[i][3], s[i][4]);
        if(b1 && b2 && b3 && b4)
        {
            for(int j=0; j<5; j++)
                out2<<s[i][j]<<" ";
            out2<<endl;
        }
    }
}

int main()
{
    ifstream in("anagram.txt");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<5; j++)
            in >> s[i][j];
    in.close();

    z1();
    z2();

    out1.close();
    out2.close();
    return 0;
}
