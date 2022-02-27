#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 1000;
string l[SIZE];
ofstream out("wynik4.txt");

bool mniejsza(string a, string b)
{
    int m = a.size(), n = b.size();
    if(m < n) return true;
    if(m > n) return false;

    for(int i=0; i< m; i++)
    {
        if(a[i] < b[i])
            return true;
        if(a[i] > b[i])
            return false;
    }
    return false;
}


void z1()
{
    int ile_liczb=0;
    for(int i=0; i<SIZE; i++)
    {
        int dl = l[i].size(), ile=0;
        for(int j=0; j<dl; j++)
            if(l[i][j] == '0')
                ile++;

        if(2*ile > dl)
            ile_liczb++;
    }
    out<<"4.1\n"<<ile_liczb<<endl;
}

void z2()
{
    int przez_2 = 0, przez_8 = 0;
    for(int i=0; i<SIZE; i++)
    {

        int dl = l[i].size();
        if(l[i][dl-1] == '0')
            przez_2++;
        if(dl < 4)
            continue;
        if(l[i][dl-1] == '0' && l[i][dl-2] == '0' && l[i][dl-3] == '0')
            przez_8++;
    }
    out<<"4.2\nPodzielne przez 2: "<<przez_2<<endl<<"Podzielne przez 8: "<<przez_8<<endl;

}

void z3()
{
    int i_najmniejsza = 0, i_najwieksza = 0;
    string max_liczba = l[0], min_liczba = l[0];

    for(int i=1; i<SIZE; i++)
    {
        if(!mniejsza(l[i], max_liczba))
        {
            max_liczba = l[i];
            i_najwieksza = i;
        }
        if(mniejsza(l[i], min_liczba))
        {
            min_liczba = l[i];
            i_najmniejsza = i;
        }
    }
    out<<"4.3\nIndeks najmniejszej: "<<i_najmniejsza+1<<"\nIndeks najwiekszej: "<<i_najwieksza+1<<endl;


}


int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> l[i];
    in.close();

    z1();
    z2();
    z3();
    out.close();
    return 0;
}
