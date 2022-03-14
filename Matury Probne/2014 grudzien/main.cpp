#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wynik5.txt");
const int SIZE = 310;
int t[SIZE];

void z1()
{
    int ile = 0, dl=1;
    for(int i=1; i<SIZE; i++)
    {
        if(t[i] > t[i-1])
            dl++;
        else
        {
            if(dl > 3)
                ile++;
            dl = 1;
        }
    }
    out<<"5.1\n"<<ile<<'\n';
}

void z2()
{
    int dl_max = 0, dl_min = INT_MAX, i_min, i_max;
    for(int i=0; i<SIZE; i++)
    {
        if(t[i] > dl_max)
        {
            dl_max = t[i];
            i_max = i;
        }
        if(t[i] < dl_min)
        {
            dl_min = t[i];
            i_min = i;
        }
    }
    out<<"\n5.2\nDlugosc najdluzszego skoku: "<<dl_max<<" , wynik nr: "<<i_max + 1<<'\n';
    out<<"Dlugosc najkrotszego skoku: "<<dl_min<<" , wynik nr: "<<i_min + 1<<'\n';
}

void z3()
{
    int max_dl = 0, dl = 1, oIle;
    for(int i=0; i<SIZE; i++)
    {
        if(t[i] > t[i-1])
            dl++;
        else
            dl = 1;
        if(dl > max_dl)
            {
                max_dl = dl;
                oIle = t[i] - t[i-dl+1];
            }
    }
    out<<"\n5.3\nDlugosc: "<<max_dl<<"\nO ile centymetrow: "<<oIle<<endl;
}

int main()
{
    ifstream in("dziennik.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
