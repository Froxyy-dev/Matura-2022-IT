#include <iostream>
#include <fstream>

using namespace std;

ofstream out("wynik4.txt");
const int SIZE = 50;
string s[SIZE][30];

void z1()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
    {
        int trawa = 0;
        for(int j=0; j<30; j++)
            for(auto const &c:s[i][j])
                if(c == '*')
                    trawa++;
        if(trawa >= 0.7*30*30)
            ile++;
    }
    out<<"4.1\n"<<ile<<endl;
}

void z2()
{
    out<<"\n4.2\n";
    for(int i=0; i<SIZE-1; i++)
    {
        for(int j=i+1; j<SIZE; j++)
        {
            bool ok = true;
            for(int w=0; w<30; w++)
            {
                if(!ok) break;
                for(int p=0; p<30; p++)
                {
                    if(s[i][w][p] != s[j][29-w][29-p])
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok)
                out<<i+1<<" "<<j+1<<endl;
        }
    }

}

int tab[SIZE];
void z3()
{
    out<<"\n4.3\n";
    int max_b = 0;
    for(int i=0; i<SIZE; i++)
    {
        for(int j=29; j>=0; j--)
        {
            bool ok = true;
            for(int b=j; b >=0; b--)
            {
                if(!ok) break;
                for(int c=0; c<=b; c++)
                    if(s[i][b][c] == 'X')
                    {
                        ok = false;
                        break;
                    }
                for(int c=0; c<=b; c++)
                    if(s[i][c][b] == 'X')
                    {
                        ok = false;
                        break;
                    }
            }
            if(ok)
                if(j+1 >= max_b)
                {
                    max_b = j+1;
                    tab[i] = j+1;
                    break;
                }
        }
    }
    out<<"Maksymalny bok: "<<max_b<<"\nDzialki: ";
    for(int i=0; i<SIZE; i++)
        if(tab[i] == max_b)
            out<<i+1<<" ";
}

int main()
{
    ifstream in("dzialki.txt");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<30; j++)
            in>>s[i][j];
    in.close();

    z1();
    z2();
    z3();
    out.close();
    return 0;
}
