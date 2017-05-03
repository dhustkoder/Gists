#include <stdio.h>
#include <stdlib.h>


static int lengthOfLongestSubstring(const char* const str)
{
	int i, j, idx;
	int size = 0;
	int longest = 0;

	for (i = idx = 0; str[i] != '\0'; ++i, ++size) {
		for (j = i - 1; j >= idx; --j) {
			if (str[j] == str[i]) {
				idx = i = j + 1;
				if (size > longest)
					longest = size;
				size = 0;
				break;
			}
		}
	}

	return size > longest ? size : longest;
}


int main(void)
{
	int i;
	const char* const strs[] = { "abcabcbb", "bbbbb", "pwwkew", "dvdf" };
	const int size = sizeof(strs) / sizeof(strs[0]);

	for (i = 0; i < size; ++i)
		printf("%s => %d\n", strs[i], lengthOfLongestSubstring(strs[i]));

	return 0;
}


