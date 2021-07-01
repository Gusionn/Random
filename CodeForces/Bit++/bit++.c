#include <stdio.h>
#include <string.h>

int main(){
	int nops, i, res=0;
    char add[3] = "++X";
    char add2[3] = "X++";
    scanf("%i", &nops);
    getchar();
    char ops[nops][4];
    for (i = 0; i < nops; i++){
        fgets(ops[i], 4, stdin);
        getchar();
    }
    for (i = 0; i < nops; i++){
        if (ops[i][0] == '+'){
            res++;
        }
        else if (ops[i][2] == '+'){
            res++;
        }
        else{
            res--;
        }
    }
    printf("%i", res);
}
