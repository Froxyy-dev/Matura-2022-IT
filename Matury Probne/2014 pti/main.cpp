#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int n;

int dlugosc(int x1, int y1, int x2, int y2)
{
    return pow(x1-x2, 2) + pow(y1-y2, 2);
}

bool czyProstokatny(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c)
{
    int a = dlugosc(x_a, y_a, x_b, y_b);
    int b = dlugosc(x_a, y_a, x_c, y_c);
    int c = dlugosc(x_c, y_c, x_b, y_b);

    return (a+b == c || a+c == b || b+c == a);
}

int main()
{
    ofstream out("zadanie4.txt");
    ifstream in("punkty.txt");
    in >> n;
    int x[n], y[n];
    for(int i=0; i<n; i++)
        in >> x[i] >> y[i];
    in.close();

    vector<int> trojki;

    int ile = 0;
    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
            for(int k=j+1; k<n; k++)
                if(czyProstokatny(x[i], y[i], x[j], y[j], x[k], y[k]))
                {
                    ile++;
                    trojki.push_back(i);
                    trojki.push_back(j);
                    trojki.push_back(k);
                }

    out<<"Liczba m: "<<ile<<"\nTrojki liczb:\n";
    for(int i=0; i<trojki.size()-2; i+=3)
        out<<trojki[i]<<" "<<trojki[i+1]<<" "<<trojki[i+2]<<endl;

    out.close();
    return 0;
}
