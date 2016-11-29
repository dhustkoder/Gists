#include <iostream>
#include <string>

int main()
{
	std::string dollars;
	dollars.reserve(15);
	int cents;

	while (std::cin >> dollars >> cents) {
		for (int i = dollars.size() - 3; i > 0; i -= 3)
			dollars.insert(i, ",");

		std::cout << "$" << dollars << ".";
		if (cents < 10)
			std::cout << '0' << cents;
		else
			std::cout << cents;
		std::cout << '\n';
	}

	return 0;
}

