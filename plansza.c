#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b;
    printf("Podaj rozmiar planszy \n");
    scanf("%d %d", &a, &b);
    int **tab = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++) {
        tab[i] = (int *)malloc(b * sizeof(int));
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            tab[i][j]=0;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}