/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//###INSERT CODE HERE -
void merge(int *a, int n, int *b, int m, int *c) {
	int indexA = 0;
	int indexB = 0;
	for (int i = 0; i < n + m; i++) {
		if (indexA < n && indexB < m) {
			if (a[indexA] < b[indexB]) {
				c[i] = a[indexA];
				indexA++;
			} else {
				c[i] = b[indexB];
				indexB++;
			}
		} else {
			if (indexA < n) {
				c[i] = a[indexA];
				indexA++;
			} else {
				c[i] = b[indexB];
				indexB++;
			}
		}
	}
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        merge(a, n, b, m, c);
        int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        delete a;
        delete b;
        cout << endl;
    }
}
