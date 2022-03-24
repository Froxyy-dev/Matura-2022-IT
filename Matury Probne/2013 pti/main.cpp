#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int SIZE = 200;
int t[SIZE];

int main()
{
    ofstream out("zadanie5.txt");
    vector<int> fibonacci;
    ifstream in("dane.txt");
    for(int i=0; i<SIZE; i++)
        in >> t[i];
    in.close();

    int fib[46];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<=45; i++)
        fib[i] = fib[i-1] + fib[i-2];

    //Zadanie a) i b)
    out<<"5.\na)\n";
    int j, max_f = 0, min_f = INT_MAX;
    for(int i=0; i<SIZE; i++)
    {
        j = 0;
        while(t[i] > fib[j] && j < 45) ++j;
        if(t[i] == fib[j])
        {
            fibonacci.push_back(t[i]);
            out<<t[i]<<endl;
            if(t[i] > max_f)
                max_f = t[i];
            if(t[i] < min_f)
                min_f = t[i];
        }
    }
    out<<"\nb)\Najwieksza: "<<max_f<<"\nNajmniejsza: "<<min_f<<'\n';

    int dl = 1, dl_max = 0, pocz;
    for(int i=1; i<fibonacci.size(); i++)
    {
        if(fibonacci[i] > fibonacci[i-1])
            dl++;
        else
            dl = 1;
        if(dl > dl_max)
        {
            dl_max = dl;
            pocz = i-dl+1;
        }

    }

    out<<"\nc)\nNajdluszy rosnacy ciag: "<<dl_max<<'\n';
    out<<"\nWyrazy tego ciagu to:\n";
    for(int i=pocz; i<pocz+dl_max; i++)
        out<<fibonacci[i]<<endl;

    out.close();
    return 0;
}
