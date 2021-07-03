#include <stdio.h>

int main(){
    int m, n, r;
    scanf("%i %i", &m, &n);
    if ((m * n) % 2 != 0){
        r = (((m * n) - 1) / 2);
        printf("%i", r);
    }
    else{
        r = (m * n) / 2;
        printf("%i", r);  
    }
}