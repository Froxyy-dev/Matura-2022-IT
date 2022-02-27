#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

const int SIZE = 1000;

string s[SIZE];

string sortuj(string s)
{
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    ifstream in("sygnaly.txt");
    ofstream out("wyniki4.txt");
    for(int i=0; i<SIZE; i++)
        in >> s[i];
    in.close();

    out<<"4.1"<<endl;
    for(int i=39; i<SIZE; i+=40)
        out<<s[i][9];

    out<<endl<<"\n4.2"<<endl;
    int ile, indeks=0, max_ilosc = -1;
    for(int i=0; i<SIZE; i++)
    {
        ile = 1;
        string wyraz = sortuj(s[i]);
        for(int j=1; j<wyraz.size(); j++)
        {
            if(wyraz[j] != wyraz[j-1])
                ile++;
        }


        if(ile > max_ilosc)
        {
            max_ilosc = ile;
            indeks = i;
        }
    }
    out<<s[indeks]<<" "<<max_ilosc<<endl;

    out<<endl<<"4.3"<<endl;
    bool ok;
    for(int i=0; i<SIZE; i++)
    {
        ok = true;
        for(int j=0; j < s[i].size(); j++)
        {
            for(int k=0; k < s[i].size(); k++)
                if(abs(s[i][j] - s[i][k]) > 10)
                {
                    ok = false;
                    break;
                }

        }
        if(ok)
            out<<s[i]<<endl;
    }

    out.close();
    return 0;
}
