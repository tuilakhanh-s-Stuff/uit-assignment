#include <istream>
#include <ostream>

class Interger {
private:
	int number;
public:
 	Interger(int = 0);
	~Interger() { }

	friend Interger operator+(Interger, Interger);
	friend Interger operator-(Interger, Interger);
	friend Interger operator*(Interger, Interger);
	friend Interger operator/(Interger, Interger);

	friend bool operator==(Interger, Interger);
    friend bool operator!=(Interger, Interger);
    friend bool operator>(Interger, Interger);
    friend bool operator>=(Interger, Interger);
    friend bool operator<(Interger, Interger);
    friend bool operator<=(Interger, Interger);

	friend std::istream& operator>>(std::istream &, Interger &);
	friend std::ostream& operator<<(std::ostream &, const Interger &);
};
