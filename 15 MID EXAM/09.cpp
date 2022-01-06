#include <iostream>
#include <string.h>

void removeDupli(char s[])
{
	int index = 0;
	int j;
  for (int i=0; s[i] != '\0'; i++)
	{
		for (j=0; j<i; j++)
			if (s[i] == s[j])
				break;

    if (j == i)
    	s[index++] = s[i];
	}
	s[index] = '\0';
}

void inputArray(char a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	a[n] = '\0';
	// std::cout << a;
}

int countMiss(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if ('A' <= a[i] && a[i] <= 'Z')
			a[i] = tolower(a[i]);
	}
	removeDupli(a);
	int count = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		if ('a' <= a[i] && a[i] <= 'z')
			count++;
	}
	return 26 - count;
}

int main()
{
	char a[1001];
	int n;
	inputArray(a, n);
	std::cout << countMiss(a);
	return 0;
}
