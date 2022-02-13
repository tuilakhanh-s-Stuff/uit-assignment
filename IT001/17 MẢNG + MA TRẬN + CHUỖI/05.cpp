#include <iostream>
#include <string.h>
#define MAX 300

void StringReverse(char *a)
{
  int len;
  for (len = 0; a[len] != '\0'; len++);
  int i = 0, j = 0;
  char temp[MAX];
  for (i = 0; i < len; i++)
  {
    for (j = 0; i < len; j++, i++)
    {
      if (a[i] == ' ')
        break;
      temp[j] = a[i];
    }
    while (j > 0)
    {
      j--;
      a[i - j - 1] = temp[j];
    }
  }
}

int main()
{

	char s[MAX];
	std::cin.getline(s,MAX);
	StringReverse(s);
	std::cout << s << '\n';

	return 0;
}
