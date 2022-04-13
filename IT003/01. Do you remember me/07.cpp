/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/
#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void do_it()
{
	int n;
	cin >> n;
	int* a = new int[n];	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n-1; i >= 0; i--)
		cout << a[i] << '\n';
}

int main(){
	//Hai lenh sau co tac dung tang toc do nhap xuat
	//Vi bai nay viec nhap xuat thuc hien voi du lieu rat lon
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

	//Ham nay se thay ham main thuc hien yeu cau de bai
	do_it();
}
