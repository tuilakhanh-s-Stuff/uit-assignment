#include <istream>
#include <ostream>

class CDate {
private:
	int Day, Month, Year;
	CDate ChuanHoa();
	bool isLeapYear();
	long CDateToDay();
public:
	CDate(int = 0, int = 0, int = 0);
 	~CDate() { }
 	bool Check();
	friend std::istream &operator>>(std::istream &, CDate &);
 	friend std::ostream &operator<<(std::ostream &, CDate);

 	friend CDate operator+(CDate, int);
    friend CDate operator-(CDate, int);
    friend long operator-(CDate, CDate);
    CDate operator++(int);
    CDate operator--(int);	
};
