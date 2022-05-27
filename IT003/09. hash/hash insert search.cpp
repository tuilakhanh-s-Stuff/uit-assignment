/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;

//###INSERT CODE HERE -
int m = 100000008;
int EMPTY = -1;


// Hash function using double hashing
int hashFunc(int key, int i) {
	return (key + i * (key % m)) % m;
}

void insert(int *hashtable, int key) {
	int i = 0;
	int index = hashFunc(key, i);
	while (hashtable[index] != EMPTY) {
		i++;
		index = hashFunc(key, i);
	}
	hashtable[index] = key;
}

int find(int *hashtable, int key) {
	int i = 0;
	int index = hashFunc(key, i);
	while (hashtable[index] != EMPTY) {
		if (hashtable[index] == key) {
			return 1;
		}
		i++;
		index = hashFunc(key, i);
	}
	return 0;
}

int main(){
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int*t = new int [m];
    for (size_t i = 0; i < m; i++)
    {
        t[i] = EMPTY;
    }

    int x, ms, i = 1;
    do {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) insert(t, ms);
        else if (x == 2) cout <<  find(t, ms)  << "\n";
       
        // cerr << " debug " << i++ << " " << x << " " << ms << endl;
    } while (x > 0);
}
