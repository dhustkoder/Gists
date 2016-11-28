#include <stdio.h>


int main()
{
	while(1) {
		int input;
		scanf("%i", &input);
		if(input != 2002) {
			printf("Senha Invalida\n");
		} else {
			printf("Acesso Permitido\n");
			break;
		}
	}
	
    return 0;
}
