#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int SIZE = 1000;
string s[SIZE];

bool czyPalindrom(string s)
{
    /*
    string pom = s;
    reverse(s.begin(), s.end());
    return pom == s;
    */

    int dl = s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}

int main()
{
    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    ofstream out("zadanie4.txt");

    for(int i=0; i<SIZE; i++)
        if(czyPalindrom(s[i]))
            out<<s[i]<<endl;

    out.close();
    return 0;
}
