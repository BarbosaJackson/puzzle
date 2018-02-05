#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define CLEAR_SCREEN() printf("\e[1;1H\e[2J");  

#define MOVE_UP 119 // w
#define MOVE_LEFT 97  // a
#define MOVE_RIGHT 100 // d
#define MOVE_DOWN 115 // s

/*
 * função encontrada em: cboard.cprogramming.com/faq-board/27714-faq-there-getch-conio-equivalent-linux-unix.html
 * é equilante ao getch da lib conio.h do windows, ou seja, lê um caracter sem que ele seja printado na tela e 
 * sem precisar de um enter para completar o processo de leitura, dando assim, uma dinâmica melhor, 
 * pois é só digitar e a jogada se realiza
 */

int mygetch(void) {
  struct termios oldt, newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}