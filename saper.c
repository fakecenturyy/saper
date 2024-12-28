#include <stdlib.h>
#include <stdio.h>
#include "plansza.h"
#include "print_map.h"
#include "game.h"
#include <unistd.h>
#include <process.h>
void print_usage(const char *prog_name) {
    printf("Usage: %s [-l poziom] [-a rzedy] [-b kolumny] [-m miny] [-n nazwa]\n", prog_name);
    printf("  -l level   Poziom trudnosci (1: latwy, 2: sredni, 3: trudny, 4: wlasny)\n");
    printf("  -a rzedy    Liczba rzedow\n");
    printf("  -b kolumny    Liczba kolumn)\n");
    printf("  -m miny   liczba min\n");
    printf("  -n nazwa    Player name\n");
}

int main(int argc, char *argv[]) {
    struct gracz player = {0, ""}; // Initialize player structure
    int a = 0, b = 0, mine_count = 0, lvl = 0;
    int opt;

    while ((opt = getopt(argc, argv, "l:n:")) != -1) {
        switch (opt) {
            case 'l':
                lvl = atoi(optarg);
                break;
            case 'n':
                snprintf(player.name, sizeof(player.name), "%s", optarg);
                break;
            default:
                print_usage(argv[0]);
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
            print_usage(argv[0]);
            return EXIT_FAILURE;
    }

    if (player.name[0] == '\0') {
        printf("Enter player name: ");
        scanf("%49s", player.name);
    }
    char **rplansza=plansza_create(a,b,mine_count);
    player.score=game(rplansza,a,b,mine_count,lvl);
    printf("Player: %s\n", player.name);
    printf("Score: %d\n", player.score);
    return 0;}