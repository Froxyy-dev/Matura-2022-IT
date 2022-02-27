#include <iostream>
#include <fstream>

using namespace std;

ofstream out1("wyniki4_1.txt");
ofstream out2("wyniki4_2.txt");
ofstream out3("wyniki4_3.txt");

const int SIZE = 5000;
int l[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 ==0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

bool czyPalindrom(string s)
{
    int dl = s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;

    return true;
}

bool czyPara(int a, int b)
{
    int Ta[10] = {}, Tb[10] = {};
    while(a > 0)
    {
        Ta[a%10]++;
        a/=10;
    }
    while(b > 0)
    {
        Tb[b%10]++;
        b/=10;
    }
    for(int i=0; i<10; i++)
        if((Ta[i] == 0 && Tb[i] != 0) || (Tb[i] == 0 && Ta[i] != 0))
            return false;
    return true;
}

string decToBin(int n)
{
    string wynik;
    while(n>0)
    {
        wynik = char(n%2 + '0')+ wynik;
        n/=2;
    }
    return wynik;
}

void z1()
{
    int ile=0, max_p = 99, min_p = 999999;
    for(int i=0; i<SIZE; i++)
        if(czyPierwsza(l[i]))
        {
            ile++;
            if(l[i] > max_p)
                max_p = l[i];
            if(l[i] < min_p)
                min_p = l[i];
        }
    out1<<"Liczba liczb pierwszych: "<<ile<<"\nNajwieksza liczba: "<<max_p<<"\nNajmniejsza liczba: "<<min_p;
}

void z2()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        string binarna = decToBin(l[i]);
        if(czyPalindrom(binarna))
        {
            //cout<<binarna<<" TAK"<<endl;
            ile++;
            continue;
        }
        //cout<<binarna<<" ";
        int dl = binarna.size();
        int j=1;
        while(binarna[dl-j] == '0')
            j++;
        for(int a=0; a<j-1; a++)
            binarna = '0' + binarna;
        //cout<<binarna;

        if(czyPalindrom(binarna))
        {
            ile++;
            //cout<<" TAK";
        }
        //cout<<endl;

    }
    out2<<ile;
}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE-1; i++)
        for(int j=i+1; j<SIZE; j++)
            if(czyPara(l[i], l[j]))
                ile++;
    out3<<ile;
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

    out1.close();
    out2.close();
    out3.close();
    return 0;
}
