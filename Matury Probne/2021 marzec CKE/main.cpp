#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

ofstream out1("wynik4_1.txt");
ofstream out2a("wynik4_2a.txt");
ofstream out2b("wynik4_2b.txt");
ofstream out3("wynik4_3.txt");
const int SIZE = 50;
string kod[SIZE], miasto[SIZE];
int pary[SIZE][70][2];

void z1()
{
    unordered_map<string, int> mp;
    for(int i=0; i<SIZE; i++)
        mp[kod[i]] = (mp.find(kod[i]) == mp.end()) ? 1 : mp[kod[i]] + 1;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
        out1<<itr->first<<" "<<itr->second<<endl;
}

void z2()
{
    int global_max = 0, indeks_max, global_min = 9999999, indeks_min;
    for(int i=0; i<SIZE; i++)
    {
        int suma = 0, ile = 0;
        for(int j=0; j<70; j++)
        {
            if(pary[i][j][0] != 0)
            {
                suma += (pary[i][j][0] * pary[i][j][1]);
                ile++;
            }

        }
        if(suma > global_max)
        {
            global_max = suma;
            indeks_max = i;
        }
        if(suma < global_min)
        {
            global_min = suma;
            indeks_min = i;
        }

        out2a<<miasto[i]<<" "<<suma<<" "<<ile<<endl;

    }
    out2b<<miasto[indeks_max]<<" "<<global_max<<endl;
    out2b<<miasto[indeks_min]<<" "<<global_min<<endl;

}

void z3()
{
    int global_max = 0, indeks_max, global_min = 71, indeks_min;
    for(int i=0; i<SIZE; i++)
    {
        set<int> rozne;
        int powierzchnia;
        for(int j=0; j<70; j++)
        {
            powierzchnia = pary[i][j][0] * pary[i][j][1];
            if(powierzchnia != 0)
                rozne.insert(powierzchnia);
        }
        if(rozne.size() > global_max)
        {
            global_max = rozne.size();
            indeks_max = i;
        }
        if(rozne.size() < global_min)
        {
            global_min = rozne.size();
            indeks_min = i;
        }
    }
    out3<<miasto[indeks_max]<<" "<<global_max<<endl;
    out3<<miasto[indeks_min]<<" "<<global_min<<endl;
}

int main()
{
    ifstream in("galerie.txt");
    for(int i=0; i<SIZE; i++)
    {
        in >> kod[i] >> miasto[i];
        for(int j=0; j<70; j++)
            in>>pary[i][j][0]>>pary[i][j][1];
    }
    in.close();

    z1();
    z2();
    z3();

    out1.close();
    out2a.close();
    out2b.close();
    out3.close();

    return 0;
}
