#include <bits/stdc++.h>

using namespace std;

template<typename T>
void check(T &a)
{
    cout<<"sth general"<<endl;
}

template<typename T>
void check(vector<T> &a)
{
    cout<<a.size()<<" vector "<<endl;
};

constexpr int gcd(int n, int m)
{
    if (m==0) return n;
    return gcd(m, n%m);
}

int gcd2(int n, int m)
{
    if (m==0) return n;
    return gcd(m, n%m);
}

// how to emulate partial template specialization with functions

int check(int _)
{
    return 1;
}

int main()
{
    cout<<check(12)<<endl;
}