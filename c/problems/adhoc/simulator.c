#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define true ((bool)1)
#define false ((bool)0)


#define VARS_SIZE (2017)


static int vars_idx = 0;
static char vars_names[VARS_SIZE][9];
static long vars_values[VARS_SIZE];


static bool isletter(const char c)
{
	return c >= 'a' && c <= 'z';
}


static long* getvar(char* const nameptr, char** const endptr)
{
	char name[9];
	int i;

	for (i = 0; isletter(nameptr[i]); ++i)
		name[i] = nameptr[i];

	name[i] = '\0';
	*endptr = nameptr + i;

	for (i = 0; i < vars_idx; ++i)
		if (strcmp(name, vars_names[i]) == 0)
			return &vars_values[i];

	strcpy(vars_names[vars_idx], name);
	return &vars_values[vars_idx++];
}


int main(void)
{
	long i, num1, num2;

	long* var = NULL;
	char* endptr = NULL;

	size_t size = 32;
	char* buffer = malloc(sizeof(char) * size);

	while (getline(&buffer, &size, stdin) != -1) {
		i = 0;
		var = getvar(&buffer[i], &endptr);
		i += (endptr - &buffer[i]) + 4;

		if (isletter(buffer[i]))
			num1 = *getvar(&buffer[i], &endptr);
		else
			num1 = strtol(&buffer[i], &endptr, 10);

		i += (endptr - &buffer[i]);

		if (buffer[i] == ' ') {
			i += 3;
			if (isletter(buffer[i]))
				num2 = *getvar(&buffer[i], &endptr);
			else
				num2 = strtol(&buffer[i], &endptr, 10);

			*var = num1 + num2;

		} else {
			*var = num1;
		}
	}

	printf("%ld\n", var != NULL ? *var : 0);
	free(buffer);
	
	return EXIT_SUCCESS;
}

