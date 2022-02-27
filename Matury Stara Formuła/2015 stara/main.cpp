#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wynik4.txt");
const int SIZE = 1000;
string s[SIZE];

bool czyWiecej(string s)
{
    int dl = s.size(), ile = 0;
    for(int i=0; i<dl; i++)
        if(s[i] == '0')
            ile++;
    return (ile > dl - ile);
}

int iloscBlokowZera(string s)
{
    int max_dl = 0, dl = 1;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i] == s[i-1] && s[i] == '0')
            dl++;
        else
            dl = 1;
        if(dl > max_dl)
            max_dl = dl;
    }
    return max_dl;
}


int iloscBlokow(string s)
{
    int ilosc = 1, dl = s.size();
    for(int i = 1; i<dl; i++)
    {
        if(s[i-1] != s[i])
            ilosc++;
    }
    return ilosc;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czyWiecej(s[i]))
            ile++;
    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(iloscBlokow(s[i]) == 2 && s[i][0] == '0' && s[i][s[i].size()-1] == '1')
            ile++;
    out<<"\n4.2\n"<<ile<<endl;
}

void z3()
{
    int max_dl = 0;
    int tab[SIZE] = {};
    for(int i=0; i<SIZE; i++)
    {
        int dl = iloscBlokowZera(s[i]);
        tab[i] = dl;
        if(max_dl < dl)
            max_dl = dl;
    }
    out<<"\n4.3\nNajdluzszy: "<<max_dl<<"\nSlowa: \n";
    for(int i=0; i<SIZE; i++)
        if(tab[i] == max_dl)
            out<<s[i]<<endl;
}

int main()
{
    ifstream in("slowa.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    z1();
    z2();
    z3();


    out.close();
    return 0;
}
