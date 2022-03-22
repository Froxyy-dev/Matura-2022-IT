#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> plansza;
vector<string> pokolenie;

int main()
{
    ofstream out("wyniki_5.txt");
    string linia;
    ifstream in("gra.txt");
    for(int i=0; i<12; i++)
    {
        getline(in, linia);
        plansza.push_back(linia);
    }
    in.close();

    int zad1, zad2 = 0, zad3 = 0, zywi;
    for(int i=0; i<99; i++)
    {
        int zyjacy = 0;
        for(int y=0; y<12; y++)
        {
            string pom;
            for(int x=0; x<20; x++)
            {
                int sasiedzi = 0;
                int xD, yD, xG, yG;
                if(x == 0)
                    xD = 19;
                else
                    xD = x - 1;
                if(y == 0)
                    yD = 11;
                else
                    yD = y - 1;
                if(x == 19)
                    xG = 0;
                else
                    xG = x + 1;
                if(y == 11)
                    yG = 0;
                else
                    yG = y + 1;

                if(plansza[yD][x] == 'X')
                    sasiedzi++;
                if(plansza[yD][xD] == 'X')
                    sasiedzi++;
                if(plansza[yD][xG] == 'X')
                    sasiedzi++;
                if(plansza[y][xD] == 'X')
                    sasiedzi++;
                if(plansza[y][xG] == 'X')
                    sasiedzi++;
                if(plansza[yG][xD] == 'X')
                    sasiedzi++;
                if(plansza[yG][x] == 'X')
                    sasiedzi++;
                if(plansza[yG][xG] == 'X')
                    sasiedzi++;
                if(plansza[y][x] == 'X' && (sasiedzi == 2 || sasiedzi == 3))
                    pom += 'X';
                else if(plansza[y][x] == '.' && sasiedzi == 3)
                    pom += 'X';
                else
                    pom += '.';

                if(i == 36 && y == 1 && x == 18)
                    zad1 = sasiedzi;
                if(i == 1 && plansza[y][x] == 'X')
                    zad2 += 1;
                if(plansza[y][x] == 'X')
                    zyjacy++;
            }
            pokolenie.push_back(pom);
        }
        if(plansza == pokolenie && zad3 == 0)
        {
            zad3 = i+2;
            zywi = zyjacy;
        }

        plansza.clear();
        plansza = pokolenie;
        pokolenie.clear();
    }

    out<<"5.1\n"<<zad1;
    out<<"\n5.2\n"<<zad2;
    out<<"\n5.3\nPokolenie: "<<zad3;
    out<<"\nZywi: "<<zywi<<"\n";

    out.close();
    return 0;
}
