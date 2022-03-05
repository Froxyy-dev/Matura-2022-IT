#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

ofstream out("zadanie1.txt");
const int SIZE = 125;
string plansza[SIZE][8];

void z1()
{
    int ile = 0, global_max = 0, temp;
    for(int i=0; i<SIZE; i++)
    {
        temp = 0;
        for(int w=0; w<8; w++)
        {
            bool ok = true;
            for(int k=0;k<8; k++)
            {
                if(plansza[i][k][w] != '.')
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
                temp++;
        }
        if(temp > 0)
        {
            ile++;
            if(temp > global_max)
                global_max = temp;
        }
    }
    out<<"1.1\n"<<ile<<" "<<global_max<<endl;

}

void z2()
{
    int ile = 0, global_min = 65, temp;
    for(int i=0; i<SIZE; i++)
    {
        temp = 0;
        bool ok = true;
        map<char, int> biale;
        map<char, int> czarne;
        for(int k=0; k<8; k++)
        {
            for(int w=0; w<8; w++)
            {
                if(plansza[i][k][w] == '.')
                    continue;
                if(plansza[i][k][w] >= 'A' && plansza[i][k][w] <= 'Z')
                {
                    char c = char(tolower(plansza[i][k][w]));
                    biale[c] = (biale.find(c) == biale.end()) ? 1 : biale[c] + 1;
                }
                else
                {
                    char c = plansza[i][k][w];
                    czarne[c] = (czarne.find(c) == czarne.end()) ? 1 : czarne[c] + 1;
                }
            }
        }
        if(czarne.size() != biale.size())
            ok = false;
        else
        {
            for(auto itr = biale.begin(); itr != biale.end(); itr++)
            {
                if(czarne.find(itr->first) == czarne.end() || czarne[itr->first] != itr->second)
                {
                    ok = false;
                    break;
                }
                temp += itr->second * 2;
            }
        }
        if(ok)
        {
            ile++;
            if(temp < global_min)
                global_min = temp;
        }
    }

    out<<"\n1.2\n"<<ile<<" "<<global_min<<endl;
}

void z3()
{
    int ileB = 0, ileC = 0;
    for(int i=0; i<SIZE; i++)
    {
        int wB, kB, wC, kC;
        for(int k=0; k<8; k++)
        {
            for(int w=0; w<8; w++)
            {
                if(plansza[i][k][w] == 'k')
                {
                    wC = w;
                    kC = k;
                }
                if(plansza[i][k][w] == 'K')
                {
                    wB = w;
                    kB = k;
                }
            }
        }

        for(int k=0; k<8; k++)
        {
            for(int w=0; w<8; w++)
            {
                if(plansza[i][k][w] == 'w')
                {
                    if(k == kB)
                    {
                        if(abs(w-wB) == 1)ileC++;
                        string pom;
                        if(w < wB)
                            pom = plansza[i][k].substr(w+1, wB-w-1);
                        else
                            pom = plansza[i][k].substr(wB+1, w-wB-1);
                        if(pom != "")
                        {
                            bool ok = true;
                            for(int i=0; i<pom.size(); i++)
                                if(pom[i] != '.')
                                {
                                    ok = false;
                                    break;
                                }
                            if(ok)
                                ileC++;
                        }
                    }
                    else if(w == wB)
                    {
                        string pom;
                        if(abs(k-kB) == 1)ileC++;
                        if(k < kB)
                        {
                            for(int a=k+1; a<kB; a++)
                            pom += plansza[i][a][w];
                        }
                        else
                        {
                            for(int a=kB+1; a<k; a++)
                            pom += plansza[i][a][w];
                        }
                        if(pom != "")
                        {
                            bool ok = true;
                            for(int i=0; i<pom.size(); i++)
                                if(pom[i] != '.')
                                {
                                    ok = false;
                                    break;
                                }
                            if(ok)
                                ileC++;
                        }
                    }
                }
                if(plansza[i][k][w] == 'W')
                {
                    if(k == kC)
                    {
                        if(abs(w-wC) == 1)ileB++;
                        string pom;
                        if(w < wC)
                            pom = plansza[i][k].substr(w+1, wC-w-1);
                        else
                            pom = plansza[i][k].substr(wC+1, w-wC-1);
                        if(pom != "")
                        {
                            bool ok = true;
                            for(int i=0; i<pom.size(); i++)
                                if(pom[i] != '.')
                                {
                                    ok = false;
                                    break;
                                }
                            if(ok)
                                ileB++;
                        }
                    }
                    else if(w == wC)
                    {
                        if(abs(k-kC) == 1)ileB++;
                        string pom;
                        if(k < kC)
                        {
                            for(int a=k+1; a<kC; a++)
                            pom += plansza[i][a][w];
                        }
                        else
                        {
                            for(int a=kC+1; a<k; a++)
                            pom += plansza[i][a][w];
                        }
                        if(pom != "")
                        {
                            bool ok = true;
                            for(int i=0; i<pom.size(); i++)
                                if(pom[i] != '.')
                                {
                                    ok = false;
                                    break;
                                }
                            if(ok)
                                ileB++;
                        }
                    }

                }
            }
        }
    }
    out<<"\n1.3\n"<<ileB<<" "<<ileC;
}

int main()
{
    string spacja;
    ifstream in("szachy.txt");
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<8; j++)
            getline(in, plansza[i][j]);
        getline(in, spacja);
    }
    in.close();

    z1();
    z2();
    z3();

    out.close();
    return 0;
}
