#include <iostream>
#include <fstream>

using namespace std;

bool czyPierwsza(int n)
{
    if(n <= 1) return false;
    if(n % 2 == 0 && n != 2) return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i == 0)
            return false;
    return true;
}

int sumaCyfr(int n)
{
    int suma = 0;
    while(n > 0)
    {
        suma += n%10;
        n /= 10;
    }
    return suma;
}
int sumaBin(int n)
{
    int suma = 0;
    while(n > 0)
    {
        if(n%2 == 1)
            suma++;
        n /= 2;
    }
    return suma;
}

bool czyBpierwsza(int n)
{
    if(czyPierwsza(n) && czyPierwsza(sumaCyfr(n)))
        if(czyPierwsza(sumaBin(n)))
            return true;

    return false;
}

int main()
{
    ofstream out1("1.txt");
    ofstream out2("2.txt");
    ofstream out3("3.txt");

    int ile = 0;

    for(int i=2; i<=1000; i++)
        if(czyBpierwsza(i))
        {
            ile++;
            out1<<i<<endl;
        }
    cout<<"a)\n1. "<<ile<<endl;

    ile = 0;
    for(int i=100; i<=10000; i++)
        if(czyBpierwsza(i))
        {
            ile++;
            out2<<i<<endl;
        }
    cout<<"2. "<<ile<<endl;

    ile = 0;
    for(int i=1000; i<=100000; i++)
        if(czyBpierwsza(i))
        {
            ile++;
            out3<<i<<endl;
        }
    cout<<"3. "<<ile<<endl;

    ile = 0;
    for(int i=100; i<=10000; i++)
        if(czyPierwsza(sumaCyfr(i)))
            ile++;
    cout<<"\nb)\n"<<ile<<'\n';

    int suma = 0;
    for(int i=100; i<=10000; i++)
        if(czyBpierwsza(i))
            suma += i;
    if(czyPierwsza(suma))
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;

    out1.close();
    out2.close();
    out3.close();
    return 0;
}
