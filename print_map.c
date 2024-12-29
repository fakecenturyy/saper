#include <stdio.h>
void print_map(char **tab, int a, int b) {
    printf("    ");
    for (int x = 0; x < b; x++) {
        printf("%d ", x + 1);
    }
    printf("\n");
    printf("  ");
    for (int x = 0; x < b; x++) {
        printf("--");
    }
    printf("-\n");
    for (int i = 0; i < a; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < b; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}