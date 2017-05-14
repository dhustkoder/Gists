#include <stdio.h>
#include <stdlib.h>


static int strStr(const char* const haystack, const char* const needle)
{
	int i, j;

	if (needle[0] == '\0')
		return 0;

	for (i = 0; haystack[i] != '\0'; ++i) {
		if (haystack[i] == needle[0]) {
			j = i + 1;
			while (haystack[j] == needle[j - i] &&
			       haystack[j] != '\0' && needle[j - i] != '\0')
				++j;
			if (needle[j - i] == '\0')
				return i;
		}
	}

	return -1;
}


int main(void)
{
	const char* const str = "nao sei";
	const char* const needle = "sei";
	int idx = strStr(str, needle);

	if (idx != -1)
		printf("%s\n", &str[idx]);


	return 0;
}
