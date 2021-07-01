#include <stdio.h>
#include <string.h>

int main(){
    char xsum[100];
    fgets(xsum, 100, stdin);
    char hold;
    int i, j=0, n;
    n = strlen(xsum);
    do{    
        for (i = 0; i < n - 2; i++){
            if ((i % 2 == 0) || (i == 0)){
                if (xsum[i] > xsum[i + 2]){
                    hold = xsum[i];
                    xsum[i] = xsum[i + 2];
                    xsum[i + 2] = hold;
                }
            }
        }
        j++;
    } while(j < n - 1);
    printf("%s", xsum);
}