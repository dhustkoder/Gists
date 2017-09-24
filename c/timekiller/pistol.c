#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#define CLS() (system("cls"))
#else
#define CLS() (system("clear"))
#endif


static const char* const gun = 
	"====================================\n"
	"==================================  \n"
	"====================================\n"
	"===== \\   |\n"
	"=====_____|\n"
	"=====\n"
	"=====\n"
	"=====\n"
	"=====\n"
	"=====\n"
	"=====\n";

static char buf[1024];

int main(void)
{
	char c;
	int i;
	clock_t clk;

	for (;;) {
		CLS();
		printf("%s", gun);

		c = getchar();
		if (c == 'q')
			break;
		
		for (i = 0; i < 64; ++i) {
			CLS();
			memset(buf, 0, sizeof(buf));
			memcpy(buf, gun, 71);
			memset(buf + 71, ' ', i);
			strcat(buf, "=>");
			strcat(buf, "\n");
			strcat(buf, gun + 74);

			if (i < 12)
				buf[117 + i] = '|';

			printf("%s", buf);
			
			clk = clock();
			while ((clock() - clk) < (CLOCKS_PER_SEC / 32))
				;
		}
	}


	return EXIT_SUCCESS;
}
