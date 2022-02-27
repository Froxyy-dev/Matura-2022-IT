#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wyniki6.txt");
const int SIZE = 1000;
string s[SIZE];

bool czyPoprawny(string s)
{
    int suma = 1*(s[0] - '0') + 3*(s[1] - '0') + 7*(s[2] - '0') + 9*(s[3] - '0')
             + 1*(s[4] - '0') + 3*(s[5] - '0') + 7*(s[6] - '0') + 9*(s[7] - '0')
             + 1*(s[8] - '0') + 3*(s[9] - '0') + 1*(s[10] - '0');
    return !(suma%10);
}

void z1()
{
    out<<"6.1\n";
    int l_kobiet = 0, l_mezczyzn = 0;
    for(int i=0; i<SIZE; i++)
        if((s[i][9]-'0')%2 == 0)
            l_kobiet++;
        else
            l_mezczyzn++;
    out<<"Liczba numerow PESEL kobiet: "<<l_kobiet<<"\nLiczba numerow PESEL mezczyzn: "<<l_mezczyzn<<'\n';

}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        int m = (s[i][2] - '0')*10;
        int mm = (s[i][3] - '0');
        int miesiac = m+mm;
        if(miesiac > 20)
            miesiac -= 20;
        if(miesiac == 11)
            ile++;
    }
    out<<"\n6.2\n"<<ile<<'\n';
}

void z3()
{
    out<<"\n6.3\n";
    for(int i=0; i<SIZE; i++)
        if(czyPoprawny(s[i]) == false)
            out<<s[i]<<endl;
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
