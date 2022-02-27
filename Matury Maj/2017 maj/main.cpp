#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int t[200][320];
ofstream out("wyniki6.txt");

void z1()
{
    out<<"6.1"<<endl;

    int max_jasn=-1, min_jasn=256;
    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
        {
            if(t[i][j] > max_jasn)
                max_jasn = t[i][j];
            else if(t[i][j] < min_jasn)
                min_jasn = t[i][j];
        }
    out<<"Najjasniejszy piksel: "<<max_jasn<<endl<<"Najciemniejszy piksel: "<<min_jasn<<endl;
}

void z2()
{
    out<<endl<<"6.2\n";

    int ile_wierszy = 0;
    for(int i=0; i<200; i++)
    {
        int p=0, k=319;
        while(p<k)
        {
            if(t[i][p] != t[i][k])
            {
                ile_wierszy++;
                break;
            }
            k--;
            p++;
        }
    }
    out<<ile_wierszy<<endl;
}

void z3()
{
    out<<endl<<"6.3"<<endl;
    int ile=0;
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<320; j++)
        {
            if(j > 0 && (abs(t[i][j] - t[i][j-1]) > 128))
            {
                ile++;
                continue;
            }
            if(j < 319 && (abs(t[i][j] - t[i][j+1]) > 128))
            {
                ile++;
                continue;
            }
            if(i > 0 && (abs(t[i][j] - t[i-1][j]) > 128))
            {
                ile++;
                continue;
            }
            if(i < 199 && (abs(t[i][j] - t[i+1][j]) > 128))
            {
                ile++;
                continue;
            }
        }
    }
    out<<ile<<endl;
}

void z4()
{
    out<<endl<<"6.4\n";
    int dl, max_dl=0;
    for(int i=0; i<320; i++)
    {
        dl=1;
        for(int j=1; j<200; j++)
        {
            if(t[j][i] != t[j-1][i])
                dl=1;

            else
                dl++;
            if(dl>max_dl)
            {
                max_dl=dl;
            }

        }
    }
    out<<max_dl;
}

int main()
{
    ifstream in("dane.txt");
    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            in>>t[i][j];

    z1();
    z2();
    z3();
    z4();

    in.close();
    out.close();
    return 0;
}
