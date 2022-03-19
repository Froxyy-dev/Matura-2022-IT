#include <iostream>
#include <fstream>

using namespace std;

ofstream out("zadanie4.txt");
const int SIZE = 1000;
int plansza[20][20];
string ruchy[SIZE];

void z1()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
    {
        int x = 0, y = 0;
        for(int j=0; j<ruchy[i].size(); j++)
        {
            if(ruchy[i][j] == 'E')
                x++;
            if(ruchy[i][j] == 'W')
                x--;
            if(ruchy[i][j] == 'S')
                y++;
            if(ruchy[i][j] == 'N')
                y--;
            if(x < 0 || x > 19 || y < 0 || y > 19)
            {
                ile++;
                break;
            }
        }
    }

    out<<"4.1\nIlosc graczy zdyskwalifikowanych: "<<ile<<endl;
}

void z2()
{
    int max_punkty = 0, indeks;
    for(int i=0; i<SIZE; i++)
    {
        int punkty = plansza[0][0], x = 0, y = 0;
        for(int j=0; j<ruchy[i].size(); j++)
        {
            if(ruchy[i][j] == 'E')
                x++;
            if(ruchy[i][j] == 'W')
                x--;
            if(ruchy[i][j] == 'S')
                y++;
            if(ruchy[i][j] == 'N')
                y--;

            punkty += plansza[x][y];

            if(x < 0 || x > 19 || y < 0 || y > 19)
            {
                punkty = -1;
                break;
            }
        }
        if(punkty > max_punkty)
        {
            max_punkty = punkty;
            indeks = i + 1;
        }
    }
    out<<"\n4.2\nIlosc punktow: "<<max_punkty<<"\nNumer gracza: "<<indeks<<endl;
}

void z3()
{
    int gracze[SIZE] = {};
    int max_il = 0, il;
    for(int i=0; i<SIZE; i++)
    {
        int x = 0, y = 0, il = 0;

        for(int j=0; j<ruchy[i].size(); j++)
        {
            if(ruchy[i][j] == 'W' || ruchy[i][j] == 'E')
                    il++;
            else
                il = 0;

            if(il >= max_il)
            {
                max_il = il;
                gracze[i] = il;
            }
        }
    }
    out<<"\n4.3\nNajwieksza liczba ruchow W lub E: "<<max_il<<"\nGracze: \n";
    for(int i=0; i<SIZE; i++)
        if(gracze[i] == max_il)
            out<<i+1<<" ";
    out<<'\n';
}

int main()
{
    ifstream in("plansza.txt");
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            in >> plansza[i][j];
    in.close();

    ifstream in1("robot.txt");
    for(int i=0; i<SIZE; i++)
        in1 >> ruchy[i];
    in1.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
