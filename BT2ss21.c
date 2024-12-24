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
    int c= fgetc(fptr);
	printf("%c\n", c);
	
    fclose(fptr);
    printf("\nDa doc ky tu dau tien file bt01.txt\n");

    return 0;
}

