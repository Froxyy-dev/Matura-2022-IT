#include <iostream>
#include <fstream>

using namespace std;

string s[100], s1[3000], s3[3000], s4[3000];
int l[3000];
ofstream out1("wyniki_6_1.txt");
ofstream out2("wyniki_6_2.txt");
ofstream out3("wyniki_6_3.txt");

string szyfruj(string s, int k)
{
    string wyraz;
    int n = k%26, dl = s.size();
    for(int i=0; i< dl; i++)
    {
        if(s[i] + n <= 'Z')
        {

            wyraz += s[i]+ n;
        }
        else
        {
            wyraz += s[i] + n - 26;
        }
    }
    return wyraz;
}

string deszyfruj(string s, int k)
{
    string wyraz;
    int n = k%26, dl = s.size();
    for(int i=0; i< dl; i++)
    {
        if(s[i] - n >= 'A')
        {

            wyraz += s[i] - n;
        }
        else
        {
            wyraz += s[i] - n + 26;
        }
    }
    return wyraz;
}

void z1()
{
    out1<<"6.1"<<endl;
    for(int i=0; i<100; i++)
    {
        out1<<szyfruj(s[i], 107)<<endl;
    }
}

void z2()
{
    out2<<"6.2"<<endl;
    for(int i=0; i<3000; i++)
    {
        out2<<deszyfruj(s1[i], l[i])<<endl;
    }
}

void z3()
{
    for(int i=0; i<3000; i++)
    {
        if(s3[i].size() != s4[i].size())
        {
            out3<<s[i]<<endl;
            continue;
        }
        int pom =s4[i][0] - s3[i][0];
        if(pom < 0)
            pom+=26;
        for(int j=1; j< s3[i].size(); j++)
        {
            int kod = s4[i][j] - s3[i][j];
            if(kod < 0)
                kod+=26;
            if(kod != pom)
            {
                out3<<s3[i]<<endl;
                break;
            }
        }
    }

}

int main()
{
    ifstream in("dane_6_1.txt");

    for(int i=0; i<100; i++)
        in>>s[i];
    in.close();

    ifstream in1("dane_6_2.txt");
    for(int i=0; i<3000; i++)
    {
        in1>>s1[i]>>l[i];
    }
    in1.close();

    ifstream in2("dane_6_3.txt");
    for(int i=0; i<3000; i++)
    {
        in2>>s3[i]>>s4[i];
    }
    in2.close();

    z1();
    z2();
    z3();

    out1.close();
    out2.close();
    return 0;
}
