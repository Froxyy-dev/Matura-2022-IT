#include <iostream>
#include <fstream>
#include <cmath>

#define SIZE 100

using namespace std;

int t[SIZE][3];
int r[SIZE];

bool czyZawiera(int a, int b, int r, int x, int y)
{
    return pow((x-a), 2) + pow((y-b), 2) <= r*r;
}

int odc(int x1, int y1, int x2, int y2)
{
    return pow((x1-x2), 2) + pow((y1-y2), 2);
}

void z1()
{
    ofstream out1("wynik1.txt");
    int min_r = INT_MAX, ile = 0;
    for(int i=0; i<SIZE; i++)
        if(t[i][2] <= min_r)
        {
            min_r = t[i][2];
            r[i] = t[i][2];
        }
    for(int i=0; i<SIZE; i++)
        if(r[i] == min_r)
        {
            out1<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<endl;
            ile++;
        }
    out1<<"\nLiczba okregow o najkrotszym promieniu: "<<ile<<endl;
    out1.close();
}

void z2()
{
    ofstream out2("wynik2.txt");
    int global_max = 0, indeks, ile;
    for(int i=0; i<SIZE; i++)
    {
        ile = 0;
        for(int j=0; j<SIZE; j++)
        {
            if(i == j) continue;
            if(czyZawiera(t[i][0], t[i][1], t[i][2], t[j][0], t[j][1]))
                ile++;
        }
        if(ile > global_max)
        {
            global_max = ile;
            indeks = i;
        }
    }
    out2<<t[indeks][0]<<" "<<t[indeks][1]<<" "<<t[indeks][2]<<endl;
    out2<<global_max<<endl;
    out2.close();
}

void z3()
{
    ofstream out3("wynik3.txt");
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
        {
            if(i == j) continue;
            int d = odc(t[i][0], t[i][1], t[j][0], t[j][1]);
            if(d == pow((t[i][2]+t[j][2]), 2) || d == pow((t[i][2]-t[j][2]), 2))
                ile++;
        }
    out3<<ile<<endl;

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
        {
            if(i == j) continue;
            int d = odc(t[i][0], t[i][1], t[j][0], t[j][1]);
            if(d == pow((t[i][2]+t[j][2]), 2) || d == pow((t[i][2]-t[j][2]), 2))
            {
                out3<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<" ";
                out3<<t[j][0]<<" "<<t[j][1]<<" "<<t[j][2]<<endl;
            }

        }
    out3.close();
}

int main()
{
    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i][0] >> t[i][1] >> t[i][2];
    in.close();

    z1();
    z2();
    z3();

    return 0;
}
