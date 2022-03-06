#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int SIZE = 1000;
string s[SIZE];

bool czyPalindrom(string s)
{
    int dl =s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}

string utworz(string s)
{
    string pom;
    pom += s[0];
    int i=1;
    for(int j=1; j<s.size(); j++)
    {
        if(czyPalindrom(pom))
            i = j;
        pom += s[j];
    }
    string wynik = s.substr(i, s.size());
    reverse(wynik.begin(), wynik.end());
    return wynik + s;
}

void z1()
{
    ofstream hasla_a("hasla_a.txt");
    ofstream slowa_a("slowa_a.txt");
    int global_max = 0, global_min = 31;
    string i_min, i_max;
    for(int i=0; i<SIZE; i++)
    {
        string pom = s[i];
        reverse(pom.begin(), pom.end());
        hasla_a<<pom<<endl;
        if(pom.size() > global_max)
        {
            global_max = pom.size();
            i_max = pom;
        }
        if(pom.size() < global_min)
        {
            global_min = pom.size();
            i_min = pom;
        }
    }
    slowa_a<<"Najdluzsze: "<<i_max<<" , dlugosc: "<<global_max<<endl;
    slowa_a<<"Najkrotsze: "<<i_min<<" , dlugosc: "<<global_min<<endl;
    hasla_a.close();
    slowa_a.close();
}

void z2()
{
    ofstream hasla_b("hasla_b.txt");
    ofstream slowa_b("slowa_b.txt");
    int global_max = 0, global_min = 31, suma=0;
    string i_min, i_max;
    for(int i=0; i<SIZE; i++)
    {
        string pom;
        if(czyPalindrom(s[i]))
            pom = s[i];
        else
            pom = utworz(s[i]);
        hasla_b<<pom<<endl;
        suma += pom.size();
        if(pom.size() == 12)
            slowa_b<<pom<<endl;
        if(pom.size() > global_max)
        {
            global_max = pom.size();
            i_max = pom;
        }
        if(pom.size() < global_min)
        {
            global_min = pom.size();
            i_min = pom;
        }
    }
    slowa_b<<"Najdluzsze: "<<i_max<<" , dlugosc: "<<global_max<<endl;
    slowa_b<<"Najkrotsze: "<<i_min<<" , dlugosc: "<<global_min<<endl;
    slowa_b<<"Suma dlugosci: "<<suma<<endl;
    hasla_b.close();
    slowa_b.close();
}

int main()
{
    ifstream in("slowa.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();

    return 0;
}
