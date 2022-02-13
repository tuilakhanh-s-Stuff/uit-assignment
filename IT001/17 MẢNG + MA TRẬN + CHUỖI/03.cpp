#include <iostream>
#include <cstring>

bool checkSpecs(char word, char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (word == a[i])
			return true;
	}
	return false;
}

void listWord(char a[], char specs[])
{
	char world2D[1000][1000];
	int i = 0;
	bool flag;
	for (int j = 0, k = 0; j < strlen(a); j++) {
		bool check = checkSpecs(a[j], specs);
    if ((check) && flag) {
      world2D[i++][k] = '\0';
      k = 0;
			flag = false;
    } else if (!check) {
      world2D[i][k++] = a[j];
			flag = true;
    }
  }
	for (int j = 0; j <= i; j++)
	{
		std::cout << world2D[j] << '\n';
	}
}

int main()
{

   char str[1000];
	 char specs[21];
	 std::cin.getline(str,1000);
	 std::cin.getline(specs, 21);
   listWord(str, specs);

   return 0;
}
