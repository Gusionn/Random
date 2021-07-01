#include <stdio.h>

int main(){
	int n;
	scanf("%i", &n);
	if (n % 2 == 0 && n > 2){
		printf("YES");
	}
	else {
		printf("NO");
	}
}
