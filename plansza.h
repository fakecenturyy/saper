#ifndef PLANSZA_H
#define PLANSZA_H

void print_map(char **tab,int a,int b);
int count_mines(char **tab,int a,int b,int i,int j);
char **plansza_create(int a, int b, int mine_count,int x,int y);
#endif