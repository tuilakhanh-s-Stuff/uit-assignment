#include "CTime.h"

CTime::CTime(int a, int b, int c) {
  hour = (a < 0 || a > 23) ? 0 : a;
  minutes = (b < 0 || b > 59) ? 0 : b;
  second = (c < 0 || c > 59) ? 0 : c;
}

int CTime::GetTotalSecond() {
  return this->second + this->minutes * 60 + this->hour * 60 * 60;
}

CTime CTime::operator+(const int &x) {
  CTime c;
  int a, b;
  a = (this->second + x) / 60;
  c.second = (this->second + x) % 60;
  b = (this->minutes + a) / 60;
  c.minutes = (this->minutes + a) % 60;
  c.hour = hour + b;
  return c;
}

CTime CTime::operator+(CTime T) { return *this + T.GetTotalSecond(); }

CTime CTime::operator-(const int &x) {
  CTime newCtime;
  int newSecond, newMinutes;

  newSecond = (this->second - x < 0) ? -1 : 0;
  newCtime.second = (newSecond == -1) ? 60 + second - x : second - x;

  newMinutes = (minutes + newSecond) < 0 ? -1 : 0;
  newCtime.minutes = (newMinutes == -1) ? 60 + minutes + newSecond : minutes + newSecond;

  newCtime.hour = newMinutes + hour;
  if (newCtime.hour < 0) {
    newSecond = (-this->second + x < 0) ? -1 : 0;
    newCtime.second = (newSecond == -1) ? 60 - second + x : -second + x;

    newMinutes = (-minutes + newSecond) < 0 ? -1 : 0;
    newCtime.minutes = (newMinutes == -1) ? 60 - minutes + newSecond : -minutes + newSecond;

    newCtime.hour = -(newMinutes - hour);
    if (newCtime.hour == 0) {
      if (newCtime.minutes != 0)
        newCtime.minutes = 0 - newCtime.minutes;
      else if (newCtime.second != 0)
        newCtime.second = 0 - newCtime.second;
    }
    return newCtime;
  }
  return newCtime;
}

CTime CTime::operator-(CTime T) { return *this - T.GetTotalSecond(); }

CTime CTime::operator++(int) { 
	*this = *this + 1; 
	return *this;
}

CTime CTime::operator--(int) { 
	*this = *this - 1; 
	return *this;
}

std::ostream &operator<<(std::ostream &out, const CTime &a) {
  if (a.hour < 0 || a.minutes < 0 || a.second < 0)
    out << "-";
  out << (a.hour < 10 && a.hour >= 0 ? "0" : "") << abs(a.hour) << ":"
      << (a.minutes < 10 && a.minutes >= 0 ? "0" : "") << abs(a.minutes) << ":"
      << (a.second < 10 && a.second >= 0 ? "0" : "") << abs(a.second);
  return out;
}

std::istream &operator>>(std::istream &in, CTime &a) {
  in >> a.hour >> a.minutes >> a.second;
  return in;
}
