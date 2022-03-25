#include <iostream>
#include <fstream>

using namespace std;

void czyAnagramy(int a, int b)
{
    int licz[10] = {};
    int cpA = a, cpB = b;
    while(cpA > 0)
    {
        licz[cpA%10]++;
        cpA /= 10;
    }
    while(cpB > 0)
    {
        licz[cpB%10]--;
        cpB /= 10;
    }
    for(int i=0; i<10; i++)
        if(licz[i] != 0)
        {
            cout<<a<<" "<<b<<" nie"<<endl;
            return;
        }

    cout<<a<<" "<<b<<" tak"<<endl;
}

int main()
{
    cout<<"Zadanie 6.\nPodpunkt b)\n";
    int a, b;
    cin >> a >> b;

    czyAnagramy(a, b);
    cout<<"\nPodpunkt c)\n";

    int n, p, q;
    ifstream in("dane.txt");
    in >> n;
    for(int i=0; i<n; i++)
    {
        in >> p >> q;
        czyAnagramy(p, q);
    }
    return 0;
}
