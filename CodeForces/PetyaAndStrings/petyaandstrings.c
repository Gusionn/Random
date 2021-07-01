#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char string1[103], string2[103];
    fgets(string1, 103, stdin);
    fgets(string2, 103, stdin);
    int i, sum1=0, sum2=0;
    for (i = 0; i < strlen(string1); i++){
        if (string1[i] < 97){
            string1[i] += 32;
        }
        if (string2[i] < 97){
            string2[i] += 32;
        }
    }
    for (i = 0; i < strlen(string1); i++){
        if (string1[i] > string2[i]){
            printf("1");
            exit(EXIT_SUCCESS);
        }
        else if (string2[i] > string1[i]){
            printf("-1");
            exit(EXIT_SUCCESS);
        }
    }
    printf("0");
    
}