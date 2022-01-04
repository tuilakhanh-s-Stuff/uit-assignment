#include <iostream>
#include <string>

struct PROVINCE {
	int ID;
	std::string name;
	int pop;
	float area;
};

void inputArrayProvinces(PROVINCE a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i].ID;
		std::cin.ignore();
		std::getline(std::cin, a[i].name);
		std::cin >> a[i].pop;
		std::cin >> a[i].area;
	}
}

int getMaxPos(PROVINCE a[], int n)
{
	int pos = 0;
	int max = a[0].area;
	for (int i = 1; i < n; i++)
	{
		if (max < a[i].area)
		{
			max = a[i].area;
			pos = i;
		}
	}
	return pos;
}

bool checkLastWorld(PROVINCE a[], std::string s, int pos)
{
	std::string name = a[pos].name.substr(a[pos].name.find_last_of(" ") + 1);
	// std::cout << a[pos].name << name << '\n';
	if (name == s)
		return true;
	else
		return false;
}

int main()
{
	PROVINCE a[100];
	int n;
	inputArrayProvinces(a, n);
	std::string s;
	std::cin >> s;
	int pos = getMaxPos(a, n);
	std::cout << (checkLastWorld(a, s, pos) ? "YES" : "NO");
	return 0;
}

