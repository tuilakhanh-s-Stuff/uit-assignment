#include <iostream>
#include <cstring>

#define SHIFT  1

int main()
{
	char ch[15] = "HelloWorld";
	int make_room_at = 5;
	int room_to_make = 1;

	memmove(
    ch + make_room_at + room_to_make,
    ch + make_room_at,
 15 - (make_room_at + room_to_make)
	);	
	std::cout << ch;
}
