#include <stdio.h>
#include <stdlib.h>

/// \param n le nombre de boites
/// \param valeur la valeur du marché du jour
/// \param boites le contenu de chaque boite
int le_juste_etal(int n, int valeur, int* boites) {

	int* cache = malloc(n*sizeof(int));
	int count = 0;

	for(int i = 0; i < n; i++) 
		for(int j = 0; j <= i; j++)
			if((cache[j]+=boites[i]) % valeur == 0)count++;

	free(cache);
	return count % 1000000007;
}

int main() {
    int n;
    scanf("%d", &n);
    int valeur;
    scanf("%d", &valeur);
    int* boites = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &boites[i]);
    
    int e = le_juste_etal(n, valeur, boites);
	printf("%i \n", e);
    return 0;
}
