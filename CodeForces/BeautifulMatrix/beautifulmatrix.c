#include <stdio.h>
#include <stdlib.h>

int main(){
    int matrix[5][5], i, j, x, y, dx, dy, r;
    for (i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            scanf("%i", &matrix[i][j]);
        }
    }
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (matrix[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    dx = x - 2;
    dy = y - 2;
    r = abs(dx) + abs(dy);
    printf("%i", r);
}