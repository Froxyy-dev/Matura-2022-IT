#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool *tab = new bool[n+1];
    for(int i=2; i<=n; i++)
        tab[i] = 0;
    tab[0] = 1;
    tab[1] = 1;
    for(int i=2; i*i<=n; i++)
        if(!tab[i])
            for(int j=i*i; j<=n; j+=i)
                tab[j] = 1;

    for(int i=3; i<n-1; i+=2)
        if(!tab[i] && !tab[i+2])
            cout<<i<<" "<<i+2<<endl;

    delete []tab;
    return 0;
}
