#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ofstream out("wyniki6.txt");
const int SIZE = 2000;
pair<string, char> pary[SIZE];

int main()
{
    ifstream in("instrukcje.txt");
    for(int i=0; i<SIZE; i++)
        in>> pary[i].first >> pary[i].second;
    in.close();

    //utworzenie koncowego napisu
    string napis = "";
    for(int i=0; i<SIZE; i++)
    {
        if(pary[i].first == "DOPISZ")
            napis += pary[i].second;
        if(pary[i].first == "ZMIEN")
        {
             napis[napis.size()-1] = pary[i].second;
        }
        if(pary[i].first == "USUN")
            napis.pop_back();
        if(pary[i].first == "PRZESUN")
        {
            for(int j=0; j<napis.size(); j++)
                if(napis[j] == pary[i].second)
                {
                    if(napis[j] == 'Z')
                        napis[j] = 'A';
                    else
                        napis[j] += 1;
                    break;
                }
        }
    }

    //Zadanie 4.1
    out<<"4.1\n"<<napis.size()<<'\n';

    //Zadanie 4.2
    int dl = 1, max_dl = 0;
    string instrukcja;
    for(int i=1; i<SIZE; i++)
    {
        if(pary[i].first != pary[i-1].first)
            dl = 1;
        else
            dl++;
        if(dl > max_dl)
        {
            max_dl = dl;
            instrukcja = pary[i-1].first;
        }
    }
    out<<"\n4.2\nRodzaj instrukcji - "<<instrukcja<<"\nDlugosc ciagu - "<<max_dl<<'\n';

    //Zadanie 4.3
    map<char, int> litery;
    for(int i=0; i<SIZE; i++)
        if(pary[i].first == "DOPISZ")
        {
            char c = pary[i].second;
            litery[c] = (litery.find(c) == litery.end()) ? 1 : litery[c] + 1;
        }
    int ilosc_max = 0;
    char litera;
    for(auto itr = litery.begin(); itr != litery.end(); ++itr)
        if(itr->second > ilosc_max)
        {
            ilosc_max = itr->second;
            litera = itr->first;
        }
    out<<"\n4.3\nNajczesciej dopisywana litera: "<<litera<<"\nIlosc dopisan: "<<ilosc_max<<'\n';

    //Zadanie 4.4
    out<<"\n4.4\n"<<napis;

    out.close();
    return 0;
}
