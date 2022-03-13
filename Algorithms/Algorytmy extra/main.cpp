#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//**********************************
//Znajdowanie jednoczesnie min i max
//**********************************
void szukaj(int tab[], int n, int &MAX, int &MIN)
{
    int i = 2;
    if(n >= 2)
    {
        if(tab[0] > tab[1])
        {
            MAX = tab[0];
            MIN = tab[1];
        }
        else
        {
            MAX = tab[1];
            MIN = tab[0];
        }
        while(i+2 <= n)
        {
            if(tab[i] > tab[i+1])
            {
                if(tab[i] > MAX)
                    MAX = tab[i];
                if(tab[i+1] < MIN)
                    MIN = tab[i+1];
            }
            else
            {
                if(tab[i+1] > MAX)
                    MAX = tab[i+1];
                if(tab[i] < MIN)
                    MIN = tab[i];
            }
            i += 2;
        }
        if(n%2 == 1)
        {
            if(tab[i] > MAX)
                MAX = tab[i];
            if(tab[i] < MIN)
                MIN = tab[i];
        }
    }
    else
    {
        MIN = MAX = tab[0];
    }
}
//******************************************************************
//Wyznaczanie pierwiastka arytmetycznego - Metoda Newtona - Raphsona
//******************************************************************
double pierwiastek(double Pole, double epsilon)
{
    double a = 1., b = Pole;
    while(fabs(a-b) >= epsilon)
    {
        a = (a+b)/2.;
        b = Pole/a;
    }
    return a;
}
//*****************************
//Schemat Hornera Rekurencyjnie
//*****************************
double HornerR(int wsp[], int st, double x)
{
    if(st == 0)
        return wsp[0];
    return x*HornerR(wsp, st-1, x) + wsp[st];
}
//***************************
//Schemat Hornera Iteracyjnie
//***************************
double HornerI(int wsp[], int st, double x)
{
    double wynik = wsp[0];
    for(int i=1; i<=st; i++)
        wynik = wynik*x + wsp[i];
    return wynik;
}
//***************
//Metoda Trapezów
//***************
double f(double x)
{
    return x*x + x + 2;
}
double metodaTrapezow(double a, double b, int n)
{
    double h = (b-a)/(double)n;
    double S = 0.0;
    double podstawa_a = f(a), podstawa_b;

    for(int i=1; i<=n; i++)
    {
        podstawa_b = f(a+h*i);
        S += (podstawa_a + podstawa_b);
        podstawa_a = podstawa_b;
    }
    return S*0.5*h;
}
//******************
//Metoda prostokatow
//******************
double metodaProstokatow(int a, int b, int n)
{
    double x = (b-a)/(double)n;
    double S = 0.0;
    double srodek = a + (b-a)/(2.0*n);

    for(int i=0; i<n; i++)
    {
        S += f(srodek);
        srodek += x;
    }
    return S*x;
}
//***************************************
//NWW - najmniejsza wspolna wielokrotnosc
//***************************************
int NWD(int a, int b)
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
int NWW(int a, int b)
{
    return a*b/NWD(a,b);
}
//*****************
//Sito Eratostenesa
//*****************
void sito(bool *tab, int n)
{
    for(int i=2; i*i<=n; i++)
        if(!tab[i])
            for(int j=i*i; j<=n; j+=i)
                tab[j] = 1;
}
//*******************
//Nierownosc trojkata
//*******************
bool trojkat(int a, int b, int c)
{
    return a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a;
}
//********************
//Wyszukiwanie binarne
//********************
int wyszukiwanie(int tab[], int l, int p, int szukana)
{
    int sr;
    while(l <= p)
    {
        sr = (l + p)/ 2;
        if(tab[sr] == szukana)
            return sr;
        if(tab[sr] > szukana)
            p = sr - 1;
        else
            l = sr + 1;
    }
    return -1;
}
//****************************
//Znajdowanie lidera w zbiorze
//****************************
int szukajLidera(int tab[], int n)
{
    int lider = tab[0], do_pary = 1;
    for(int i=1; i<n; i++)
        if(do_pary > 0)
        {
            if(tab[i] == lider)
                do_pary++;
            else
                do_pary--;
        }
        else
        {
            do_pary++;
            lider = tab[i];
        }

    if(do_pary == 0)
        return -1;

    int ile = 0;
    for(int i=0; i<n; i++)
        if(tab[i] == lider)
            ile++;
    if(ile > n/2)
        return lider;
    return -1;
}
//*************************************
//Przeszukiwanie liniowe z wartownikiem
//*************************************
void wartownik(int tab[], int szukana)
{
    int i=0;
    while(tab[i] != szukana && tab[i] != -1) ++i;
    if(tab[i] == -1)
        cout<<"Szukany element nie wystepuje w tablicy"<<endl;
    else
        cout<<"Liczba "<<szukana<<" znajduje sie na "<<i+1<<endl;
}
//*******************************************
//Sprawdzenie, czy dwa odcinki sie przecinaja
//*******************************************

//******************************
//Rozszerzony Algorytm Euklidesa
//******************************


int main()
{
    int tab[10] = {1002, 213, 3213, 302, 80, 53, 723, 678, 31, 60}, n = 10, MIN, MAX;
    int wsp[4] = {1, 2, -1, 4};
    const double epsilon = 0.000001;

    //**********************************
    //Znajdowanie jednoczesnie min i max
    //**********************************
    /*
    szukaj(tab, n, MAX, MIN);
    cout<<"MIN: "<<MIN<<"\nMAX: "<<MAX<<endl;
    */

    //******************************************************************
    //Wyznaczanie pierwiastka arytmetycznego - Metoda Newtona - Raphsona
    //******************************************************************
    /*
    cout<<"Pierwiastek z 3: "<<fixed<<pierwiastek(3, epsilon)<<endl;
    cout<<"Pierwiastek z 20: "<<fixed<<pierwiastek(20, epsilon)<<endl;
    cout<<"Pierwiastek z 64: "<<fixed<<pierwiastek(64, epsilon)<<endl;
    */

    //*****************************
    //Schemat Hornera Rekurencyjnie
    //*****************************
    /*
    cout<<"Schemat Hornera Rekurencyjnie\n";
    cout<<"f(x) = x^3 + 2*x^2 - x + 4\nf(2) = "<<HornerR(wsp, 3, 2)<<'\n';
    */

    //***************************
    //Schemat Hornera Iteracyjnie
    //***************************
    /*
    cout<<"Schemat Hornera Iteracyjnie\n";
    cout<<"f(x) = x^3 + 2*x^2 - x + 4\nf(2) = "<<HornerI(wsp, 3, 2)<<'\n';
    */

    //***************
    //Metoda trapezów
    //***************
    /*
    cout<<"Metoda trapezow:\n\n";
    cout<<"f(x) = x*x + x + 2\n(funkcja zawsze przyjmuje wartosci dodatnie,\nwiec mozna pominac wartosc bezwzglenda)\n";
    cout<<"\nPole figury wynosi: "<<fixed<<setprecision(2)<<metodaTrapezow(1, 4, 100)<<'\n';
    */

    //******************
    //Metoda prostokatow
    //******************
    /*
    cout<<"Metoda prostokatow:\n\n";
    cout<<"f(x) = x*x + x + 2\n(funkcja zawsze przyjmuje wartosci dodatnie,\nwiec mozna pominac wartosc bezwzglenda)\n";
    cout<<"\nPole figury wynosi: "<<fixed<<setprecision(2)<<metodaProstokatow(1, 4, 100)<<'\n';
    */

    //***************************************
    //NWW - najmniejsza wspolna wielokrotnosc
    //***************************************
    /*
    cout<<"Najmniejsza wspolna wielokrotnosc (NWW) dla:\n";
    cout<<"a = 4, b = 6: "<<NWW(6, 4)<<'\n';
    cout<<"a = 7, b = 425: "<<NWW(7, 425)<<'\n';
    cout<<"a = 75, b = 5: "<<NWW(75, 5)<<'\n';
    */

    //*****************
    //Sito Eratostenesa
    //*****************
    /*
    int przedzial = 100;
    bool *tablica = new bool[przedzial+1];
    tablica[0] = 1;
    tablica[1] = 1;
    for(int i=2; i<=przedzial; i++)
        tablica[i] = 0;

    sito(tablica, przedzial);
    cout<<"Sito Eratostenesa: \n";
    for(int i=0; i<=przedzial; i++)
        if(!tablica[i])
            cout<<i<<'\n';
    delete[] tablica;
    */

    //*******************
    //Nierownosc trojkata
    //*******************
    /*
    int a, b, c;
  	cout<<"Podaj trzy liczby calkowite: ";
    cin>>a>>b>>c;
    if(trojkat(a, b, c))
 		cout<<"Z podanych odcinkow mozna zbudowac trojkat.\n";
 	else
 		cout<<"Z podanych odcinkow nie mozna zbudowac trojkata.\n";
    */

    //********************
    //Wyszukiwanie binarne
    //********************
    /*
    int posortowane[10] = {1, 10, 23, 76, 93, 118, 412, 723, 1002, 3412};
    cout<<"Wyszukiwanie binarne dla: \nTablica: posortowane[10] = {1, 10, 23, 76, 93, 118, 412, 723, 1002, 3412}\n";
    cout<<"- Szukana = 1002 : "<<wyszukiwanie(posortowane, 0, 10, 1002)<<'\n';
    cout<<"- Szukana = 76 : "<<wyszukiwanie(posortowane, 0, 9, 76)<<'\n';
    cout<<"- Szukana = 56 : "<<wyszukiwanie(posortowane, 0, 9, 56)<<'\n';
    */

    //****************************
    //Znajdowanie lidera w zbiorze
    //****************************
    /*
    int tab_lider[7] = {2, 1, 1, 3, 2, 2, 2};
    int lider = szukajLidera(tab_lider, 7);
    cout<<"Liderem zbioru jest: "<<lider<<endl;
    */

    //*************************************
    //Przeszukiwanie liniowe z wartownikiem
    //*************************************
    /*
    int wart[10] = {54, 31, 42, 38, 9, 8, 2 , 9, 9, -1};
    cout<<"Szukam 8: \n";
    wartownik(wart, 8);
    cout<<endl;
    cout<<"Szukam 2: \n";
    wartownik(wart, 2);
    cout<<endl;
    cout<<"Szukam 10: \n";
    wartownik(wart, 10);
    cout<<endl;
    */

    return 0;
}
