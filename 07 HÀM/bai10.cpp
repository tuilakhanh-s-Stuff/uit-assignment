/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
switch
[
###End banned keyword*/


#include <iostream>
using namespace std;

void getScore(int &n){
  cout << "Enter course score (0<=score<=100): ";
  cin >> n;
  cout << "\nCourse score is " << n << '\n';
}

void printGrade(int score)
{
    char c;
    if (score >= 0 && score <= 59)
      c = 'F';
    else if (score >= 60 && score <= 69)
      c = 'D';
    else if (score >= 70 && score <= 79)
      c = 'C';
    else if (score >= 80 && score <= 89)
      c = 'B';
    else if (score >= 90 && score <= 100)
      c = 'A';
    cout << "Your grade for the course is " << c;
}

//###INSERT CODE HERE -
int main()
{
    int courseScore;
    getScore(courseScore);
    printGrade(courseScore);
    return 0;
}



