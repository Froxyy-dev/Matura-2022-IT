#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wyniki6.txt");
const int SIZE = 5000;
string l[SIZE];

int octToDec(string s)
{
    int wynik = 0, k=1;
    for(int i=s.size()-1; i>=0; i--)
    {
        wynik += (s[i] - '0')*k;
        k*=8;
    }
    return wynik;
}

bool czySpelnia(int n)
{
    int k = n%10, pom;
    while(n > 0)
    {
        pom = n%10;
        n/=10;
    }
    return (k == pom);
}

bool czyRosnaca(string s)
{
    for(int i=1; i<s.size(); i++)
        if(s[i] < s[i-1])
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(l[i][0] == l[i][l[i].size()-1])
            ile++;
    out<<"6.\na)\n"<<ile<<"\n";
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        int pom = octToDec(l[i]);
        if(czySpelnia(pom))
            ile++;
    }
    out<<"\nb)\n"<<ile<<"\n";
}

void z3()
{
    int ile = 0;
    string max_l = "9", min_l = "2000001";
    for(int i=0; i<SIZE; i++)
        if(czyRosnaca(l[i]))
        {
            ile++;
            if(l[i].size() >max_l.size() || (l[i].size() == max_l.size() && l[i]>max_l))
                max_l = l[i];

            if(l[i].size() <min_l.size() || (l[i].size() == min_l.size() && l[i]<min_l))
                min_l = l[i];
        }
    out<<"\nc)\nIlosc liczb: "<<ile<<"\nNajwieksza: "<<max_l<<"\nNajmniejsza: "<<min_l;
}

int main()
{
    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> l[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
