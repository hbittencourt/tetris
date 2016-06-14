#ifndef BIB_H
#define BIB_H

void abertura();

void recordes(void);

void alarm_handler (int signal __attribute__ ((unused)));

int fits_in (int *shape, int pos);

void place (int *shape, int pos, int b);

int *next_shape (void);

void game_over();

void arq(char jogador[], int points, int level);

void show_online_help (void);

int tty_break (void);

int tty_fix (void);

#endif

