#include <iostream>

using namespace std;

//**********************************
//Znajdowanie jednoczesnie min i max
//**********************************

//******************************************************************
//Wyznaczanie pierwiastka arytmetycznego - Metoda Newtona - Raphsona
//******************************************************************

//*****************************
//Schemat Hornera Rekurencyjnie
//*****************************

//***************************
//Schemat Hornera Iteracyjnie
//***************************

//***************
//Metoda Trapezów
//***************
double f(double x)
{
    return x*x + x + 2;
}

//******************
//Metoda prostokatow
//******************

//***************************************
//NWW - najmniejsza wspolna wielokrotnosc
//***************************************

//*****************
//Sito Eratostenesa
//*****************

//*******************
//Nierownosc trojkata
//*******************

//********************
//Wyszukiwanie binarne
//********************

//****************************
//Znajdowanie lidera w zbiorze
//****************************

//*************************************
//Przeszukiwanie liniowe z wartownikiem
//*************************************

//*************************************
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
