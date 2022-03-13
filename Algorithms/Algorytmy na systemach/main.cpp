#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

//***************************
//System binarny w dziesietny
//***************************
int binToDec(string s)
{
    int wynik = 0;
    for(int i=0; i<s.size(); i++)
        wynik = wynik * 2 + (s[i] - '0');
    return wynik;
}
int binToDec_v2(string s)
{
    int wynik = 0;
    for(int i=0; i<s.size(); i++)
        wynik += (s[i] - '0') * pow(2, s.size()-1-i);
    return wynik;
}
//***************************
//System dziesietny w binarny
//***************************
string decToBin(int n)
{
    string wynik;
    while(n > 0)
    {
        wynik = char(n%2 + '0') + wynik;
        n/=2;
    }
    return wynik;
}
void decToBin_v2(int n, string &a)
{
    for(; n>=1; n/=2)
    {
        if(n%2 == 0)
            a.push_back('0');
        else
            a.push_back('1');
    }
    reverse(a.begin(), a.end());
}
//*************************
//Zamiana na dowolny system
//*************************
string decToP(int n, int p)
{
    string wynik;
    while(n > 0)
    {
        if(n%p > 9)
            wynik = char(n%p + 'A' - 10) + wynik;
        else
            wynik = char(n%p + '0') + wynik;
        n/=p;
    }
    return wynik;
}
//*****************
//Dodawanie binarne
//*****************
string dodawanie(string a, string b)
{
    string result;
    int schowek = 0, pom;
    while(a.size() || b.size())
    {
        pom = schowek;
        schowek = 0;
        if(a.size())
        {
            if(a.back() == '1')
                pom++;
            a.pop_back();
        }
        if(b.size())
        {
            if(b.back() == '1')
                pom++;
            b.pop_back();
        }
        if(pom >= 2)
        {
            schowek = 1;
            pom -= 2;
        }
        result.push_back('0' + pom);
    }
    if(schowek)
        result.push_back('1');

    reverse(result.begin(), result.end());
    return result;
}
//*******************
//Mnozenie binarne
//*******************
string mnozenie(string a, string b)
{
    string wynik;
    while(a.size() || b.size())
    {
        int pom1=0, pom2=0;


    }

}

int main()
{
    //System binarny w dziesietny
    /*
    cout<<"111: "<<binToDec("111")<<endl;
    cout<<"111001: "<<binToDec("111001")<<endl;
    cout<<"10100: "<<binToDec("10100")<<endl;
    */
    /*
    cout<<"111: "<<binToDec_v2("111")<<endl;
    cout<<"111001: "<<binToDec_v2("111001")<<endl;
    cout<<"10100: "<<binToDec_v2("10100")<<endl;
    */

    //System dziesietny w binarny
    /*
    cout<<"7: "<<decToBin_(7)<<endl;
    cout<<"57: "<<decToBin_(57)<<endl;
    cout<<"20: "<<decToBin_(20)<<endl;
    */
    /*
    string a;
    decToBin_v2(7, a);
    cout<<"7: "<<a<<endl;
    a.clear();
    decToBin_v2(57, a);
    cout<<"57: "<<a<<endl;
    a.clear();
    decToBin_v2(20, a);
    cout<<"20: "<<a<<endl;
    */

    //Zamiana na dowolny system
    /*
    cout<<"n = 1000, p = 2: "<<decToP(1000, 2)<<endl;
    cout<<"n = 1000, p = 8: "<<decToP(1000, 8)<<endl;
    cout<<"n = 1000, p = 16: "<<decToP(1000, 16)<<endl;
    */

    //Dodawanie binarne
    /*
    cout<<"10001 + 1001010 = "<<dodawanie("10001", "1001010")<<endl;
    */

    return 0;
}
