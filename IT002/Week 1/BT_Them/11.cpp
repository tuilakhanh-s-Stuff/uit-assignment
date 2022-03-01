#include <iostream>
#include <string.h>

void KV(char a[], double& DTB)
{
	for(int i=0; i<strlen(a); i++)
	if (a[i] == 'A' || a[i] == 'a')
		DTB = DTB + 1.5;
	else if (a[i] == 'B' || a[i] == 'b')
		DTB = DTB + 1;
	else if (a[i] == 'C' || a[i] == 'c')
		DTB = DTB + 0.5;
}

void DT(int b, double& DTB)
{
	if (b == 1)
		DTB = DTB + 1.5;
	else if (b == 2)
		DTB = DTB + 1;
	else if (b == 3)
		DTB = DTB + 0.5;
}

int main()
{
	double Mon1, Mon2, Mon3;
	double DTB;
	int b;
	char a[30];
	std::cout << "Mon thu nhat: ";
	std::cin >> Mon1; 
	std::cout << "Mon thu hai: ";
	std::cin >> Mon2;
	std::cout << "Mon thu ba: ";
	std::cin >> Mon3;


	std::cout << "Nhap khu vuc cua ban: ";
    std::cin >> a;
	std::cout << "Ban thuoc doi tuong nao: "; 
    std::cin >> b;


	if (Mon1 <= 1 || Mon2 <= 1 || Mon3 <= 1)
	{
		std::cout << "diem liet";
	}
	else
	{
		DTB = (Mon1 + Mon2 + Mon3) / 3;
		KV(a, DTB);
		DT(b, DTB);
		if (DTB >= 10) 
            std::cout << "Diem trung binh cua ban la: 10";
		else 
            std::cout << "Diem trung binh cua ban la: " << DTB;
	}
	return 0;
}