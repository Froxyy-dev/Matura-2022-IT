#include <iostream>

using namespace std;

//Sprawdzanie czy liczba jest pierwsza
//************************************

//*************************************
//Sprawdzanie czy liczba jest doskonala
//*************************************

//****************************************
//Rozkladlanie liczby na czynniki pierwsze
//****************************************

//*****************************************
//Iteracyjna realizacja algorytmu Euklidesa
//*****************************************

//*******************************************
//Rekurencyjna realizacja algorytmu Euklidesa
//*******************************************

//*************************************************
//Iteracyjne obliczanie wartosci liczb Fibonacciego
//*************************************************

//*********************************
//Wydawanie reszty metoda zachlanna
//*********************************

//******************************
//Szybkie podnoszenie do potegi
//******************************

//*****************************************************
//Wyznaczanie miejsc zerowych funkcji metoda polowienia
//*****************************************************
double f(double x)
{
    return x*x - 5*x + 4;
}

//*****************************************************
int main()
{

    //Sprawdzanie czy liczba jest pierwsza
    /*
    cout<<"Czy pierwsza 1: "<<czyPierwsza(1)<<endl;
    cout<<"Czy pierwsza 2: "<<czyPierwsza(2)<<endl;
    cout<<"Czy pierwsza 3: "<<czyPierwsza(3)<<endl;
    cout<<"Czy pierwsza 5: "<<czyPierwsza(5)<<endl;
    cout<<"Czy pierwsza 7: "<<czyPierwsza(7)<<endl;
    cout<<"Czy pierwsza 12: "<<czyPierwsza(12)<<endl;
    */

    //Sprawdzanie czy liczba jest doskonala
    /*
    cout<<"Czy doskonala 6: "<<czyDoskonala(6)<<endl;
    cout<<"Czy doskonala 28: "<<czyDoskonala(28)<<endl;
    cout<<"Czy doskonala 496: "<<czyDoskonala(496)<<endl;
    cout<<"Czy doskonala 8128: "<<czyDoskonala(8128)<<endl;
    cout<<"Czy doskonala 7: "<<czyDoskonala(7)<<endl;
    cout<<"Czy doskonala 12: "<<czyDoskonala(12)<<endl;
    */

    //Rozkladanie liczby na czynniki pierwsze
    /*
    cout<<"14 na czynniki pierwsze: "<<endl;
    rozloz(14);
    cout<<"\n1542 na czynniki pierwsze: "<<endl;
    rozloz(1542);
    cout<<"\n81 na czynniki pierwsze: "<<endl;
    rozloz(81);
    */

    //Iteracyjna realizacja algorytmu Euklidesa
    /*
    cout<<"NWD 2 i 8: "<<NWDi(2,8)<<endl;
    cout<<"NWD 10 i 5: "<<NWDi(10,5)<<endl;
    cout<<"NWD 7 i 4: "<<NWDi(7,4)<<endl;
    cout<<"NWD 11 i 87: "<<NWDi(11,87)<<endl;
    cout<<"NWD 88 i 168: "<<NWDi(88,168)<<endl;
    */

    //Rekurencyjna realizacja algorytmu Euklidesa
    /*
    cout<<"NWD 2 i 8: "<<NWDr(2,8)<<endl;
    cout<<"NWD 10 i 5: "<<NWDr(10,5)<<endl;
    cout<<"NWD 7 i 4: "<<NWDr(7,4)<<endl;
    cout<<"NWD 11 i 87: "<<NWDr(11,87)<<endl;
    cout<<"NWD 88 i 168: "<<NWDr(88,168)<<endl;
    */

    //Iteracyjne obliczanie wartosci liczb Fibonacciego
    /*
    cout<<"Fibonacci 0: "<<fib(0)<<endl;
    cout<<"Fibonacci 1: "<<fib(1)<<endl;
    cout<<"Fibonacci 2: "<<fib(2)<<endl;
    cout<<"Fibonacci 3: "<<fib(3)<<endl;
    cout<<"Fibonacci 4: "<<fib(4)<<endl;
    cout<<"Fibonacci 5: "<<fib(5)<<endl;
    cout<<"Fibonacci 6: "<<fib(6)<<endl;
    cout<<"Fibonacci 7: "<<fib(7)<<endl;
    cout<<"Fibonacci 8: "<<fib(8)<<endl;
    */

    //Wydawanie reszty metoda zachlanna
    /*
    cout<<"Reszta z 520:\n";
    metodaZachlanna(520);
    cout<<"Reszta z 1230:\n";
    metodaZachlanna(1230);
    cout<<"Reszta z 80:\n";
    metodaZachlanna(80);
    */

    //Szybkie podnoszenie do potegi
    /*
    cout<<"2 do 10: "<<szybkiePotega(2,10)<<endl;
    cout<<"3 do 5: "<<szybkiePotega(3,5)<<endl;
    cout<<"4 do 3: "<<szybkiePotega(4,3)<<endl;
    cout<<"10 do 4: "<<szybkiePotega(10,4)<<endl;
    */

    //Wyznaczanie miejsc zerowych funkcji metoda polowienia
    /*
    cout<<"f(x) = x^2 - 5*x + 4"<<endl;
    cout<<"x1 = "<<polowieniePrzedzialow(2.75, 6.878, 0.0001)<<endl;
    cout<<"x2 = "<<polowieniePrzedzialow(-2, 2.5, 0.0001);
    */

    return 0;
}
