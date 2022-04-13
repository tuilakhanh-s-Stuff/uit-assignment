#include<iostream>
#include<stdlib.h>
#include<time.h>


int main()
{
	srand(time(NULL));
	int randomnumber, a;
	randomnumber = rand();
    bool flag = true;	
    int count = 0;
    do {
        std::cout << "Moi ban nhap mot so: ";
        std::cin >> a;
        count++;
        if (a > randomnumber) {
            std::cout << "So cua ban da lon hon so chinh xac.\n";
            std::cout << "Moi ban doan lai.\n";
        }
        else if (a < randomnumber) {
            std::cout << "So cua ban da nho hon so chinh xac.\n";
            std::cout << "Moi ban doan lai.\n";
        }
        else if (a == randomnumber)
        {
            std::cout << "Chuc mung ban da doan dung.";
            std::cout << "\nVoi so lan nhap la " << count;
            flag = false;
        }
    } while (flag);
    return 0;
}