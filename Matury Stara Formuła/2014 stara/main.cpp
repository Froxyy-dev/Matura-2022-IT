#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ofstream out("ZADANIE5.TXT");
const int SIZE = 1000;
string s[SIZE];

bool czyPierwsza(string s)
{
    int n=0;
    for(auto const &c:s)
        n += c;
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

bool czyRosnacy(string s)
{
    for(int i=1; i<s.size(); i++)
        if(s[i] <= s[i-1])
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(s[i]))
            ile++;
    out<<"5\na)\n"<<ile<<endl;
}

void z2()
{
    out<<"\nb)\n";
    for(int i=0; i<SIZE; i++)
        if(czyRosnacy(s[i]))
            out<<s[i]<<endl;
}

void z3()
{
    out<<"\nc)\n";
    map<string, int> napisy;
    for(int i=0; i<SIZE; i++)
        napisy[s[i]] = (napisy.find(s[i]) == napisy.end()) ? 1 : napisy[s[i]] + 1;
    for(map<string, int>::iterator itr = napisy.begin(); itr != napisy.end(); ++itr)
        if(itr->second > 1)
            out<<itr->first<<endl;
}

int main()
{
    ifstream in("NAPIS.TXT");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
