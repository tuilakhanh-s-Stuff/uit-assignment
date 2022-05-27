#include <istream>
#include <ostream>

class CTime {
private:
  int second, minutes, hour;
  int GetTotalSecond();
public:
  CTime(int = 0, int = 0, int = 0);
  CTime operator+(const int &);
  CTime operator+(CTime);
  CTime operator-(const int &);
  CTime operator-(CTime);
  CTime operator++(int);
  CTime operator--(int);
  friend std::ostream &operator<<(std::ostream &out, const CTime &a);
  friend std::istream &operator>>(std::istream &in, CTime &a);
};
