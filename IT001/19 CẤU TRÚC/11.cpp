/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
using namespace std;

struct DATHUC {
	double a;
	int n;
};

DATHUC* Nhap()
{
	DATHUC *a;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a->a >> a->n;
		a++;
	}
	return a;
}

void Xuat(DATHUC a)
{
}

int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
