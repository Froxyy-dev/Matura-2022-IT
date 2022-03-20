#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int najdluzszy(vector<int> tab, int n)
{
    int LIS[n];
    LIS[0] = 1;
    for(int i=1; i<n; i++)
    {
        int maximum =0;
        for(int j=i-1; j>=0; j--)
        {
            if(tab[j]<tab[i])
            {
                maximum = max(maximum,LIS[j]);
            }
        }
        LIS[i]=maximum+1;
    }

    int dl_max = 0;
    for(int i=0; i<n; i++)
        if(LIS[i] > dl_max)
            dl_max = LIS[i];
    return dl_max;
}

int main()
{

    int k, n, q;
    ifstream in("ciagi.txt");
    ofstream out("podciagi.txt");
    in >> k;
    for(int i=0; i<k; i++)
    {
        vector<int> tab;
        in >> n;
        for(int j=0; j<n; j++)
        {
              in >> q;
              tab.push_back(q);
        }
        out<<najdluzszy(tab, n)<<endl;
    }
    in.close();
    out.close();

    return 0;
}
