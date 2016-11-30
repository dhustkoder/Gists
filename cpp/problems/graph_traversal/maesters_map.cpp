#include <iostream>
#include <algorithm>

int main()
{
	const auto read_int = [] {
		int i;
		std::cin >> i;
		return i;
	};

	const int width = read_int();
	const int height = read_int();
	int known_offsets_sz = 0;

	char* const vec = new char[(width + 1) * height];
	int* const known_offsets = new int[width * height];
	
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

	for (int y = 0; y < height; ++y)
		std::cin >> &vec[y * width];

	int x = 0, y = 0;
	bool found = false;
	char last_char = 0;

	do {
		const int offset = (y * width) + x;
		const char map_char = vec[offset];
		const char check_char = map_char == '.' ? last_char : map_char;

		if (last_char != check_char) {
			if (is_known_offset(offset)) {
				break;
			} else {
				add_known_offset(offset);
				last_char = check_char;
			}
		}

		switch (check_char) {
		case '>': ++x; break;
		case 'v': ++y; break;
		case '<': --x; break;
		case '^': --y; break;
		case '*': found = true; break;
		default: break;
		}

	} while (!found && x >= 0 && x < width && y >= 0 && y < height);

	if (found) 
		std::cout << "*\n";
	else
		std::cout << "!\n";

	delete[] known_offsets;
	delete[] vec;
	return 0;
}

