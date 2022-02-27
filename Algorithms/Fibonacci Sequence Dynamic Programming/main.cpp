#include <iostream>
#include <cmath>

using namespace std;

//Nth number of FIBONACCI SEQUENCE
//Brute Force = O(2^n)
//Top Down = O(n)
//Bottom Down = O(n)
//Math = O(1) - constant time and space complexity

int totalCalls = 0;

int cache[100];

//Brute Force
int fib(int n)
{
    totalCalls++;
    if(n <= 1)
            return n;
    return fib(n-1) + fib(n-2);
}

//TopDown approach
int fibT(int n)
{
    totalCalls++;

    if(cache[n] > 0) return cache[n];

    if(n <= 1) return n;
    cache[n] = fibT(n-1) + fibT(n-2);
    return cache[n];
}

//BottomUp approach
int fibBottom(int n)
{
    if(n == 0) return n;
    int f1 = 1, f2 = 1;
    for(int i=3; i<=n; i++)
    {
        totalCalls++;
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    return f2;
}

//Math approach
int fibMath(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi ,n) / sqrt(5));
}

int main()
{
    cout<<fibMath(32)<<endl;
    cout<<totalCalls;
    return 0;
}
