#include <stdio.h>

int main(){
		int i, n, k;
		scanf("%i %i", &n, &k);
		int add = n;
		getchar();
		int scr[n];
		for (i = 0; i < n; i++){
			scanf("%i", &scr[i]);
		}
		for (i = 0; i < n; i++){
			if ((scr[k-1] > scr[i]) || (scr[i] == 0)){
				add--;			}
		}
		printf("%i", add);
}
