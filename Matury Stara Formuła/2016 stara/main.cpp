#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int SIZE = 12;
vector<string> plansza, pokolenie;

int zwroc_x(int n)
{
    if(n < 0)
        return 19;
    if(n > 19)
        return 0;
    return n;
}

int zwroc_y(int n)
{
    if(n < 0)
        return 11;
    if(n > 11)
        return 0;
    return n;
}

int main()
{
    ifstream in("gra.txt");
    string tekst;
    for(int i=0; i<SIZE; i++)
    {
        getline(in, tekst);
        plansza.push_back(tekst);
    }
    in.close();

    int zad1, zad2, zad3 = 0;
    pokolenie = plansza;
    for(int i=0; i<100; i++)
    {
        int zywe = 0;
        for(int j=0; j<plansza.size(); j++)
        {
            for(int a=0; a<plansza[j].size(); a++)
            {
                int sasiedzi=0;
                int x,y;
                x = zwroc_x(a-1);
                y = zwroc_y(j+1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a-1);
                y = zwroc_y(j);

                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a-1);
                y = zwroc_y(j-1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a);
                y = zwroc_y(j+1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a);
                y = zwroc_y(j-1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a+1);
                y = zwroc_y(j+1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a+1);
                y = zwroc_y(j);
                if(plansza[y][x] == 'X')
                    sasiedzi++;

                x = zwroc_x(a+1);
                y = zwroc_y(j-1);
                if(plansza[y][x] == 'X')
                    sasiedzi++;



                if(plansza[j][a] == 'X' && (sasiedzi == 2 || sasiedzi == 3))
                {
                    pokolenie[j][a] = 'X';
                    zywe++;
                }

                else if(plansza[j][a] == '.' && sasiedzi == 3)
                {
                    pokolenie[j][a] = 'X';
                    zywe++;
                }
                else
                pokolenie[j][a] = '.';
                if(i == 36 && j == 1 && a == 18)
                    zad1 = sasiedzi;

            }
        }
        if(i == 0)
            zad2 = zywe;
        if(!zad3 && plansza == pokolenie)
        {
            zad3 = i+2;
        }

        plansza = pokolenie;

        pokolenie = plansza;
    }
    cout<<"5.1\n"<<zad1;
    cout<<"\n5.2\n"<<zad2;
    cout<<"\n5.3\n"<<zad3;
    return 0;
}
