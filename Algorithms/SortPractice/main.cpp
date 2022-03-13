#include <iostream>

using namespace std;

//********************
//Sortowanie babelkowe
//********************

//**********************
//Sortowanie przez wybor
//**********************

//***********************************
//Sortowanie przez wstawianie liniowe
//***********************************

//*************************
//Sortowanie przez scalanie
//*************************
int tab[20] = {123, 213, 4, 5, 6, 2, 1, 5, 79, 432, 1, 213, 22, 34, 81, 19, 76, 4, 27, 20}, tmp[20] = {};

//******************
//Sortowanie szybkie
//******************

//********************
//Sortowanie kubelkowe
//********************

//********************
int main()
{
    int T[20] = {123, 213, 4, 5, 6, 2, 1, 5, 79, 432, 1, 213, 22, 34, 81, 19, 76, 4, 27, 20};
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
