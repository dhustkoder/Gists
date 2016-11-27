#include <stdio.h>

int main()
{
	
	int input;
	int total = 0;
	int nOfInputs;
	while(1) {
		scanf("%i", &input);
		if(input > 0)
			total+= input, ++nOfInputs;
		else
			break;
	}

	printf("%.2f\n", ((float)total / nOfInputs));
}
