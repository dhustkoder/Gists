#include <iostream>
#include <algorithm>
#include <utility>

int main()
{

	constexpr const int ddds[8] { 61, 71, 11, 21, 32, 19, 27, 31 };
	constexpr const char* const cities[8] {
		"Brasilia", "Salvador", "Sao Paulo",
		"Rio de Janeiro", "Juiz de Fora", "Campinas",
		"Vitoria", "Belo Horizonte"
	};

	int ddd;
	std::cin >> ddd;
	const auto itr = std::find(std::begin(ddds), std::end(ddds), ddd);
	if (itr != std::end(ddds))
		std::cout << cities[itr - std::begin(ddds)] << std::endl;
	else
		std::cout << "DDD nao cadastrado" << std::endl;
}
