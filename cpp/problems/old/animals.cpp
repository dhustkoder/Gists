#include <cstring>
#include <iostream>

constexpr const char* const vert = "vertebrado";
constexpr const char* const ave = "ave";
constexpr const char* const mami = "mamifero";
constexpr const char* const carn = "carnivoro";
constexpr const char* const oni = "onivoro";
constexpr const char* const herb = "herbivoro";
constexpr const char* const inver = "invertebrado";
constexpr const char* const inset = "inseto";
constexpr const char* const anel = "anelideo";
constexpr const char* const hema = "hematofago";

struct Animal {
	constexpr Animal(const char* const d1, const char* const d2,
		const char* const d3, const char* const name)
		: descriptions { d1, d2, d3 }, name { name }
	{
	}
	const char* const descriptions[3];
	const char* const name;
};


constexpr const Animal animals[8] = {
	{vert, ave, carn, "aguia"},
	{vert, ave, oni, "pomba"},
	{vert, mami, oni, "homem"},
	{vert, mami, herb, "vaca"},
	{inver, inset, hema, "pulga"},
	{inver, inset, herb, "lagarta"},
	{inver, anel, hema, "sanguessuga"},
	{inver, anel, oni, "minhoca"}

};

int main()
{
	std::string input[3];
	std::cin >> input[0] >> input[1] >> input[2];

	int inputIndex = 0;
	const Animal* rightAnimal = nullptr;
	for (auto& animal : animals) {
		bool isIt = true;
		for (const char* const str : animal.descriptions) {
			if (std::strcmp(str, input[inputIndex++].c_str()) != 0) {
				isIt = false;
				inputIndex = 0;
				break;
			}
		}

		if (isIt) {
			rightAnimal = &animal;
			break;
		}
	}
	
	if(rightAnimal != nullptr)
		std::cout << rightAnimal->name << std::endl;
}
