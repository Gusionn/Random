#include <stdio.h>
#include <string.h>
int main(){
	int n, i;
	scanf("%i", &n);
	char str[n][100];
	getchar();
	for (i = 0; i < n; i++){
		fgets(str[i], 100, stdin);
	}
	for (i = 0; i < n; i++){
		int len = strlen(str[i]);
		if (len > 11){
			printf("%c%i%c\n", str[i][0], (len - 3), str[i][len - 2]);
		}
		else {
			printf("%s", str[i]);
		}
	}
}
