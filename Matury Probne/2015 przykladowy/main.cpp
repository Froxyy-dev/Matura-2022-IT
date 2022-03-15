#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

ofstream out("wyniki_anagramy.txt");
const int SIZE = 1000;
string s[SIZE][2];

bool czyAnagram(string a, string b)
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
        if(czyAnagram(s[i][0], s[i][1]))
            ile++;
    out<<"4.\na)\nIlosc wierszy: "<<ile<<'\n';
}

void z2()
{
    map<string, int> anagramy;
    for(int i=0; i<SIZE; i++)
    {
        string tmp1 = s[i][0];
        string tmp2 = s[i][1];
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());

        anagramy[tmp1] = (anagramy.find(tmp1) == anagramy.end()) ? 1 : anagramy[tmp1] + 1;
        anagramy[tmp2] = (anagramy.find(tmp2) == anagramy.end()) ? 1 : anagramy[tmp2] + 1;
    }

    int global_max = 0;
    for(auto itr=anagramy.begin(); itr != anagramy.end(); ++itr)
        if(itr->second > global_max)
            global_max = itr->second;
    out<<"\nb)\nMaksymalna ilosc liczb: "<<global_max<<'\n';

}

int main()
{
    ifstream in("dane_anagramy.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i][0] >> s[i][1];
    in.close();

    z1();
    z2();

    out.close();
    return 0;
}
