#include <stdlib.h>
#include <stdio.h>
#include "print_map.h"
#include <stdbool.h>
void reveal_all_mines(char **rplansza, char **gplansza,int a, int b){
    for(int i=0; i<a;i++){
        for (int j=0;j<b;j++){
            if (rplansza[i][j]=='*')    gplansza[i][j]=rplansza[i][j];
        }
    }
}
void flood_fill(char **rplansza, char **gplansza, int a, int b,int x, int y){
    if(x>a||x<0||x>b||x<0)  return;
    if(gplansza[x][y]!='.')   return;
    if (rplansza[x][y] !='0')  {
        gplansza[x][y]=rplansza[x][y];
        return;}
    gplansza[x][y]=rplansza[x][y];
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++) {
        flood_fill(rplansza, gplansza, a, b, x + dx[i], y + dy[i]);
    }
}
bool check_for_win(char **rplansza,char **gplansza,int a, int b,int mine_count){
    int check=0;
    for(int i=0; i<a;i++){
        for (int j=0;j<b;j++){
            if (rplansza[i][j]!=gplansza[i][j])    check++;
        }
    }
    return (check=mine_count);
}
int check_score(char **rplansza,char **gplansza,int a, int b,int mine_count,int lvl){
    int score=0;
    for(int i=0; i<a;i++){
        for (int j=0;j<b;j++){
            if (rplansza[i][j]!=gplansza[i][j]) score++;
        }
    }
    score-=mine_count;
    score*=lvl;
    return score;
}
int game(char **rplansza,int a, int b,int mine_count,int lvl){
    if (lvl==4) lvl=1;
    char **gplansza = (char **)malloc(a * sizeof(char *));
    for (int i = 0; i < a; i++) {
        gplansza[i] = (char *)malloc(b * sizeof(char));
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            gplansza[i][j]='.';
        }
    }
    bool gg=false;
    int x,y;
    while (!gg){
        printf("Input: \n");
         if (scanf("%d %d", &x, &y) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        x-=1;
        y-=1;
        if(x>a||x<0||x>b||x<0){
            printf("Podaj poprawne wspolrzedne pola \n");
            scanf("%d, %d ",&x,&y);
        }
        switch (rplansza[x][y]){
            case 'f':{
            print_map(gplansza,a,b);
                printf("usun flage aby odkryc pole \n");
                break;}
            case '*':{
                reveal_all_mines(rplansza,gplansza,a,b);
                print_map(gplansza,a,b);
                printf("PRZEGRANA\n");
                gg=true;
                break;
            }
            case '0':{
                flood_fill(rplansza,gplansza,a,b,x,y);
                print_map(gplansza,a,b);
                break;
            }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':{
                gplansza[x][y]=rplansza[x][y];
                print_map(gplansza,a,b);
            }
            }
        check_for_win(rplansza,gplansza,a,b,mine_count);
        }
    int score;
    score=check_score(rplansza,gplansza,a,b,mine_count,lvl) ;
    return score;
    }
