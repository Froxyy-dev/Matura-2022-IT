#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double x)
{
    return fabs((-1 * x*x)/50);
}
double g(double x)
{
    return fabs(1 + (x*x)/100 - x/200);
}

double PoleF(double a, double b, double epsilon)
{
    int n = (b-a)/epsilon;
    double h = (b-a)/(double)n;
    double S = 0.0;
    double podstawa_a = f(a), podstawa_b;

    for(int i=1; i<=n; i++)
    {
        podstawa_b = f(a + h*i);
        S += (podstawa_a + podstawa_b);
        podstawa_a = podstawa_b;
    }
    return S * 0.5 * h;
}

double PoleG(double a, double b, double epsilon)
{
    int n = (b-a)/epsilon;
    double h = (b-a)/(double)n;
    double S = 0.0;
    double podstawa_a = g(a), podstawa_b;

    for(int i=1; i<=n; i++)
    {
        podstawa_b = g(a + h*i);
        S += (podstawa_a + podstawa_b);
        podstawa_a = podstawa_b;
    }
    return S * 0.5 * h;
}

int main()
{
    ofstream out("figura.txt");
    double wynik;
    wynik = PoleG(0, 10, 0.01) + PoleF(0, 10, 0.01);
    out<<wynik<<endl;

    int i=1;
    while(int(f(i)) + int(g(i)) < 26) i++;
    out<<"C = "<<i<<"\nWspolrzedne:\n";
    out<<i<<"; "<<-(int)f(i)+1<<endl;
    out<<i<<"; "<<(int)g(i)<<endl;
    out<<i+100<<"; "<<-(int)f(i)+1<<endl;
    out<<i+100<<"; "<<(int)g(i)<<endl;

    out.close();
    return 0;
}
