#include <stdlib.h>
#include <stdio.h>
#include "plansza.h"
#include <print_map.h>
struct gracz{
    int score;
    char name;
}
int main(){
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
    char plansza=plansza_create(a,b,mine_count);
    print_map(plansza,a,b);
    return 0;
}
