#include <stdio.h>
void print_map(char **tab,int a,int b){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}