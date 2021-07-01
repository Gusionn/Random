#include <stdio.h>
#include <string.h>

int main(){
    int ii, count=0;
    scanf("%i", &ii);
    getchar();
    char word[ii];
    fgets(word, 51, stdin);
    for (int i = 0; i < strlen(word); i++){
        if (word[i] == word[i + 1]){
            count++;
        }
    }
    printf("%i", count);
}