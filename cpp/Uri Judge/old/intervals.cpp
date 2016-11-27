#include <iostream>

int main()
{
	constexpr const char* const intervalsText[] {
		"[0,25]", "(25,50]", "(75,100]"
	};

	const auto getInterval = [](const float x)->const char* {
		if (x < 0.0)
			return -1;
		else if (x <= 25.0)
			return intervalsText[0];
		else if (x <= 50.0)
			return intervalsText[1];
		else if (x > 75.0 && x <= 100.0)
			return internalsText[2];
		else
			return nullptr;
	};

	float x;
	std::cin >> x;

	const auto interval = getInterval(x);

	if (internal != nullptr)
		std::cout << "Intervalo " << interval << std::endl;
	else
		std::cout << "Fora de intervalo" << std::endl;

	return 0;
}
