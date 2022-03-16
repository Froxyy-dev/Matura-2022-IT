#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream out("zad_5.txt");
const int SIZE = 500;
int t[SIZE];

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n%2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

void z1()
{
    for(int i=0; i<SIZE; i++)
    {
        int pierwiastek = sqrt(t[i]);
        if(pierwiastek*pierwiastek == t[i])
            if(czyPierwsza(pierwiastek))
                out<<t[i]<<endl;
    }
}

int main()
{
    ifstream in("liczby.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    z1();

    out.close();
    return 0;
}
