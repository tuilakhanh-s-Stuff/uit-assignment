#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int N, first, second, last;
  string demso;
  cin>>N;
  
  vector<string> num_str {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};

  first = N/100;
  second = (N/10) % 10;
  last = N % 10;
  
  demso = num_str[first] + " tram";

  if (N < 100 || N > 999) {
    cout << "NULL";
    return 0;
  }

  if (second == 0 && last == 0) {
    cout<<demso;
    exit(0);
  } else {
    demso = demso + " ";
  }

  switch (second) {
    case 0:
      demso = demso + "le ";
      break;
    case 1:
      demso = demso + "muoi ";
      break;
    default:
      demso = demso + num_str[second] + " muoi";
      break;
  }

  if (last == 0) {
    cout<<demso;
    exit(0);
  } else {
    demso = demso + " ";
  }

  if (second != 0)
    num_str[5] = "lam";
  demso = demso + num_str[last];

  cout<<demso<<"\n";

  return 0;
}
