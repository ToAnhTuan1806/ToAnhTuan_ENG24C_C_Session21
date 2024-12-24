#include <stdio.h>
#include<string.h>

int main() {
    FILE *fptr;
    char str[100];

    fptr = fopen("bt01.txt", "w");
    if (fptr==NULL) {
        printf("Loi mo file!\n");
        return 1;
    }
    printf("Nhap mot chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    fputs(str, fptr);
    fclose(fptr);
    printf("Da ghi du lieu vao file bt01.txt thanh cong\n");

	
    return 0;
}

