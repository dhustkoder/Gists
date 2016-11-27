#include <iostream>
#include <algorithm>
#include <utility>

using DDDCity = std::pair<int, const char*>;

static DDDCity ddds_and_cities[8] = 
{
	{61, "Brasilia"}, {71, "Salvador"},
	{11, "Sao Paulo"}, {21, "Rio de Janeiro"},
	{32, "Juiz de Fora"}, {19, "Campinas"},
	{27, "Vitoria"}, {31, "Belo Horizonte"}
};


int main()
{
	int ddd;
	std::cin >> ddd;
	
	auto itr = std::find_if(ddds_and_cities, ddds_and_cities + 8,
		[](DDDCity &it) { 
			return it.first == ddd; 
		});

	if (itr != ddds_and_cities + 8)
		std::cout << itr->second << std::endl;
	else
		std::cout << "DDD nao cadastrado" << std::endl;
}