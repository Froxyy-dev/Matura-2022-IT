#include <iostream>
#include <fstream>

using namespace std;

void wyswietl(int a[], int b[], int n, int m, int t[], int c)
{
    cout<<"Zestaw nr "<<c<<": "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"a"<<i+1<<": "<<a[i]<<" ";
        cout<<"b"<<i+1<<": "<<b[i]<<endl;
    }
    cout<<"\nStrzaly: ";
    for(int i=0; i<m; i++)
            cout<<"t"<<i+1<<": "<<t[i]<<endl;
    cout<<endl<<endl;
}

void solve4_1(int a[], int b[], int n, int m, int t[], int c)
{
    bool shooted[n] = {};
    int ilosc = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            if(t[i] >= a[j] && t[i] < a[j] + b[j] && !shooted[j])
            {
                ilosc++;
                shooted[j] = 1;
            }
    }
    cout<<"Zad 4.1 #"<<c<<": "<<ilosc<<endl;
}

void solve4_2(int a[], int b[], int n, int m, int t[], int c)
{
    int global_max = 0;
    for(int i=0; i<n; i++)
        if(b[i] > global_max)
            global_max = b[i];

    cout<<"Zad 4.2 #"<<c<<": "<<global_max<<endl;
}

void solve4_3(int a[], int b[], int n, int m, int t[], int c)
{
    int global_max = 0, ilosc, result;
    for(int i=0; i<=300; i++)
    {
        ilosc = 0;
        for(int j=0; j<n; j++)
            if(i >= a[j] && i < a[j] + b[j])
                ilosc++;
        if(ilosc > global_max)
        {
            result = i;
            global_max = ilosc;
        }
    }

    cout<<"Zad 4.3 #"<<c<<": "<<result<<endl;
}

void solve4_4(int a[], int b[], int n, int m, int t[], int c)
{
    int ilosc = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            if(t[i] >= a[j] && t[i] < a[j] + b[j])
                ilosc++;
    }
    cout<<"Zad 4.4 #"<<c<<": "<<ilosc<<endl;
}

int main()
{
    ifstream in("festyn.txt");

    int n, m, c = 1;
    while(in >> n)
    {
        int *a = new int[n];
        int *b = new int[n];
        for(int i=0; i<n; i++)
            in >> a[i] >> b[i];

        in >> m;
        int *t = new int[m];
        for(int i=0; i<m; i++)
            in >> t[i];

        //wyswietl(a, b, n, m, t, c);
        solve4_1(a, b, n, m, t, c);
        solve4_2(a, b, n, m, t, c);
        solve4_3(a, b, n, m, t, c);
        solve4_4(a, b, n, m, t, c);

        cout<<endl<<endl;
        c++;
        //zwalniamy pamiec
        delete[] a;
        delete[] b;
        delete[] t;
    }

    return 0;
}
