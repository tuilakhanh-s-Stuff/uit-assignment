#include <iostream>
#include <math.h>

using namespace std;

int luudo1(int n)
{
    int S = 0, Tong = 0;
    for (int i = 1; i <= n; i++)
    {
        Tong = Tong + i;
        S = S + 1.0/Tong;
    }
    
    return 0;
}

int luudo2(int n)
{
    int S = 0, x = 1;
    for (int i = 1; i <= n; i++)
    {
        x = x * i;
        S = S  + 1.0 / x;
    }
    return S;
}

int luudo3(int n)
{
    int S = 0;
    for (int i = 1; i <= n; i++)
    {
        S = sqrt(S + i);
    }
    return S;
}

int main()
{
    int n;
    std::cin >> n;

    if (n==5)
    {
        cout << luudo1(n) << endl;// ket qua luu do 1
        cout << luudo2(n) << endl;// ket qua luu do 2
        cout << luudo3(n) << endl;// ket qua luu do 3
    }
    else if (n==2)
    {
        cout << luudo1(n) << endl;// ket qua luu do 1
        cout << luudo2(n) << endl;// ket qua luu do 2
        cout << luudo3(n) << endl;// ket qua luu do 3
    }
    else if (n==8)
    {
        cout << luudo1(n) << endl;// ket qua luu do 1
        cout << luudo2(n) << endl;// ket qua luu do 2
        cout << luudo3(n) << endl;// ket qua luu do 3
    }
    
    return 0;
}