#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int atoi2(char c) {
	return (int) c - (int) '0';
}

char* dechiffrer_message(int n, char* message) {
	
	int last = 0;
	int i = 0;
	char* result = malloc((n+1)*sizeof(char));
	
	for(int j = 0; j < n; j++) {
		
		char curr = message[j];
		int val = atoi2(curr);
		
		if(val >= 0 && val <= 9) {
			if(last > val) {
				last = val;
				continue;
			} else last = val;
		}

		result[i++]=curr;
	}
	result[i] = '\0';
	return result;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // \n
    char* message = (char*)malloc((n + 1) * sizeof(char));
    fgets(message, n + 1, stdin);
    char* c = dechiffrer_message(n, message);
    printf("%s\n", c);
    return 0;
}
