#include <iostream>
#include <unordered_map>
#include <string>

#define fast_io


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fast_io;

	std::unordered_map<std::string, std::string> d;
	std::unordered_map<std::string, std::string>::const_iterator temp;

	std::string world, translation;
	int m, n;
	std::cin >> m >> n;
	while (n--)
	{
		std::cin.ignore();
		std::cin >> world >> translation;
		d.insert(std::pair<std::string, std::string>(translation, world));
	}
	while (m--) {
		std::cin >> translation;
		temp = d.find(translation);
		if (temp != d.end())
			std::cout << temp->second << '\n';
		else
			std::cout << "eh" << '\n';
	}
	return 0; 
}
