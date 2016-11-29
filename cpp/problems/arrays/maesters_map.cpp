#include <iostream>
#include <algorithm>

int main()
{
	int x, y;
	int known_offsets_sz = 0;
	std::cin >> x >> y;
	char* const vec = new char[(x + 1) * y];
	int* const known_offsets = new int[x * y];
	
	const auto is_known_offset = 
	[&known_offsets_sz, known_offsets](const int offset) {
		const auto begin = &known_offsets[0];
		const auto end = begin + known_offsets_sz;
		return std::find(begin, end, offset) != end;
	};
	const auto add_known_offset =
	[&known_offsets_sz, known_offsets](const int offset) {
		known_offsets[known_offsets_sz++] = offset;
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
			if (is_known_offset(offset)) {
				break;
			} else {
				add_known_offset(offset);
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

	delete[] known_offsets;
	delete[] vec;
	return 0;
}

