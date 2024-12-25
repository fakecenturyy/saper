#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_map(char **tab,int a,int b){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%c ",tab[i][j]);
        }
        printf("\n");
    }
}
int count_mines(char **tab,int a,int b,int i,int j){
    int sum=0;
    for(int x=-1;x<=1;x++){
        for(int y=-1;y<=1;y++){
            int nj=j+y;
            int ni=i+x;
            if (ni<a && nj<b && ni>=0 && nj>=0){
                if (tab[ni][nj] == '*') {
                    sum+=1;}
        }
    }
    }
    return sum;
}
char** plansza_create(){
    srand(time(NULL));
    int a, b, mine_count,lvl;
    printf("Wybierz pozmiom trudnosci \n 1-latwy    2-sredni    3-trudny    4-wlasny\n");
    scanf("%d", &lvl);
    switch(lvl){
        case 1:
            a=9;
            b=9;
            mine_count=10;
            break;
        case 2:
            a=16;
            b=16;
            mine_count=40;
            break;
        case 3:
            a=16;
            b=30;
            mine_count=99;
            break;
        case 4:
            printf("Podaj liczbe kolumn, wierszy oraz min\n");
            scanf("%d %d %d",&a,&b,&mine_count);
    }
    char **tab = (char **)malloc(a * sizeof(char *));
    for (int i = 0; i < a; i++) {
        tab[i] = (char *)malloc(b * sizeof(char));
    }
    while(mine_count>0){
        int x,y;
        x=rand()%a;
        y=rand()%b;
        if (tab[x][y]!='*'){
             tab[x][y]='*';
             mine_count--;
             }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
                if (tab[i][j] != '*') tab[i][j]=count_mines(tab,a,b,i,j)+'0';
            }
        }
    print_map(tab,a,b);
    return tab;
}