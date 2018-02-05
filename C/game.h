#include "mylibs.h"
#include <ncurses.h>

char map[3][3];
int i_white, j_white;

void init_game(void);
void init_table(void);
void print_table(void);
void check_move(char m);
int check_win(void);

void init_game(void) {
	int i, n, max;
	srand(100);
	max = rand() % 5000000;
	for(i = 0; i < max; i++) {
		n = rand() % 4;
		if(n == 1) {
			check_move('w');
		} else if(n == 2) {
			check_move('a');
		} else if(n == 3) {
			check_move('s');
		} else if(n == 4) {
			check_move('d');
		}
	}
}

void init_table(void) {
	int i, j, qtd=0;
	i_white = j_white = 2;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			map[i][j] = (qtd == 8 ? '#' : (qtd+1) + '0');
			qtd++;
		}
	}
	init_game();
}

void print_table(void) {
	int i, j;
	printf("\e[1;1H\e[2J");	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("A -> LEFT\nS -> DOWN\nD -> RIGHT\nW -> UP\n");
}

void check_move (char m) {
	char aux;
	if(m == MOVE_UP && i_white > 0 )  {
		aux = map[i_white-1][j_white];
		i_white--;
		map[i_white][j_white] = '#';
		map[i_white+1][j_white] = aux;
	}
	if(m == MOVE_RIGHT && j_white < 2) {
		aux = map[i_white][j_white+1];
		j_white++;
		map[i_white][j_white] = '#';
		map[i_white][j_white-1] = aux;	
	}
	if(m == MOVE_LEFT && j_white > 0) {
		aux = map[i_white][j_white-1];
		j_white--;
		map[i_white][j_white] = '#';
		map[i_white][j_white+1] = aux;
	}
	if(m == MOVE_DOWN && i_white < 2) {
		aux = map[i_white+1][j_white];
		map[++i_white][j_white] = '#';
		map[i_white-1][j_white] = aux;
	}
}

int check_win(void)  {
	int i, j, k = 1;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(k+'0' == map[i][j]) k++;
		}
	}
	return (k == 9 ? 1 : 0);
}