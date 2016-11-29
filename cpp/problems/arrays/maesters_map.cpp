#include <iostream>


int main()
{
	int x, y;
	int known_points_sz = 0;
	std::cin >> x >> y;
	char* const vec = new char[(x + 1) * y];
	int* const known_points = new int[x * y];

	const auto is_known_point =
	[&known_points_sz, known_points](const int offset) {
		for (int i = 0; i < known_points_sz; ++i) {
			if (known_points[i] == offset)
				return true;
		}
		return false;
	};
	for (int i = 0; i < y; ++i)
		std::cin >> &vec[i * x];

	int next_x = 0, next_y = 0;
	bool found = false;
	char last_char = 0, new_char = 0;

	do {
		const int offset = (next_y * x) + next_x;
		const char map_char = vec[offset];
		const char check_char = 
		  map_char == '.' ? last_char : (new_char = map_char);

		if (last_char != new_char) {
			if (is_known_point(offset)) {
				break;
			} else {
				known_points[known_points_sz++] = offset;
				last_char = new_char;
			}
		}

		switch (check_char) {
		case '>': ++next_x; break;
		case 'v': ++next_y; break;
		case '<': --next_x; break;
		case '^': --next_y; break;
		case '*': found = true; break;
		}

	} while (!found && 
	        (next_x >= 0 && next_x < x) && 
	        (next_y >= 0 && next_y < y));

	if (found) 
		std::cout << "*\n";
	else
		std::cout << "!\n";

	delete[] vec;
	delete[] known_points;
	return 0;
}

