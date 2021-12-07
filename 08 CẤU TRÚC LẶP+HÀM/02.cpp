#include <iostream>
#include <algorithm>

void inputTime (int &h, int &m, int &s) {
  std::cin >> h >> m >> s;
}

int toSecond(int h, int m, int s) {
  return h * 3600 + m * 60 + s;
}

void reduceFraction(int &x, int &y) {
  int UCLN;
  UCLN = std::__gcd(x, y);

  x = x / UCLN;
  y = y / UCLN;
}

int main() {
  
  int totalDuration;
  int hourDuration, minuteDuration, secondDuration;
  inputTime(hourDuration, minuteDuration, secondDuration);
  
  int totalWatched;
  int hourWatched, minuteWatched, secondWatched;
  inputTime(hourWatched, minuteWatched, secondWatched);
  
  totalDuration = toSecond(hourDuration, minuteDuration, secondDuration);
  totalWatched = toSecond(hourWatched, minuteWatched, secondWatched);

  reduceFraction(totalWatched, totalDuration);

  std::cout << totalWatched << ' ' << totalDuration;

  return 0;
}
