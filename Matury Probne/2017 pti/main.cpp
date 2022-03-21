#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int t[1003][3];
double x[100], y[100];

void z1()
{
    ofstream out1("wynik1.txt");
    int pierwsza = 0, druga = 0, trzecia = 0, czwarta = 0;
    for(int i=0; i<100; i++)
    {
        if(x[i] > 0 && y[i] > 0)
            pierwsza++;
        if(x[i] < 0 && y[i] > 0)
            druga++;
        if(x[i] < 0 && y[i] < 0)
            trzecia++;
        if(x[i] > 0 && y[i] < 0)
            czwarta++;
    }
    out1<<pierwsza<<" "<<druga<<" "<<trzecia<<" "<<czwarta<<endl;
    out1.close();
}

void z2()
{
    ofstream out2("wynik2.txt");
    vector<int> x, y, r;
    for(int i=0; i<1003; i++)
    {
        if(abs(t[i][1]) == t[i][2])
        {
            x.push_back(t[i][0]);
            y.push_back(t[i][1]);
            r.push_back(t[i][2]);
        }
    }

    for(int i=x.size()-1; i>=1; i--)
        for(int j=0; j<i; j++)
            if(x[j] > x[j+1] || (x[j] == x[j+1] && y[j] > y[j+1]))
            {
                swap(x[j], x[j+1]);
                swap(y[j], y[j+1]);
                swap(r[j], r[j+1]);
            }
    for(int i=0; i<x.size(); i++)
        out2<<x[i]<<" "<<y[i]<<" "<<r[i]<<endl;
    out2<<x.size()<<endl;
    out2.close();
}

void z3()
{
    ofstream out3("wynik3.txt");
    double Pole = 0.0;
    Pole += abs(x[0]*y[99] - x[99]*y[0]);
    for(int i=0; i<99; i++)
    {
        Pole += abs(x[i]*y[i+1] - x[i+1]*y[i]);
    }
    Pole /= 2.;
    out3<<int(Pole)<<endl;
    out3.close();
}

int main()
{
    ifstream in1("punkty_3.txt");
    for(int i=0; i<100; i++)
        in1 >> x[i] >> y[i];
    in1.close();

    z1();

    ifstream in2("okregi_3.txt");
    for(int i=0; i<1003; i++)
        in2 >> t[i][0] >> t[i][1] >> t[i][2];
    in2.close();

    z2();
    z3();

    return 0;
}
