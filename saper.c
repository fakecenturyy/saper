#include <stdlib.h>
#include <stdio.h>
#include "print_map.h"
#include "game.h"
#include <unistd.h>
#include <process.h>
#include <string.h>
FILE *fptr;
int compare(const void *a, const void *b) {
    struct gracz *graczA = (struct gracz *)a;
    struct gracz *graczB = (struct gracz *)b;
    return graczB->score - graczA->score; 
}

int main(int argc, char *argv[]) {
    struct gracz player = {0, ""}; // Initialize player structure
    int a = 0, b = 0, mine_count = 0, lvl = 0;
    int opt;
    int f=0;
    while ((opt = getopt(argc, argv, "-f")) != -1) {
        switch (opt) {
            case 'l':
                f=1;
                break;
            default:
                return EXIT_FAILURE;
        }
    }

    if (lvl == 0) {
        printf("Wybierz poziom trudnosci \n 1-latwy    2-sredni    3-trudny    4-wlasny\n");
        scanf("%d", &lvl);
    }

    switch (lvl) {
        case 1:
            a = 9;
            b = 9;
            mine_count = 10;
            break;
        case 2:
            a = 16;
            b = 16;
            mine_count = 40;
            break;
        case 3:
            a = 16;
            b = 30;
            mine_count = 99;
            break;
        case 4:
            if (a == 0 || b == 0 || mine_count == 0) {
                printf("Podaj liczbe kolumn, wierszy oraz min\n");
                scanf("%d %d %d", &a, &b, &mine_count);
            }
            break;
        default:
            printf("Nieprawidlowy poziom trudnosci\n");
            return EXIT_FAILURE;
    }

    if (player.name[0] == '\0') {
        printf("Podaj nazwe gracza: ");
        scanf("%49s", player.name);
    }
    player.score=game(a,b,mine_count,lvl);
    printf("Player: %s\n", player.name);
    printf("Score: %d\n", player.score);
    fptr=fopen("wyniki.txt","a");
    fprintf(fptr,"%s %d \n",player.name,player.score);
    fclose(fptr);
    fptr=fopen("wyniki.txt","r");
    int line=0;
    char c;
    for (c = getc(fptr); c != EOF; c = getc(fptr)) {
        if (c == '\n')
            line++;
    }
    rewind(fptr);
    struct gracz wygrane[line];
    char tmp[64];
    int index=0;
    while (fgets(tmp, sizeof(tmp), fptr) != NULL) {
        if (sscanf(tmp, "%49s %d", wygrane[index].name, &wygrane[index].score) == 2) {
            index++;
        }
    }
    fclose(fptr);
    qsort(wygrane,line,sizeof(struct gracz),compare);
    int print_count = line < 5 ? line : 5;
    for (int i = 0; i < print_count; i++) {
        printf(" %s  %d\n", wygrane[i].name, wygrane[i].score);
    }
    return 0;}