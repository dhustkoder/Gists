#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
	static char buffer[3000 * 10000 + 1];

	unsigned long n;
	scanf("%lu%*c", &n);
	const unsigned long len = fread(buffer, 1, sizeof buffer, stdin) + 1;
	buffer[len - 1] = '\n';

	// encryption:
	for (char* p = buffer, *s = buffer; p != &buffer[len]; ++p) {
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
			*p += 3;
		} else if (*p == '\n') {
			char* s1 = s;
			char* s2 = p - 1;
			while (s1 < s2) {
				char tmp = *s1;
				*s1 = *s2;
				*s2 = tmp;
				++s1;
				--s2;
			}
			while (s1 != p) {
				*s1 -= 1;
				++s1;
			}
			s = p + 1;
		}
	}

	buffer[len - 1] = '\0';
	printf("%s", buffer);
	return 0;
}
