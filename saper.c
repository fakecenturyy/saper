#include <stdlib.h>
#include <stdio.h>
#include "plansza.h"
#include "print_map.h"
#include "game.h"
void print_usage(const char *prog_name) {
    printf("Usage: %s [-l poziom] [-a rzedy] [-b kolumny] [-m miny] [-n nazwa]\n", prog_name);
    printf("  -l level   Poziom trudnosci (1: latwy, 2: sredni, 3: trudny, 4: wlasny)\n");
    printf("  -a rzedy    Liczba rzedow\n");
    printf("  -b kolumny    Liczba kolumn)\n");
    printf("  -m miny   liczba min\n");
    printf("  -n nazwa    Player name\n");
}

int main(int argc, char *argv[]) {
    struct gracz player;
    int a = 0, b = 0, mine_count = 0, lvl = 0;
    int opt;

    while ((opt = getopt(argc, argv, "l:a:b:m:n:")) != -1) {
        switch (opt) {
            case 'l':
                lvl = atoi(optarg);
                break;
            case 'a':
                a = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 'm':
                mine_count = atoi(optarg);
                break;
            case 'n':
                snprintf(player.name, sizeof(player.name), "%s", optarg);
                break;
            default:
                print_usage(argv[0]);
                return EXIT_FAILURE;
        }
    }
    char **rplansza=plansza_create(a,b,mine_count);
    player.score=game(rplansza,a,b,mine_count,lvl);
    printf("Player: %s\n", player.name);
    printf("Score: %d\n", player.score);
    return 0;}