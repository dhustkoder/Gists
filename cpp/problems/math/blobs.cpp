#include <cstdio>

int main()
{
	int ninput;
	float food;
	std::scanf("%d", &ninput);
	for (int i = 0; i < ninput; ++i) {
		std::scanf("%f", &food);
		int days = 0;
		while (food > 1) {
			food /= 2;
			++days;
		}
		std::printf("%d dias\n", days);
	}

	return 0;
}

