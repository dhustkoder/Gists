#include <stdio.h>
#include <stdlib.h>


int main(void)
{

	int gremio_goals;
	int inter_goals;
	int opt;

	int grenais = 0;
	int gremio_score = 0;
	int inter_score = 0;
	int draws = 0;

	do {
		
		scanf("%d %d", &inter_goals, &gremio_goals);
		++grenais;

		if (inter_goals == gremio_goals)
			++draws;
		else if (inter_goals > gremio_goals)
			++inter_score;
		else
			++gremio_score;

		puts("Novo grenal (1-sim 2-nao)");
		scanf("%d", &opt);

	} while (opt == 1);
	
	printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n%s\n",
		grenais, inter_score, gremio_score, draws,
		inter_score == gremio_score ? "Nao houve vencedor"
		: inter_score > gremio_score ? "Inter venceu mais"
		: "Gremio venceu mais");


	return EXIT_SUCCESS;
}

