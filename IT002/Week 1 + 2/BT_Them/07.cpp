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

void Input(long long &a)
{
    do {
        std::cout << "Vui long nhap so tien: ";
        std::cin >> a;
        if (a < 0)
            std::cout << "Vui long nhap so tien khong am.";
        else if(a % 50 != 0)
            std::cout << "Vui long nhap so tien chia het cho 50!";
        else if(a < 50)
            std::cout << "Vui long nhap so tien lon hon 50.000";
        else if(a > 100000000)
            std::cout << "Vui long nhap so tien nho hon 100.000.000";
        else
            break;
        std::cout << "\nNhap lai: ";
    } while(true);
    
}

int main()
{
    long long a;
    Input(a);
    NamTram(a);
    HaiTram(a);
    MotTram(a);
    NamMuoi(a);
    return 0;
}
