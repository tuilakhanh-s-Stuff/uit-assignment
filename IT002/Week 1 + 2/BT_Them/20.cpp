#include<iostream>
#include<math.h>

void isPrimes(int a)
{
	bool Check = true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			Check = false;
	}
	if(Check)
        std::cout << a << " la so nguyen to.";
    else
        std::cout << a << " khong phai la so nguyen to.";	
}

void isSquare(int a)
{
	bool Check = false;
	for (int i = 0; i <= a; i++)
	{
		if (i * i == a)
			Check = true;
	}
	if(Check)  
        std::cout<< a << " la so chinh phuong.";
	else
        std::cout << a << " khong phai la so chinh phuong.";
        
}

void isPerfect(int a)
{
	int sum = 0;
	for (int i = 1; i <= a/2; i++)
	{
		if (a % i == 0)
			sum = sum + i;
	}
	if(sum == a) 
        std::cout << a << " la so hoan thien.";
	else 
        std::cout << a << " khong phai la so hoan thien.";
}

void isSymmetrical(int a)
{
	int sum = 0, i, b, c;
	c = a;
	for (i = a; a != 0; a = a / 10) {
	    b = a % 10;
		sum = sum * 10 + b;
	}
	if (i == sum)
		std::cout << c << " la so doi xung.";
	else
		std::cout << c << " khong phai la so doi xung.";
}

int main()
{
	int a;
	std::cout << "Nhap a: "; 
    std::cin >> a;
	isPrimes(a);
	std::cout << std::endl;
	isSquare(a);
	std::cout << std::endl;
	isPerfect(a);
	std::cout << std::endl;
	isSymmetrical(a);
	return 0;
}