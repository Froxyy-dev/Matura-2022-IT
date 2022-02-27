#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

const int SIZE=100;
int t[SIZE];
string s[SIZE];
ofstream out("wyniki4.txt");

string sortuj(string s)
{
    sort(s.begin(),s.end());
    return s;
}

bool czy_pierwsza(int n)
{
    if(n<2) return false;
    if(n%2==0 && n!=2) return false;
    for(int i=3;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}

void hipoteza(int n)
{
    if(n%2!=0 || n<4) return;
    for(int i=3;i<=n/2;i+=2)
    {
        if(czy_pierwsza(i)&&czy_pierwsza(n-i))
        {
            out<<n<<" "<<i<<" "<<n-i<<endl;
            break;
        }

    }
}

int main()
{
    ifstream in("pary.txt");

    for(int i=0;i<SIZE;i++)
        in>>t[i]>>s[i];
    in.close();

    out<<"4.1"<<endl;
    for(int i=0;i<SIZE;i++)
        hipoteza(t[i]);

    out<<"4.2"<<endl;

    char literka;
    int dl, dl_max;
    for(int i=0;i<SIZE;i++)
    {
        dl=1, dl_max=0;
        for(int j=1;j<s[i].size();j++)
        {
            if(s[i][j] == s[i][j-1])
                dl++;
            else
                dl=1;
            if(dl_max<dl)
            {
                dl_max=dl;
                literka=s[i][j-1];
            }
        }
        for(int i=0;i<dl_max;i++)
        {
           out<<literka;
        }
        out<<" "<<dl_max<<endl;
    }
    out<<"4.3"<<endl;
    int min_l=101;
    string min_s="";
    for(int i=0;i<SIZE;i++)
    {
        if(t[i] == s[i].size())
        {
            if(t[i]<min_l)
            {
                min_l=t[i];
                min_s=s[i];
            }
            else if(t[i]==min_l)
            {
                if(min_s == "")
                {
                    min_l=t[i];
                    min_s=s[i];
                    continue;
                }
                else if(sortuj(s[i])<sortuj(min_s))
                {
                    min_l=t[i];
                    min_s=s[i];
                    continue;
                }
            }

        }
    }
    out<<min_l<<" "<<min_s;



    out.close();
    return 0;
}
