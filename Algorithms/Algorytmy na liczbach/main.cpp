#include <iostream>

using namespace std;

//Sprawdzanie czy liczba jest pierwsza
//************************************
bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}
//*************************************
//Sprawdzanie czy liczba jest doskonala
//*************************************
bool czyDoskonala(int n)
{
    int suma = 1;
    for(int i=2; i*i<=n; i++)
        if(n%i == 0)
        {
            suma += i;
            if(n/i != i)
                suma += n/i;
        }
    return (suma == n);
}
//****************************************
//Rozkladlanie liczby na czynniki pierwsze
//****************************************
void rozloz(int n)
{
    int k = 2;
    while(n > 1)
    {
        while(n%k == 0)
        {
            cout<<k<<" ";
            n/=k;
        }
        k++;
    }
}
//*****************************************
//Iteracyjna realizacja algorytmu Euklidesa
//*****************************************
int NWDi(int a, int b)
{
    int pom;
    while(b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }
    return a;
}
//*******************************************
//Rekurencyjna realizacja algorytmu Euklidesa
//*******************************************
int NWDr(int a, int b)
{
    if(b == 0) return a;
    if(b > 0) return NWDr(b, a%b);
}
//*************************************************
//Iteracyjne obliczanie wartosci liczb Fibonacciego
//*************************************************
int fib(int n)
{
    if(n == 0) return 0;
    int f1 = 1, f2 = 1;
    for(int i=3; i<=n; i++)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    return f2;
}
//*********************************
//Wydawanie reszty metoda zachlanna
//*********************************
void metodaZachlanna(int R)
{
    int T[6] = {500, 200, 100, 50, 20, 10}, k[6];
    for(int i=0; i<6; i++) k[i]=0;

    int i=0;
    while(R > 0)
    {
        k[i] = R/T[i];
        R%=T[i];
        i++;
    }
    for(int i=0; i<6; i++)
        if(k[i] != 0)
            cout<<T[i]<<" x "<<k[i]<<endl;
}
//******************************
//Szybkie podnoszenie do potegi
//******************************
long long szybkiePotega(int a, int n)
{
    long long w = 1;
    while(n > 0)
    {
        if(n%2 == 1)
            w*=a;
        a*=a;
        n/=2;
    }
    return w;
}
//*****************************************************
//Wyznaczanie miejsc zerowych funkcji metoda polowienia
//*****************************************************
double f(double x)
{
    return x*x -5*x +4;
}
double polowieniePrzedzialow(double a, double b, double epsilon)
{
    if(f(a) == 0) return a;
    if(f(b) == 0) return b;
    double srodek;
    while(b-a > epsilon)
    {
        srodek = (a+b) / 2;
        if(f(srodek) == 0.0) return srodek;
        if(f(a) * f(srodek) < 0)
            b = srodek;
        else
            a = srodek;
    }
    return (a+b) / 2;
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

    //Sprawdzanie czy liczba jest doskona³a
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

    //Iteracyjne obliczanie wartoœci liczb Fibonacciego
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
