#include <stdio.h>


int main(void)
{
	int input;
	scanf("%i", &input);

	while (input != 2002) {
		printf("Senha Invalida\n");
		scanf("%i", &input);
	};
	
	printf("Acesso Permitido\n");	
	return 0;
}
