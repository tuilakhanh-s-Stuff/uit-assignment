#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(void) {

  double math, physical, chemical, avg;
  string grade;
  cin>>math>>physical>>chemical;
  avg = (math + physical + chemical) / 3;
  avg = roundf(avg * 100) / 100;

  if (9 <= avg && avg <= 10)
    grade = "XUAT SAC";      
  else if (8 <= avg && avg < 9)
    grade = "GIOI";
  else if (7 <= avg && avg < 8)
    grade = "KHA";
  else if (6 <= avg && avg < 7)
    grade = "TB KHA";
  else if (5 <= avg && avg < 6)
    grade = "TB";
  else if (4 <= avg && avg < 5)
    grade = "YEU";
  else
    grade = "KEM";

  cout<<"DTB = "<<avg<<"\n";
  cout<<"Loai: "<<grade;

  return 0;
}
