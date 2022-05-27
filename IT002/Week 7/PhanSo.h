#include <istream>
#include <ostream>

class PhanSo {
private:
	int TuSo, MauSo;
	void ChuanHoa();
public:
	PhanSo(int = 0, int = 1);
	void Set(int, int);
	PhanSo RutGon();

	friend PhanSo operator+(PhanSo, PhanSo);
	friend PhanSo operator-(PhanSo, PhanSo);
	friend PhanSo operator*(PhanSo, PhanSo);
	friend PhanSo operator/(PhanSo, PhanSo);

	friend bool operator==(PhanSo, PhanSo);
    friend bool operator!=(PhanSo, PhanSo);
    friend bool operator>(PhanSo, PhanSo);
    friend bool operator>=(PhanSo, PhanSo);
    friend bool operator<(PhanSo, PhanSo);
    friend bool operator<=(PhanSo, PhanSo);

	friend std::ostream& operator<<(std::ostream &, PhanSo);
	friend std::istream& operator>>(std::istream &, PhanSo &);
};
