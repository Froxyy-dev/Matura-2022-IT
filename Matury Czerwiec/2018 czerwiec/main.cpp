#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream out1("wynik4_1.txt");
ofstream out2("wynik4_2.txt");
ofstream out3("wynik4_3.txt");
ofstream out4("wynik4_4.txt");
const int SIZE = 1000;
int t[SIZE][10], d[SIZE][10];

bool porownaj(int t1[], int t2[])
{
    return (t1[9] == t2[9]);
}

bool parzyste(int t[])
{
    int ile=0;
    for(int i=0; i<10; i++)
        if(t[i]%2 == 0)
            ile++;
    return (ile == 5);
}

bool takieSame(int t1[], int t2[])
{
    int liczby1[101], liczby2[101];
    for(int i=0; i<101; i++)
    {
        liczby1[i]=0;
        liczby2[i]=0;
    }
    for(int i=0; i<10; i++)
    {
        liczby1[t1[i]]++;
        liczby2[t2[i]]++;
    }
    for(int i=0; i<101; i++)
    {
        if((liczby1[i] == 0 && liczby2[i] != 0) || (liczby2[i] == 0 && liczby1[i] != 0))
            return false;
    }
    return true;

}

void scal(int t1[], int t2[])
{
    int w[20];
    int s=0, k=0;
    for(int i=0; i<20; i++)
    {
        if(!(s>=10 || t1[s]>t2[k]))
            w[i]=t1[s++];
        else if(k<10)
            w[i]=t2[k++];
    }
    for(int i=0; i<20; i++)
        out4<<w[i]<<" ";
    out4<<endl;
}

void z1()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(porownaj(t[i], d[i]))
            ile++;
    out1<<ile;
}

void z2()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(parzyste(t[i]) && parzyste(d[i]))
            ile++;
    out2<<ile;
}

void z3()
{
    vector<int> tab;
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(takieSame(t[i], d[i]))
            {
                ile++;
                tab.push_back(i+1);
            }
    out3<<ile<<endl;
    for(int i=0; i<tab.size(); i++)
        out3<<tab[i]<<" ";
}

void z4()
{
    for(int i=0; i<SIZE; i++)
        scal(t[i], d[i]);
}

int main()
{
    ifstream in("dane1.txt");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<10; j++)
            in >> t[i][j];
    in.close();

    ifstream in1("dane2.txt");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<10; j++)
            in1 >> d[i][j];
    in1.close();

    z1();
    z2();
    z3();
    z4();
    out1.close();
    out2.close();
    out3.close();
    return 0;
}
