#include "CDate.h"
#include <iostream>

int dictDayMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dictDayMonthLeap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

CDate::CDate(int a, int b, int c) {
	Day = a;
	Month = b;
	Year = c;
}

bool CDate::isLeapYear() {
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	 	return true;
	return false;
}

long CDate::CDateToDay() {
 	long long DayCount = 0;
	for (int  i = 0; i < this->Year; i++) {
		if (isLeapYear())
		 	DayCount += 366;
		else
		 	DayCount += 365;
	}
	for (int i = 0; i < Month; i++) {
		if (i == 2 && isLeapYear())
		 	DayCount += dictDayMonthLeap[i];
		else
		 	DayCount += dictDayMonth[i];
	}
	
	return Day + DayCount;
}

bool CDate::Check()
{
    if (Year < 0 )
		std::cout << "Nam nhap vao khong hop le!\n"; 
        return false;
	if (Month <= 0 || Month > 12)
		std::cout << "Thang nhap vao khong hop le!\n";
 	 	return false;
    if (this->isLeapYear())
    {
        switch (Month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if (Day > 31 || Day <= 0) {
				std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        case 2:
        {
            if (Day > 29 || Day <= 0) {
			 	std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if (Day > 30 || Day <= 0 ) {
			 	std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        }
    }
    else
    {
        switch (Month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if (Day > 31 || Day <= 0) {
			 	std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        case 2:
        {
            if (Day > 28 || Day <= 0) {
			 	std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if (Day > 30 || Day <= 0) {
				std::cout << "So ngay cua thang khong hop le!\n";
                return false;
			}
            break;
        }
        }
    }
    return true;
}

CDate CDate::ChuanHoa() {
 	if (Day >= 0) {
		if (this->isLeapYear()) {
			if (Day - dictDayMonthLeap[Month] <= 0)
			 	return *this;
			else {
				while (Day > dictDayMonthLeap[Month]) {
 	 	 	 	 	Day -= dictDayMonthLeap[Month];
					Month++;
					if (Month > 12) {
 	 	 	 	 	 	Month = 1;
						Year++;
						return CDate::ChuanHoa();
					}
				}
			}
		} else {
			if (Day - dictDayMonth[Month] <= 0)
 	 	 	 	return *this;
			else {
				while (Day > dictDayMonth[Month]) {
 	 	 	 	 	Day -= dictDayMonth[Month];
					Month++;
					if (Month > 12) {
 	 	 	 	 	 	Month = 1;
						Year++;
						return CDate::ChuanHoa();
					}
				}
		 	}
		}
	} else {
		if (this->isLeapYear()) {
 	 	 	if (Day + dictDayMonthLeap[Month] >= 0) {
				Day += dictDayMonthLeap[Month];
				return *this;
			} else {
				while (std::abs(Day) > dictDayMonthLeap[Month]) {
					Day += dictDayMonthLeap[Month];
					Month--;
					if (Month < 1) {
						Month = 13;
						Year--;
						return CDate::ChuanHoa();
					}
				}
			}
		} else {
 	 	 	if (Day + dictDayMonth[Month] >= 0) {
				Day += dictDayMonth[Month];
				return *this;
			} else {
				while (std::abs(Day) > dictDayMonth[Month]) {
					Day += dictDayMonth[Month];
					Month--;
					if (Month < 1) {
						Month = 13;
						Year--;
						return CDate::ChuanHoa();
					}
				}
			}
		}
	}	
	return *this;
}

std::istream &operator>>(std::istream &is, CDate &d)
{
	bool Check = true;
    do
    {
        std::cout << "Nhap ngay: ";
        is >> d.Day;
		std::cout << "Nhap thang: ";
        is >> d.Month;
		std::cout << "Nhap nam: ";
        is >> d.Year;
	 	Check = d.Check();	
        if (Check)
            std::cout << "Vui Long Nhap Lai!\n";
    } while (Check);
    return is;
}

std::ostream &operator<<(std::ostream &os, CDate d)
{
	d = d.ChuanHoa();
    os << "Ngay " << d.Day << " thang " << d.Month << " nam " << d.Year << '\n';
    return os;
}

CDate operator+(CDate a, int b)
{
    return CDate(a.Day + b, a.Month, a.Year);
}
CDate operator-(CDate a, int b)
{
    return CDate(a.Day - b, a.Month, a.Year);
}
CDate CDate::operator++(int)
{
    Day++;
    return *this;
}
CDate CDate::operator--(int)
{
    Day--;
    return *this;
}

long operator-(CDate a, CDate b) {
	return a.CDateToDay();
}
