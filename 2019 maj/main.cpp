#include <iostream>
#include <fstream>

using namespace std;

int silnia(int n)
{
    if(n==0)
    {
        return 1;
    }
    int suma=1;
    for(int i=1;i<=n;i++)
    {
        suma*=i;
    }
    return suma;

}

int Oblicz(int n)
{
    int suma=0;
    while(n>0)
    {
        suma+=silnia(n%10);
        n/=10;
    }
    return suma;
}

bool Czy_potega(int n)
{
    int k=3;
    while(n>=k)
    {
        if(n==k)
        {
            return true;
        }
        k*=3;

    }
    return false;
}

int NWD(int a, int b)
{
    while(a>0&&b>0)
    {
        if(a>b)
        {
            int pom=b;
            b=a%b;
            a=pom;
        }
        else
        {
           int pom=a;
            a=b%a;
            b=pom;
        }
    }
    if(a>0)
    {
        return a;
    }
    else if(b>0)
    {
        return b;
    }

}


int main()
{

    ifstream liczby("liczby.txt");
    ofstream wyniki("wyniki4.txt");
    int tab[500];

    if(liczby.is_open())
    {
        for(int i=0;i<500;i++)
        {
            liczby>>tab[i];
        }
    }
    liczby.close();
    int ile=0;
    for(int i=0;i<500;i++)
        {
            if(Czy_potega(tab[i]))
            {
                ile++;
            }
        }
    wyniki<<"4.1"<<endl<<ile<<endl;
    wyniki<<"4.2"<<endl;
    for(int i=0;i<500;i++)
    {

        if(Oblicz(tab[i])==tab[i])
        {
            wyniki<<tab[i]<<endl;
        }
    }
    wyniki<<"4.3"<<endl;

    int indeks=0;
    int maximum=0;
    int maxNWD=0;
    for(int i=0;i<500;i++)
    {
        int pom_nwd=0;
        int ciag=1;
        int nwd=0;
        for(int j=i+1;j<500;j++)
        {
            nwd=NWD(tab[j-1],tab[j]);
            if(j==i+1)
            {
                pom_nwd=nwd;
                continue;

            }

            if(NWD(nwd,pom_nwd)==1)
            {
                break;

            }

            else
            {
                ciag++;
                if(ciag>maximum)
                {
                    maximum=ciag;
                    indeks=i;
                    maxNWD=NWD(nwd,pom_nwd);
                }
            }

        }
    }
    wyniki<<tab[indeks]<<endl;
    wyniki<<maximum<<endl;
    wyniki<<maxNWD;



    return 0;
}
