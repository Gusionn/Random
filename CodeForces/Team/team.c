#include <stdio.h>

int main(){
	int i, n, add=0;
	scanf("%i", &n);
	getchar();
	for (i = 0; i < n; i++){
		int pet, vas, ton;
		scanf("%i %i %i", &pet, &vas, &ton);
		if ( (pet && vas == 1) || (pet && ton == 1) || ( vas && ton == 1) ){
			add++;
		}
	}
	printf("%i", add);
}
