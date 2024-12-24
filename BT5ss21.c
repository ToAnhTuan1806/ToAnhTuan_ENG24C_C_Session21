#include<stdio.h>
#include<string.h>

int main(){
	FILE *fptr;
	char line[100];
	int numLine;
	
	fptr=fopen("bt05.txt", "w");
	if(fptr==NULL){
		printf("Loi mo file!\n");
		return 1;
	}
	printf("Nhap so dong: ");
	scanf("%d", &numLine);
	getchar();
	
	int i;
	for(i=0; i<numLine; i++){
		printf("Nhap noi dung dong %d: ", i+1);
		fgets(line, sizeof(line), stdin);
		fputs(line, fptr);
	}
	fclose(fptr);
	
	fptr=fopen("bt05.txt", "r");
	if(fptr==NULL){
		printf("Loi mo file!\n");
		return 1;
	}
	printf("\nNoi dung tung dong:\n");
	int n=1;
	while(fgets(line, sizeof(line), fptr) != NULL){
		printf("Dong %d file: %s\n",n, line);
		n++;
	}
	fclose(fptr);
	return 0;
}
