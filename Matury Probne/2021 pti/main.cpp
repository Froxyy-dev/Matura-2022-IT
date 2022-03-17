#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out1("znajomi_1_wynik.txt");
    ofstream out2("znajomi_2_wynik.txt");
    ifstream in1("znajomi_1.txt");
    ifstream in2("znajomi_2.txt");
    int n, t, q;
    in1 >> n;

    int *tab = new int[n];
    for(int i=0; i<n; i++) tab[i] = 0;

    int znajomosci[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            znajomosci[i][j] = 0;

    //Wczytywanie wierszy
    for(int i=0; i<n; i++)
    {
        in1 >> t;
        for(int j=0; j<t; j++)
        {
            in1 >> q;
            znajomosci[i][q] = 1;
            tab[q] = 1;
        }
    }
    in1.close();
    //Sprawdzanie czy ktos wskazal znajomosc
    for(int i=0; i<n; i++)
        if(!tab[i])
            out1<<i<<" ";
    out1<<endl;

    //Wypisanie par z wykorzystaniem flagi "odwiedzanych" dotychczas osob
    bool visited[n] = {};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(znajomosci[i][j] && znajomosci[j][i] && !visited[i] && !visited[j])
                out1<<i<<" "<<j<<endl;
        }
        visited[i] = 1;
    }

    out1.close();
    delete [] tab;

    in2 >> n;
    int *tab1 = new int[n];
    for(int i=0; i<n; i++) tab1[i] = 0;

    int znajomosci1[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            znajomosci1[i][j] = 0;

    //Wczytywanie wierszy
    for(int i=0; i<n; i++)
    {
        in2 >> t;
        for(int j=0; j<t; j++)
        {
            in2 >> q;
            znajomosci1[i][q] = 1;
            tab1[q] = 1;
        }
    }
    in2.close();


    //Sprawdzanie czy ktos wskazal znajomosc
    for(int i=0; i<n; i++)
        if(!tab1[i])
            out2<<i<<" ";
    out2<<endl<<endl;

    //Wypisanie par z wykorzystaniem flagi "odwiedzanych" dotychczas osob
    bool visited1[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(znajomosci1[i][j] && znajomosci1[j][i] && !visited1[i] && !visited1[j])
                out2<<i<<" "<<j<<endl;
        }
        visited1[i] = 1;
    }

    out2.close();


    return 0;
}
