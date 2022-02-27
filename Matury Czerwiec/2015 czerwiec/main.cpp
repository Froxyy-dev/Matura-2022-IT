#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream out1("kody1.txt");
ofstream out2("kody2.txt");
ofstream out3("kody3.txt");
const int SIZE = 500;
int l[SIZE];

string kodKreskowy(int n)
{
    string wynik;
    switch(n)
    {
        case 0:
        {
            return "10101110111010";
            break;
        }
        case 1:
        {
            return "11101010101110";
            break;
        }
        case 2:
        {
            return "10111010101110";
            break;
        }
        case 3:
        {
            return "11101110101010";
            break;
        }
        case 4:
        {
            return "10101110101110";
            break;
        }
        case 5:
        {
            return "11101011101010";
            break;
        }
        case 6:
        {
            return "10111011101010";
            break;
        }
        case 7:
        {
            return "10101011101110";
            break;
        }
        case 8:
        {
            return "11101010111010";
            break;
        }
        case 9:
        {
            return "10111010111010";
            break;
        }
    }
    return "";
}

int sumaParzyste(int n, bool parzyste)
{
    int k=0, suma=0;
    while(n > 0)
    {
        if(k%2 == 0 && parzyste)
        {
           suma += n%10;
        }
        if(k%2 == 1 && !parzyste)
        {
            suma += n%10;
        }
        k++;
        n/=10;
    }

    return suma;
}
void z1()
{
    for(int i=0; i<SIZE; i++)
        out1<<sumaParzyste(l[i], 1)<< " "<<sumaParzyste(l[i], 0)<<endl;

}
void z2()
{
    for(int i=0; i<SIZE; i++)
    {
        int sumaP = sumaParzyste(l[i], 1) * 3;
        int sumaNp = sumaParzyste(l[i], 0);
        int pom = sumaP + sumaNp;
        pom = pom % 10;
        pom = 10 - pom;
        pom = pom % 10;
        out2<<pom<<" "<<kodKreskowy(pom)<<endl;
    }
}
void z3()
{
    for(int i=0; i<SIZE; i++)
    {
        string wynik = "11010110";
        int sumaP = sumaParzyste(l[i], 1) * 3;
        int sumaNp = sumaParzyste(l[i], 0);
        int pom = sumaP + sumaNp;
        pom = pom % 10;
        pom = 10 - pom;
        pom = pom % 10;
        wynik = kodKreskowy(pom) + wynik;

        int n = l[i];
        while(n > 0)
        {
            wynik = kodKreskowy(n%10) + wynik;
            n/=10;
        }

        wynik = "11011010" + wynik;
        out3<<wynik<<endl;
    }

}
int main()
{
    ifstream in("kody.txt");
    for(int i=0; i<SIZE; i++)
        in>>l[i];
    in.close();

    z1();
    z2();
    z3();
    out1.close();
    out2.close();
    out3.close();
    return 0;
}
