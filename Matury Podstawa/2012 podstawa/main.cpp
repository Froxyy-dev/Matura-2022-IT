#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream out("zadanie4.txt");
const int SIZE = 1000;
int t[SIZE];

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

bool czyRosnaca(string s)
{
    for(int i=1; i<s.size(); i++)
        if(s[i] <= s[i-1])
            return false;
    return true;
}

int ileCyfr(int n)
{
    int ile = 0;
    while(n > 0)
    {
        ile++;
        n /= 10;
    }
    return ile;
}

bool czyRosnacaINT(int n)
{
    int dl = ileCyfr(n), i = 0;
    int *tab = new int[dl];

    while(n > 0)
    {
        tab[dl-1-i] = n % 10;
        n /= 10;
        i++;
    }

    for(int j=1; j<dl; j++)
        if(tab[j-1] >= tab[j])
            return false;
    return true;

    delete[] tab;
}

bool czyRosnacaVector(int n)
{
    vector<int> tab;
    while(n > 0)
    {
        tab.push_back(n % 10);
        n /= 10;
    }
    for(int i=1; i<tab.size(); i++)
        if(tab[i-1] <= tab[i])
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(t[i] % 2 == 0)
            ile++;
    out<<"4.\na)\n"<<ile<<'\n';
}

void z2()
{
    int max_l = sumaCyfr(t[0]), min_l = sumaCyfr(t[0]), suma, min_i = 0, max_i = 0;
    for(int i=1; i<SIZE; i++)
    {
        suma = sumaCyfr(t[i]);
        if(suma > max_l)
        {
            max_l = suma;
            max_i = i;
        }
        if(suma < min_l)
        {
            min_l = suma;
            min_i = i;
        }
    }
    out<<"\nb)\nSuma cyfr najwieksza: "<<t[max_i]<<"\nSuma cyfr najmniejsza: "<<t[min_i]<<'\n';
}

string s[SIZE];

void z3()
{
    ifstream in1("cyfry.txt");
    for(int i=0; i<SIZE; i++)
        in1 >> s[i];
    in1.close();

    out<<"\nc)\n";
    for(int i=0; i<SIZE; i++)
    {
        if(czyRosnaca(s[i]))
            out<<s[i]<<'\n';
    }
    cout<<endl;
    for(int i=0; i<SIZE; i++)
    {
        if(czyRosnacaINT(t[i]))
            cout<<t[i]<<endl;
    }
    cout<<endl;
    for(int i=0; i<SIZE; i++)
    {
        if(czyRosnacaVector(t[i]))
            cout<<t[i]<<endl;
    }
}

int main()
{
    ifstream in("cyfry.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
