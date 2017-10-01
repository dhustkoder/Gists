#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>


#ifdef _WIN32
#define CLS() (system("cls"))
#else
#define CLS() (system("clear"))
#endif


int main(void)
{
	char dv[] = "deus vult";
	int i = 0;
	int j = 8;
	for (;;) {
		CLS();
		dv[i] = toupper(dv[i]);
		dv[j] = toupper(dv[j]);
		puts(dv);
		dv[i] = tolower(dv[i]);
		dv[j] = tolower(dv[j]);

		++i;
		--j;

		if (i == 4)
			++i;
		else if (i == 9)
		       i = 0;	

		if (j == 4)
			--j;
		else if (j == -1)
			j = 8;
		
		clock_t clk = clock();

		while ((clock() - clk) < (CLOCKS_PER_SEC / 12))
			;

	}

	return 0;
}



