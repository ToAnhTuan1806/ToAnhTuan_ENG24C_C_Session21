#include <stdio.h>
#include<string.h>

int main() {
    FILE *fptr;
    char str[100];

    fptr = fopen("bt01.txt", "r");
    if (fptr==NULL) {
        printf("Loi mo file!\n");
        return 1;
    }
	fgets(str, sizeof(str), fptr);
	printf("Dong dau tien doc tu file: %s\n", str);
	
    fclose(fptr);


	
    return 0;
}

