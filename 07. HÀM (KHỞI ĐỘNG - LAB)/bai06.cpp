/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
if
else
[
###End banned keyword*/


#include <iostream>
using namespace std;

char courseGrade(int score)
{
    switch(

//###INSERT CODE HERE -
        score) {
      case 0 ... 59:
        return 'F';
      case 60 ... 69:
        return 'D';
      case 70 ... 79:
        return 'C';
      case 80 ... 89:
        return 'B';
      case 90 ... 100:
        return 'A';
    }
    return '0';
}

int main() {
  int score;
  cin >> score;
  cout << courseGrade(score);
}
