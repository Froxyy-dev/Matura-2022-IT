#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream out("wyniki5.txt");
const int SIZE = 1000;
int t[SIZE];
string s[SIZE];

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n%10;
        n /= 10;
    }
    return suma;
}

void z1()
{
    int global_max = 0;
    for(int i=0; i<SIZE; i++)
        if(t[i]%2 == 0 && t[i] > global_max)
            global_max = t[i];
    out<<"5.1\nNajwieksza liczba parzysta: "<<global_max<<'\n';
}

void z2()
{
    ifstream in1("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in1 >> s[i];
    in1.close();

    out<<"\n5.2\n";
    string pom;
    for(int i=0; i<SIZE; i++)
    {
        pom = s[i];
        reverse(s[i].begin(), s[i].end());
        if(s[i] == pom)
            out<<s[i]<<'\n';
    }
}

void z3()
{
    out<<"\n5.3\n";
    int global_sum = 0, suma;
    for(int i=0; i<SIZE; i++)
    {
        suma = sumaCyfr(t[i]);
        global_sum += suma;
        if(suma > 30)
            out<<t[i]<<'\n';
    }
    out<<"Suma wszystkich cyfr: "<<global_sum<<'\n';
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
