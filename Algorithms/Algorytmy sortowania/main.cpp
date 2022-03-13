#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//********************
//Sortowanie babelkowe
//********************
void babelkowe(int tab[], int n)
{
    int pom;
    for(int i=n-1; i>=1; i--)
        for(int j=0; j<i; j++)
            if(tab[j] > tab[j+1])
                {
                    pom = tab[j+1];
                    tab[j+1] = tab[j];
                    tab[j] = pom;
                }

    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
}
//**********************
//Sortowanie przez wybor
//**********************
void wybor(int tab[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int najmniejszy = i;
        for(int j=i+1; j<n; j++)
            if(tab[j] < tab[najmniejszy])
                najmniejszy = j;
        swap(tab[i], tab[najmniejszy]);
    }

    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";
}
//***********************************
//Sortowanie przez wstawianie liniowe
//***********************************
void wstawianie(int tab[], int n)
{
    for(int i=1; i<n; i++)
        for(int j=i-1; j>=0; j--)
            if(tab[j+1] < tab[j])
                swap(tab[j+1], tab[j]);
            else
                break;

    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";
}
//*************************
//Sortowanie przez scalanie
//*************************
int tab[20] = {123, 213, 4, 5, 6, 2, 1, 5, 79, 432, 1, 213, 22, 34, 81, 19, 76, 4, 27, 20}, tmp[20] = {};
void sortujScalanie(int p, int k)
{
    int sr, i1, i2;
    if(p < k)
    {
        sr = (p+k)/2;
        sortujScalanie(p, sr);
        sortujScalanie(sr+1, k);
        i1=p;
        i2=sr+1;
        for(int i=p; i<=k; i++)
            if(i1 > sr || (i2 <= k && tab[i2] < tab[i1]))
                tmp[i] = tab[i2++];
            else
                tmp[i] = tab[i1++];

        for(int i=p; i<=k; i++) tab[i] =tmp[i];
    }
}
//******************
//Sortowanie szybkie
//******************
void szybkie(int lewy, int prawy)
{
    if(prawy <= lewy) return;
    int i=lewy, j=prawy, pivot=tab[(lewy+prawy)/2];
    do
    {
        while(tab[i] < pivot)
            i++;
        while(tab[j] > pivot)
            j--;
        if(i <= j)
            swap(tab[i++], tab[j--]);

    } while(i <= j);
    if(lewy < j) szybkie(lewy, j);
    if(i < prawy) szybkie(i, prawy);
}
//********************
//Sortowanie kubelkowe
//********************
void sortujKub(int tab[], int n)
{
    vector<int> kubelki[20];
    int p = 500/n;

    for(int i=0; i<n; i++)
        kubelki[tab[i]/p].push_back(tab[i]);
    for(int i=0; i<n; i++)
        if(kubelki[i].size() > 1)
            sort(kubelki[i].begin(), kubelki[i].end());
    for(int i=0; i<n; i++)
        for(int j=0; j<kubelki[i].size(); j++)
            cout<<kubelki[i][j]<<" ";
}

int main()
{
    int T[20] = {123, 213, 4, 5, 6, 2, 1, 5, 79, 432, 1, 213, 22, 34, 81, 19, 76, 4, 27, 20};
    int tmp[20] = {0};
    //Sortowanie babelkowe
    /*
    cout<<"Sortowanie babelkowe:\n";
    babelkowe(T, 20);
    */

    //Sortowanie przez wybor
    /*
    cout<<"Sortowanie przez wybor:\n";
    wybor(T, 20);
    */

    //Sortowanie przez wstawianie liniowe
    /*
    cout<<"Sortowanie przez wstawianie liniowe:\n";
    wstawianie(T, 20);
    */

    //Sortowanie przez scalanie
    /*
    cout<<"Sortowanie przez scalanie:\n";
    sortujScalanie(0, 19);
    for(int i=0; i<20; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
    */

    //Sortowanie szybkie
    /*
    cout<<"Sortowanie szybkie:\n";
    szybkie(0, 19);
    for(int i=0; i<20; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
    */

    //Sortowanie kubelkowe
    /*
    cout<<"Sortowanie kubelkowe:\n";
    sortujKub(T,20);
    cout<<endl;
    */
    return 0;
}
