#include "game.h"

int main(void) {
	int n = 0;

	init_table();
	print_table();

	while(n != 1) {
		check_move(tolower(getchar()));
		print_table();
		n = check_win();
	}
	return 0;
}