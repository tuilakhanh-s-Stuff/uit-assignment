#include <iostream>
#include <algorithm>

typedef struct PhanSo
{
	int tuso;
	int mauso;
} PS;

void input(PS &p)
{
	std::cin >> p.tuso;
	std::cin >> p.mauso;
}

PS add(PS fac1, PS fac2)
{
	PS sum;
	sum.tuso = fac1.tuso*fac2.mauso + fac1.mauso*fac2.tuso;
	sum.mauso = fac1.mauso*fac2.mauso;
	return sum;
}

PS subtract(PS fac1, PS fac2)
{
	PS sub;
	sub.tuso = fac1.tuso*fac2.mauso - fac1.mauso*fac2.tuso;
	sub.mauso = fac1.mauso*fac2.mauso;
	return sub;
}

PS multi(PS fac1, PS fac2)
{
	PS mul;
	mul.tuso = fac1.tuso * fac2.tuso;
	mul.mauso = fac1.mauso * fac2.mauso;
	return mul;
}

PS div(PS fac1, PS fac2)
{
	PS div;
	div.tuso = fac1.tuso * fac2.mauso;
	div.mauso = fac1.mauso * fac2.tuso;
	return div;
}

PS facMath(PS fac1, PS fac2, char ope)
{
	PS result;
	switch (ope)
	{
		case '+':
			result = add(fac1, fac2);
			break;
		case '-':
			result = subtract(fac1, fac2);
			break;
		case '*':
			result = multi(fac1, fac2);
			break;
		case '/':
			result = div(fac1, fac2);
			break;
	}
	return result;
}

PS reduce(PS fac)
{
	int ucln = std::__gcd(fac.tuso, fac.mauso);
	fac.tuso = fac.tuso / ucln;
	fac.mauso = fac.mauso / ucln;
	return fac;
}

void output(PS fac)
{
	std::cout << fac.tuso << '/' << fac.mauso;
}

int main() 
{
	PS a, b;
	input(a);
	input(b);
	char ope;
	std::cin >> ope;
	if (a.mauso == 0 || b.mauso == 0)
	{
		std::cout << "Khong thoa yeu cau bai toan";
		return 0;
	}
	PS result = facMath(a, b, ope);
	result = reduce(result);
	output(result);
	return 0;	
}
