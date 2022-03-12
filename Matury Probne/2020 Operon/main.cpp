#include <iostream>
#include <fstream>
#include <vector>
#define MAX 10000
#define SIZE 2526

using namespace std;

ofstream out("wyniki4.txt");
int t[SIZE];
vector<int> szczesliwe;

bool czySzczesliwa(int n)
{
    for(int i=0; i<szczesliwe.size(); i++)
        if(szczesliwe[i] == n)
            return true;
    return false;
}

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czySzczesliwa(t[i]))
            ile++;

    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    int max_dl = 0, dl = 0, pierwszy;

    if(czySzczesliwa(t[0]))
        dl = 1;

    for(int i=1; i<SIZE; i++)
    {
        if(czySzczesliwa(t[i]))
            dl++;
        else
            dl = 0;
        if(dl > max_dl)
        {
            max_dl = dl;
            pierwszy = t[i-dl+1];
        }
    }
    out<<"\n4.2\n"<<max_dl<<" "<<pierwszy<<endl;
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(czySzczesliwa(t[i]) && czyPierwsza(t[i]))
            ile++;
    out<<"\n4.3\n"<<ile<<'\n';
}

int main()
{
    int tab[MAX+1];
    tab[0] = 1;
    for(int i=1; i<=MAX; i++)
        tab[i] = 0;

    int pom, n;
    for(int i=2; i<=MAX; i++)
        if(!tab[i])
        {
            n=i;
            pom = 1;
            for(int j=1; j<=MAX; j++)
            {
                if(!tab[j])
                {
                    if(pom == n)
                    {
                        tab[j] = 1;
                        pom = 0;
                    }
                    pom++;
                }
            }
        }

    for(int i=0; i<=MAX; i++)
        if(!tab[i])
            szczesliwe.push_back(i);

    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
