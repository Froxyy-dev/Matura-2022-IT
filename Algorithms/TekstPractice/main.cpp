#include <iostream>

using namespace std;

//**************************************************
//Sprawdzanie, czy dany ciag znakow tworzy palindrom
//**************************************************

//************************************************
//Sprawdzanie, czy dany ciag znakow tworzy anagram
//************************************************

//**************************
//Porzadkowanie alfabetyczne
//**************************

//*****************************
//Wyszukiwanie wzorca w tekscie
//*****************************

//************
//Szyfr Cezara
//************

//*********************
//Szyfr przestawieniowy
//*********************

//***************************************
//Przesuniecie spolglosek o jedno miejsce
//***************************************

//***************************************
int main()
{
    string s[5] = {"Adam", "Marek", "Jozef", "Roman", "Marcin"};
    //Sprawdzanie, czy dany ciag znakow tworzy palindrom
    /*
    cout<<"Palindrom ABBA: "<<czyPalindrom("ABBA")<<endl;
    cout<<"Palindrom atokanapapanakota: "<<czyPalindrom("atokanapapanakota")<<endl;
    cout<<"Palindrom icoidioci: "<<czyPalindrom("icoidioci")<<endl;
    cout<<"Palindrom ABBBASIABBA: "<<czyPalindrom("ABBASIABBA")<<endl;
    */

    //Sprawdzanie, czy dany ciag znakow tworzy anagram
    /*
    cout<<"Anagramy siema, emisa: "<<czyAnagram("siema", "emisa")<<endl;
    cout<<"Anagramy sadasdaa, sadasi: "<<czyAnagram("sadasdaa", "sadasi")<<endl;
    cout<<"Anagramy witam, witax: "<<czyAnagram("witam", "witax")<<endl;
    cout<<"Anagramy aaabbbccc, bbbccacaa: "<<czyAnagram("aaabbbccc", "bbbccacaa")<<endl;
    cout<<"Anagramy aabbcc, aaabbcc: "<<czyAnagram("aabbcc", "aaabbcc")<<endl;
    */
    /*
    cout<<"Anagramy_v2 siema, emisa: "<<czyAnagram_v2("siema", "emisa")<<endl;
    cout<<"Anagramy_v2 sadasdaa, sadasi: "<<czyAnagram_v2("sadasdaa", "sadasi")<<endl;
    cout<<"Anagramy_v2 witam, witax: "<<czyAnagram_v2("witam", "witax")<<endl;
    cout<<"Anagramy_v2 aaabbbccc, bbbccacaa: "<<czyAnagram_v2("aaabbbccc", "bbbccacaa")<<endl;
    cout<<"Anagramy_v2 aabbcc, aaabbcc: "<<czyAnagram_v2("aabbcc", "aaabbcc")<<endl;
    */
    /*
    cout<<"Anagramy_v3 siema, emisa: "<<czyAnagram_v3("siema", "emisa")<<endl;
    cout<<"Anagramy_v3 sadasdaa, sadasi: "<<czyAnagram_v3("sadasdaa", "sadasi")<<endl;
    cout<<"Anagramy_v3 witam, witax: "<<czyAnagram_v3("witam", "witax")<<endl;
    cout<<"Anagramy_v3 aaabbbccc, bbbccacaa: "<<czyAnagram_v3("aaabbbccc", "bbbccacaa")<<endl;
    cout<<"Anagramy_v3 aabbcc, aaabbcc: "<<czyAnagram_v3("aabbcc", "aaabbcc")<<endl;
    */

    //Porzadkowanie alfabetyczne
    /*
    cout<<"Porzadkowanie alfabetyczne tablicy:\n";
    porzadkowanie(s, 5);
    */

    //Wyszukiwanie wzorca w tekscie
    /*
    cout<<"Tekst: siema; wzorzec: em - "<<wyszukajWzorzec("siema", "em")<<endl;
    cout<<"Tekst: howtodoit; wzorzec: howd - "<<wyszukajWzorzec("howtodoit", "howd")<<endl;
    */

    //Szyfr Cezara
    /*
    cout<<"Slowo AAABBBC, k=25: "<<szyfrujCezar("AAABBBC", 25)<<endl;
    cout<<"Slowo BBBCCCD, k=-10: "<<szyfrujCezar("BBBCCCD", -10)<<endl;
    */

    //Szyfr przestawieniowy
    /*
    cout<<"Slowo lokomotywa: "<<szyfrujPrzest("lokomotywa")<<endl;
    cout<<"Slowo olokomytaw: "<<szyfrujPrzest("olokomytaw")<<endl;
    */

    //Przesuniecie spolglosek o jedno miejsce
    /*
    char a[11] = "lokomotywa";
    kodowanie(a);
    cout<<"Kodowanie lokomotywa: "<<a<<endl;
    dekodowanie(a);
    cout<<"Dekodowanie wolokomyta: "<<a<<endl;
    */

    return 0;
}
