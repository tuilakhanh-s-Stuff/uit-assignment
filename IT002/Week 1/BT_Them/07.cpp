#include <iostream>

void NamTram(long long& a)
{
    for  (; a >= 500; )
    {
        a -= 500;
        std::cout << "500k"<<' ';
    }
}

void HaiTram(long long& a)
{
    for (; a >= 200;)
    {
        a -= 200;
        std::cout << "200k" << ' ';
    }
}

void MotTram(long long& a)
{
    for ( ; a >= 100; )
    {
        a -= 100;
        std::cout << "100k" << ' ';
    }
}

void NamMuoi(long long& a)
{
    for ( ; a >= 50; )
    {
        a -= 50;
        std::cout << "50k" << ' ';
    }
}

void HaiMuoi(long long &a)
{
    for ( ; a >= 20; )
    {
        a -= 20;
        std::cout << "20k" << ' ';
    }
}

void Muoi(long long& a)
{
    for (; a >= 10;)
    {
        a -= 10;
        std::cout << "10k" << ' ';
    }
}

void Nam(long long& a)
{
    for ( ; a >= 5; )
    {
        a -= 5;
        std::cout << "5k" << ' ';
    }
}

void Hai(long long& a)
{
    for ( ; a >= 2; )
    {
        a -= 2;
        std::cout << "2k" << ' ';
    }
}

void Mot(long long& a)
{
    for ( ; a > 0; )
    {
   
        a -= 1;
        std::cout << "1k" << ' ';
    }
}

int main()
{
    long long a;
    std::cout << "Vui long nhap so tien: ";
    std::cin >> a;
    NamTram(a);
    HaiTram(a);
    MotTram(a);
    NamMuoi(a);
    HaiMuoi(a);
    Muoi(a);
    Nam(a); 
    Hai(a);
    Mot(a);
    return 0;
}
