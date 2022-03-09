#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

ofstream out("Raport5.txt");

int zad1(vector<int> ciag)
{
    int suma = 0, max_s = INT_MIN;
    for(int i=0; i<ciag.size(); i++)
    {
        suma += ciag[i];
        if(suma > max_s)
            max_s = suma;
        if(suma < 0)
            suma = 0;
    }
    return max_s;
}

void najpopularniejszy(vector<int> ciag)
{
    map<int, int> mp;
    int max_wystap = 0;
    for(auto i:ciag)
    {
        mp[i] = (mp.find(i) == mp.end()) ? 1 : mp[i] + 1;
        if(mp[i] > max_wystap)
            max_wystap = mp[i];
    }

    for(auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        if(itr->second == max_wystap)
            out<<itr->first<<endl;
    }

}

int main()
{
    int liczba;
    vector<int> ciag;
    ifstream in("dane5-1.txt");
    while(in >> liczba)
    {
        ciag.push_back(liczba);
    }
    in.close();

    out<<zad1(ciag)<<endl;
    out<<endl;
    najpopularniejszy(ciag);
    out<<endl;
    ciag.clear();

    ifstream in1("dane5-2.txt");
    while(in1 >> liczba)
    {
        ciag.push_back(liczba);
    }
    in1.close();

    out<<zad1(ciag)<<endl;
    out<<endl;
    najpopularniejszy(ciag);
    out<<endl;
    ciag.clear();

    ifstream in2("dane5-3.txt");
    while(in2 >> liczba)
    {
        ciag.push_back(liczba);
    }
    in2.close();

    out<<zad1(ciag)<<endl;
    out<<endl;
    najpopularniejszy(ciag);
    out<<endl;
    ciag.clear();

    out.close();
    return 0;
}
