#include <stdio.h>


static int getRomanValue(const char c)
{
	const char kRNums[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'  };
	const int kValues[] = {  1,   5,  10,   50, 100, 500, 1000 };
	int i = 0;

	while (kRNums[i] != c)
		++i;

	return kValues[i];
}


static int romanToInt(const char* const str)
{
	int a, b;
	const char* p = str;
	int sum;

	while (*(p + 1) != '\0')
		++p;

	sum = getRomanValue(*p);

	for (--p; p >= str; --p) {
		a = getRomanValue(*p);
		b = getRomanValue(*(p + 1));
		if (a < b)
			sum -= a;
		else
			sum += a;
	}

	return sum;
}


int main(void)
{
	const char* const kRNums[] = {
		"I", "II", "III", "IV", "V",
		"VI", "VII", "VIII", "IX", "X",
		"DCXXI", "MCMXCVI"
	};
	const int kRNumsSize = sizeof(kRNums)/sizeof(kRNums[0]);
	int i;

	for (i = 0; i < kRNumsSize; ++i)
		printf("%s => %d\n", kRNums[i], romanToInt(kRNums[i]));

	return 0;
}

