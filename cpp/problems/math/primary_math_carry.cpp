#include <cstdio>
#include <iostream>
#include <algorithm>

int main()
{
	while (true) {
		long int first, second;
		std::cin >> first >> second;
		if (!first && !second)
			break;

		int carry = 0;
		int carry_cnt = 0;
		const long int max = std::max(first, second);

		for (long int i = 10 ;; i *= 10) {
			const long int first_mod = first % i;
			const long int second_mod = second % i;
			const long int divisor = i / 10;
			const int first_num = first_mod / divisor;
			const int second_num = second_mod / divisor;
			if ((first_num + second_num + carry) > 9) {
				carry = 1;
				++carry_cnt;
			} else {
				carry = 0;
			}

			if (i > max)
				break;
		}

		if (carry_cnt == 0)
			std::cout << "No carry operation.\n";
		else if (carry_cnt == 1)
			std::cout << "1 carry operation.\n";
		else if (carry_cnt > 1)
			std::cout << carry_cnt << " carry operations.\n";
	}

	return 0;
}

