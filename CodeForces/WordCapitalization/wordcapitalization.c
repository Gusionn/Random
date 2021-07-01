#include <stdio.h>
#include <string.h>

int main(){
    char word[1000];
    fgets(word, 1000, stdin);
    int i=0, j=0, n;
    n = strlen(word);
    if (word[0] > 90){
        word[0] -= 32;
    }
    printf("%s", word);
}