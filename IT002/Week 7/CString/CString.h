#include <string>
#include <istream>
#include <ostream>


class CString {
private:
	std::string String;
public:
    CString() { }
    ~CString() { }

    friend std::istream& operator>>(std::istream&, CString&);
    friend std::ostream& operator<<(std::ostream&, const CString&);

    CString operator+(const CString&);
    void operator=(const CString&);
    bool operator<(const CString&);
    bool operator<=(const CString&);
    bool operator>(const CString&);
    bool operator>=(const CString&);
    bool operator==(const CString&);
    bool operator!=(const CString&);
};
