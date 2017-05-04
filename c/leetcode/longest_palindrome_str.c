#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char* longestPalindrome(const char* const s)
{
	char* r;
	int i, j, k;
	int siz, idx;
	int ridx;
	int rsiz = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		for (k = i + 1, j = i - 1; j >= 0 && s[k] == s[j]; ++k, --j) {}

		--k;
		++j;

		siz = (k - j) + 1;
		idx = j;

		for (k = i, j = i - 1; j >= 0 && s[k] == s[j]; ++k, --j) {}

		--k;
		++j;

		if (((k - j) + 1) > siz) {
			siz = (k - j) + 1;
			idx = j;
		}

		if (siz > rsiz) {
			rsiz = siz;
			ridx = idx;
		}
	}

	r = malloc(sizeof(char) * rsiz + 1);
	strncpy(r, s + ridx, rsiz);
	r[rsiz] = '\0';
	return r;
}


int main(void)
{
	const char* const strs[] = { "babad", "bab", "cbbd" };
	char* r;
	int i;

	for (i = 0; i < (int)(sizeof(strs)/sizeof(strs[0])); ++i) {
		r = longestPalindrome(strs[i]);
		printf("%s => %s\n", strs[i], r);
		free(r);
	}

	return 0;
}

