#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream out1("wyniki_6_1.txt");
ofstream out2("wyniki_6_2.txt");
ofstream out3("wyniki_6_3.txt");
ofstream out4("wyniki_6_4.txt");
ofstream out5("wyniki_6_5.txt");
const int SIZE = 999;
string s[SIZE];

int octToDec(string s)
{
    int dl = s.size()-2;
    int suma=0;
    int k=1;
    for(int i=dl; i>=0; i--)
    {
        suma += k*int(s[i]-'0');
        k*=8;
    }

    return suma;
}

int sysToDec(string s)
{
    int p = int(s.back() - '0');
    int dl = s.size()-2;
    int suma=0;
    int k=1;
    for(int i=dl; i>=0; i--)
    {
        suma += k*int(s[i]-'0');
        k*=p;
    }

    return suma;
}

void z1()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(s[i].back() == '8')
            ile++;
    out1<<ile<<endl;
}

void z2()
{
    int ile=0;
    for(int i=0; i<SIZE; i++)
        if(s[i].back() == '4')
        {
            ile++;
            for(int j=0; j<s[i].size()-1; j++)
                if(s[i][j] == '0')
                {
                    ile--;
                    break;
                }
        }
    out2<<ile;

}

void z3()
{
    int ile = 0;
    for(int i=0; i<SIZE; i++)
        if(s[i].back() == '2')
            if(s[i][s[i].size()-2] == '0')
                ile++;
    out3<<ile;
}

void z4()
{
    int suma = 0;
    for(int i=0; i<SIZE; i++)
        if(s[i].back() == '8')
            suma += octToDec(s[i]);
    out4<<suma;
}

void z5()
{
    int max_s = sysToDec(s[0]);
    int min_s = sysToDec(s[0]);
    int i_min = 0, i_max = 0;
    for(int i=1; i<SIZE; i++)
    {
        int pom = sysToDec(s[i]);
        if(pom > max_s)
        {
            max_s = pom;
            i_max = i;
        }
        if(pom < min_s)
        {
            min_s = pom;
            i_min = i;
        }
    }
    out5<<s[i_max]<<" "<<max_s<<endl;
    out5<<s[i_min]<<" "<<min_s;
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in>>s[i];
    in.close();

    z1();
    z2();
    z3();
    z4();
    z5();
    out1.close();
    out2.close();
    out3.close();
    out4.close();
    out5.close();
    return 0;
}
