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
int main(){
    srand(time(NULL));
    int a, b;
    printf("Podaj rozmiar planszy \n");
    scanf("%d %d", &a, &b);
    char **tab = (char **)malloc(a * sizeof(char *));
    for (int i = 0; i < a; i++) {
        tab[i] = (char *)malloc(b * sizeof(char));
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int isbomb=rand()%3;
            if (isbomb==1){
                tab[i][j]='*';
            }
            else{
                tab[i][j]='0';
                }
            }
        }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
                if (tab[i][j] != '*') tab[i][j]=count_mines(tab,a,b,i,j)+'0';
            }
        }
    print_map(tab,a,b);
    for (int i = 0; i < a; i++) {
        free(tab[i]);
    }
    free(tab);
    return 0;
}