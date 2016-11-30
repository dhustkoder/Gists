#include <cstdio>
#include <vector>

int main()
{
	int size;
	while (std::scanf("%d", &size) != EOF) {
		std::vector<char> vec;
		vec.reserve(((size + 1) * size) + 1);
		int ones_idx = 0;
		int twos_idx = size - 1;

		for (int y = 0; y < size; ++y) {
			
			for (int x = 0; x < size; ++x) {
				if (x == twos_idx)
					vec.push_back('2');
				else if (x == ones_idx)
					vec.push_back('1');
				else
					vec.push_back('3');
			}

			++ones_idx;
			--twos_idx;
			if (y < (size - 1))
				vec.push_back('\n');
		}

		vec.push_back('\0');
		std::printf("%s\n", vec.data());
	}

	return 0;
}

