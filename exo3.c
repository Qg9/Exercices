#include <stdio.h>
#include <stdlib.h>

/// \param longueur la longueur (en mètres) du passage souterrain
/// \param tunnel le tableau représentant les zones sûres et les zones de danger du passage souterrain. Un chiffre par mètre : Un `0` correspond à une position dans une zone sûre, et un `1` correspond à une position dans une zone de danger

int force_maximale(int longueur, int* tunnel) {

	int R = longueur; // min interv 0
	int E = 0; // max interv 1
	
	int cs = 0;
	int ct = tunnel[0];
	
	for(int i = 0; i < longueur; i++) {
		int c = tunnel[i];
		if(c != ct) {
			if(ct == 0 && cs < R) R = cs;
			else if(ct == 1 && cs > E) E = cs;
				
			cs = 0;
			ct = c;
		} 
		cs++;
	}
	
	if(ct == 0 && cs < R) R = cs;
	else if(ct == 1 && cs > E) E = cs;
	
	return R-E;
}

int main() {
    int longueur;
    scanf("%d", &longueur);
    int* tunnel = (int*)malloc(longueur * sizeof(int));
    for (int i = 0; i < longueur; ++i)
        scanf("%d", &tunnel[i]);
    int r = force_maximale(longueur, tunnel);

    printf("%i \n", r);

    return 0;
}
