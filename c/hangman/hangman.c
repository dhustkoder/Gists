#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct Game {
	struct Gallow {
		char body[7];
		int errors;
	} gallow;
	const char* const correct_word;
	char* const hidden_word;
} Game;

static const char* const words[] = { "control", "television", "computer" };

static int init_game(Game* game)
{
	srand(time(NULL));
	
	*game = (Game) { .gallow.body = {'\0'}, .gallow.errors = 0 };

	const int word_idx = rand() % (sizeof(words)/sizeof(const char* const));
	
	*((const char**)&game->correct_word) = words[word_idx];
	
	const size_t word_size = sizeof(char) * strlen(game->correct_word);
	
	*((char**)&game->hidden_word) = malloc(word_size + 1);

	if (game->hidden_word == NULL) {
		perror("failed to allocate memory: ");
		return -1;
	}

	memset(game->hidden_word, '_', word_size);
	game->hidden_word[word_size] = '\0';
	return 0;
}

static void free_game(const Game* const game)
{
	free(game->hidden_word);
}

static int increment_gallow(struct Gallow* const gallow)
{
	char* const body = gallow->body;
	switch(++gallow->errors) {
	case 6: body[6] = '\\'; break;
	case 5: body[5] = '/'; break;
	case 4: body[4] = '\\'; break;
	case 3: body[3] = '|'; break;
	case 2: body[2] = '/'; break;
	case 1: body[1] = ')', body[0] = '('; break;
	}

	return gallow->errors < 6 ? 0 : -1;
}


static void draw_game(const Game* const game)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	const char* const body = game->gallow.body;
	printf(" _________\n"
	       "|         |\n"
	       "|        %c %c\n"
	       "|        %c%c%c\n"
	       "|        %c %c\n"
	       "|             \n"
	       "|             ", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6]);

	const char* c = game->hidden_word;
	while (*c != '\0')
		printf("%c ", *c++); // couldn't resist
	putchar('\n');
}

static int update_game(Game* const game)
{
	printf("Enter a letter: ");
	const char input = tolower(getchar());
	while (getchar() != '\n') {}

	const char* correct = game->correct_word;
	char* const hidden = game->hidden_word;
	unsigned char found = 0;
	for (size_t i = 0; correct[i] != '\0'; ++i) {
		if (correct[i] == input) {
			hidden[i] = input;
			found = 1;
		}
	}

	if (!found && increment_gallow(&game->gallow) != 0) {
		draw_game(game);
		printf("######## you lose! ############\n");
		return 1;
	} else if (found && strcmp(game->correct_word, game->hidden_word) == 0) {
		draw_game(game);
		printf("######### you win! ############\n");
		return 1;
	}

	return 0;
}


int main()
{
	Game game;
	if (init_game(&game) != 0)
		return EXIT_FAILURE;
	do 
		draw_game(&game); 
	while (update_game(&game) == 0);

	free_game(&game);
	return EXIT_SUCCESS;
}
