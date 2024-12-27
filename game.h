#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
void reveal_all_mines(char **rplansza, char **gplansza,int a, int b);
void flood_fill(char **rplansza, char **gplansza, int a, int b,int x, int y);
bool check_for_win(char **rplansza,char **gplansza,int a, int b,int mine_count);
int check_score(char **rplansza,char **gplansza,int a, int b,int mine_count,int lvl);
int game(char **rplansza,int a, int b,int mine_count,int lvl);
#endif