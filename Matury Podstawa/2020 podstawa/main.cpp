#include <iostream>
#include <fstream>
#include <set>
//#include <unordered_set>

using namespace std;

ofstream out("wyniki4.txt");
const int SIZE = 1000;
int t[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n%10;
        n/=10;
    }
    return suma;
}

void z1()
{
    int ile = 0, ile_p = 0;
    for(int i=0; i<SIZE; i++)
        if(t[i]%2 == 1)
            ile++;
        else
        {
            cout<<t[i]<<endl;
            ile_p++;
        }

    cout<<ile_p <<" + "<<ile<<" = "<<ile_p+ile<<endl;
    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    out<<"\n4.2\n";
    for(int i=0; i<SIZE; i++)
        if(sumaCyfr(t[i]) == 11)
            out<<t[i]<<'\n';
}

void z3()
{
    out<<"\n4.3\n";
    set<int> pierwsze;
    out<<"Liczby sie powtarzaja:\n";
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(t[i]) && t[i] >= 4000 && t[i] <= 5000)
        {
            out<<t[i]<<'\n';
            pierwsze.insert(t[i]);
        }
    out<<"\nLiczby sie nie powtarzaja:\n";
    for(auto itr = pierwsze.begin(); itr != pierwsze.end(); ++itr)
        out<<*itr<<'\n';
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
