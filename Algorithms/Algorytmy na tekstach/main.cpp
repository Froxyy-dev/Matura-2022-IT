#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//**************************************************
//Sprawdzanie, czy dany ciag znakow tworzy palindrom
//**************************************************
bool czyPalindrom(string s)
{
    int dl = s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}
//************************************************
//Sprawdzanie, czy dany ciag znakow tworzy anagram
//************************************************
bool czyAnagram(string a, string b)
{
    int dl_a = a.size(), dl_b = b.size();
    if(dl_a != dl_b) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<dl_a; i++)
        if(a[i] != b[i])
            return false;
    return true;
}
bool czyAnagram_v2(char a[], char b[])
{
    int dl_a = strlen(a), dl_b = strlen(b);
    if(dl_a != dl_b) return false;
    int licz[127] = {};

    for(int i=0; i<dl_a; i++)
        licz[a[i]]++;
    for(int i=0; i<dl_a; i++)
        licz[b[i]]--;
    for(int i=0; i<127; i++)
        if(licz[i] != 0)
            return false;
    return true;
}
bool czyAnagram_v3(string a, string b)
{
    if(a.size() != b.size()) return false;
    map<char, int> mp;
    for(auto const &c:a)
        mp[c] = (mp.find(c) == mp.end()) ? 1 : mp[c] + 1;

    for(auto const &c:b)
    {
        if(mp.find(c) == mp.end())
            return false;
        mp[c]--;
    }
    for(map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
        if(itr->second != 0)
            return false;
    return true;
}
//**************************
//Porzadkowanie alfabetyczne
//**************************
void porzadkowanie(string s[], int n)
{
    for(int i=n-1; i>=1; i--)
        for(int j=0; j<i; j++)
            if(s[j] > s[j+1])
                swap(s[j], s[j+1]);
    /*
    for(int i=1; i<n; i++)
        for(int j=i-1; j>=0; j--)
            if(s[j+1] < s[j])
                swap(s[j+1], s[j]);
            else
                break;
    */
    for(int i=0; i<n; i++)
        cout<<s[i]<<" ";
    cout<<endl;
}
//*****************************
//Wyszukiwanie wzorca w tekscie
//*****************************
bool wyszukajWzorzec(string tekst, string wzorzec)
{
    int dl_t = tekst.size(), dl_w = wzorzec.size();
    bool ok;
    for(int i=0; i<=dl_t - dl_w; i++)
    {
        ok =1;
        for(int j=0; j<dl_w; j++)
            if(tekst[j+i] != wzorzec[j])
            {
                ok = 0;
                break;
            }
        if(ok)
            return true;
    }
    return false;
}
//************
//Szyfr Cezara
//************
string szyfrujCezar(string s, int k)
{
    k = k%26;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] + k > 'Z')
            s[i] = s[i] + k - 26;
        else if(s[i] + k < 'A')
            s[i] = s[i] + k+26;
        else
            s[i] = s[i] +k;
    }
    return s;
}
//*********************
//Szyfr przestawieniowy
//*********************
string szyfrujPrzest(string s)
{
    for(int i=0; i<s.size()-1; i+=2)
        swap(s[i], s[i+1]);
    return s;
}
//***************************************
//Przesuniecie spolglosek o jedno miejsce
//***************************************
bool czySpolgloska(char l)
{
    return !(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'y');
}
void kodowanie(char napis[])
{
    int dl = strlen(napis), nr;
    bool f =1;
    char first;
    for(int i=0; i<dl; i++)
        if(czySpolgloska(napis[i]))
            if(f)
            {
                nr = i;
                first = napis[i];
                f=0;
            }
            else
            {
                char pom = napis[i];
                napis[i] = first;
                first = pom;
            }
    if(!f)
        napis[nr] = first;
}
void dekodowanie(char napis[])
{
    int n = strlen(napis), nr;
    bool f=1;
    char first;
    for(int i=n-1; i>=0; i--)
        if(czySpolgloska(napis[i]))
            if(f)
            {
                first = napis[i];
                nr=i;
                f=0;
            }
            else
            {
                char pom = napis[i];
                napis[i] = first;
                first = pom;
            }
    if(!f)
        napis[nr] = first;
}
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
    cout<<"Anagramy_v2 siema, emisa: "<<czyAnagram_v2("siema", "emisa")<<endl;
    cout<<"Anagramy_v2 sadasdaa, sadasi: "<<czyAnagram_v2("sadasdaa", "sadasi")<<endl;
    cout<<"Anagramy_v2 witam, witax: "<<czyAnagram_v2("witam", "witax")<<endl;
    cout<<"Anagramy_v2 aaabbbccc, bbbccacaa: "<<czyAnagram_v2("aaabbbccc", "bbbccacaa")<<endl;
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
    cout<<"Slowo AAABBBC, k=1: "<<szyfrujCezar("AAABBBC", 25)<<endl;
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
