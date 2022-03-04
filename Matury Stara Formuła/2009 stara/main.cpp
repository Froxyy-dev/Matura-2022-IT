#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool czyPalindrom(string s)
{
    int dl=s.size();
    for(int i=0; i<dl/2; i++)
        if(s[i] != s[dl-i-1])
            return false;
    return true;
}

bool wyszukajWzorzec(string tekst, string wzorzec)
{
    return tekst.find(wzorzec) != string::npos;
}

/*
string utworz(string a, string b)
{
    int prefiks = 0, sufiks = 0, dl_a = a.size(), dl_b = b.size();
    int j=dl_b-1;
    for(int i=dl_b-1; i>=0; i--)
    {
        if(a[i] == b[j])
        {
            prefiks++;
            j--;
        }
        else
        {
            prefiks = 0;
            j = dl_b-1;
            if(a[i] == b[j])
                prefiks++;
        }
    }
    j = 0;
    for(int i=dl_a-dl_b; i<dl_a; i++)
    {
        if(a[i] == b[j])
        {
            sufiks++;
            j++;
        }
        else
        {
            sufiks = 0;
            j = 0;
            if(a[i] == b[j])
            {
                sufiks++;
                j++;
            }

        }
    }
    if(sufiks == 0 && prefiks == 0)
        return a+b;

    string C = a;
    if(sufiks > prefiks)
    {
        for(int i=0; i<dl_b-sufiks; i++)
        {
            C += b[sufiks+i];
        }
    }
    else
    {
        string pom;
        for(int i=0; i<dl_b-prefiks; i++)
        {
            pom += b[i];
        }
        C = pom + C;
    }
    return C;
}
*/

string utworz(string a, string b)
{
    bool flaga;
    string temp, temp2, temp3, temp4;
    for(int i=b.size(); i>=0; i--)
    {
        flaga = false;
        temp = b.substr(b.size()-i, b.size());
        temp2 = a.substr(0, i);
        temp3 = b.substr(0, i);
        temp4 = a.substr(a.size()-i, a.size());
        if(temp == temp2 || temp3 == temp4)
        {
            if(temp.size() == 0 || temp3.size() == 0)
                continue;

            if(temp == temp2)
                return (b.substr(0, b.size()-temp2.size()) + a);
            else
                return (a + b.substr(temp3.size()));
        }
    }
    return a+b;
}

int main()
{
    int zad_a = 0, zad_b = 0, zad_c;
    string A, B, C;
    vector<string> najkrotsze;
    ifstream in("dane.txt");
    while(in >> A >> B)
    {
        if(czyPalindrom(A))
            zad_a++;
        if(czyPalindrom(B))
            zad_a++;
        if(wyszukajWzorzec(A, B))
        {
            zad_b++;
            najkrotsze.push_back(A);
            continue;
        }
        C = utworz(A, B);
        if(C.size() == A.size() + B.size())
            zad_c++;
        najkrotsze.push_back(C);
    }
    in.close();

    ofstream out("zad_5.txt");

    out<<"5.\na)\n"<<zad_a<<endl;
    out<<"\nb)\n"<<zad_b<<endl;
    out<<"\nc)\n"<<zad_c<<endl;
    out<<"\nd)\n";
    for(int i=0; i<najkrotsze.size(); i++)
        out<<najkrotsze[i]<<endl;

    out.close();
    return 0;
}
