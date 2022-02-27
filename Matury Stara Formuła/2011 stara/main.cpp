#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ofstream out("zadanie6.txt");
const int SIZE = 1000;
string l[SIZE];

void z1()
{
    int ile_parzystych = 0;
    for(int i=0; i<SIZE; i++)
    {
        int last = l[i].size()-1;
        if(l[i][last] == '0')
            ile_parzystych++;
    }
    out<<"6.\na)\n"<<ile_parzystych<<endl;
}

int binToDec(string s)
{
    int wynik = 0;
    for(int i=0; i<s.size(); i++)
        wynik = wynik*2 + (s[i] - '0');
    return wynik;
}

string decToBin(int n)
{
    string wynik;
    while(n > 0)
    {
        wynik = char(n%2 + '0') + wynik;
        n /= 2;
    }
    return wynik;
}

string dodawanie(string a, string b)
{
    string wynik;
    int schowek = 0, pom;
    while(a.size() || b.size())
    {
        pom = schowek;
        schowek = 0;
        if(a.size())
        {
            if(a.back() == '1')
                pom++;
            a.pop_back();
        }
        if(b.size())
        {
            if(b.back() == '1')
                pom++;
            b.pop_back();
        }
        if(pom >= 2)
        {
            schowek =  1;
            pom -= 2;
        }
        wynik.push_back(pom + '0');
    }
    if(schowek)
        wynik.push_back('1');

    reverse(wynik.begin(), wynik.end());
    return wynik;
}

void z2()
{
    int indeks = 0, max_l = 0;
    for(int i=0; i<SIZE; i++)
    {
        int tmp = binToDec(l[i]);
        if(tmp > max_l)
        {
            indeks = i;
            max_l = tmp;
        }
    }
    out<<"\nb)\n"<<l[indeks]<<"\n"<<max_l<<endl;
}

void z3()
{
    int ile = 0, suma = 0;
    string suma_test = "0";
    for(int i=0; i<SIZE; i++)
    {
        int tmp = l[i].size();
        if(tmp == 9)
        {
            ile++;
            suma += binToDec(l[i]);
            suma_test = dodawanie(suma_test, l[i]);
        }
    }
    out<<"\nc)\n"<<ile<<"\n"<<decToBin(suma)<<"\n"<<suma_test;
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> l[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
