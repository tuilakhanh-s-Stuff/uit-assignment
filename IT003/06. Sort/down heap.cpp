#include <iostream>

#define fast_io    std::ios_base::sync_with_stdio(false)

void heapify(int *&a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    if (l < n && a[l] > a[largest])
        largest = l;
 
    if (r < n && a[r] > a[largest])
        largest = r;
 
    if (largest != i) {
        std::swap(a[i], a[largest]);
 
        heapify(a, n, largest);
    }
}
 
void buildHeap(int *a, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void Sort(int *a, int n) {
 	for (int i = n - 1; i >= 0; i--) {
        std::swap(a[0], a[i]);
 
        heapify(a, i, 0);
    }
}

void removeRoot(int *a, int &n) {
	if (n == 0)
		return;
 	std::swap(a[0], a[n-1]);
	heapify(a, n-1, 0);
	n--;
}

void removeRootAll(int *a, int &n) {
 	auto max = a[0];
	while (a[0] == max) {
 	 	std::swap(a[0], a[n-1]);
	 	heapify(a, n-1, 0);
	 	n--;
		if (n == 0)
		 	return;
	}
}

void reduceRoot(int *a, int n, int x) {
	a[0] -= x;
	heapify(a, n-1, 0);
}

void reduceRootAll(int *a, int n, int x) {
	int max = a[0];
	while (a[0] == max) {
		a[0] -= x;
		heapify(a, n-1, 0);
	}
}

void Input(int *&a, int &n) {
 	int quantity, option, x;
	std::cin >> n;
	std::cin >> quantity;
	a = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	buildHeap(a, n);
	for (int i = 0; i < quantity; i++) {
 	 	std::cin >> option;
		if (n == 0)
			break;
		switch (option) {
			case -1:
			 	removeRoot(a, n);
				break;
			case -2:
			 	removeRootAll(a, n);
			 	break;
			case -3:
				std::cin >> x;
			  	reduceRoot(a, n, x);	
			 	break;
			case -4:
			 	std::cin >> x;
				reduceRootAll(a, n, x);
				break;
		}
	}
}

void Output(int *a, int n) {
	for (int i = n -1; i >= 0; i--) {
		std::cout << a[i] << '\n';
	}
}

int main() {
	int *a, n;

    std::cin.tie(NULL);
    fast_io;
	Input(a, n);
	Sort(a, n);
	Output(a, n);
 	
	return 0;
}
