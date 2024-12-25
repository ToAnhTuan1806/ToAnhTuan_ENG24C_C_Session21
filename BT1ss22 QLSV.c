#include<stdio.h>
#include<string.h>

typedef struct {
	int id;
	char name[50];
	int age;
} Student;

Student students[100];
int n=0;

void loadStudentsFromFile();
void saveStudentsToFile();
void printStudents();
void addStudents();
void editStudents();
void delStudents();
void findStudents();
void sortStudents();



int main(){
	int choice;
	do {
		printf("\n=========== MENU ===========\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printStudents();
				break;
			case 2:
				addStudents();
				saveStudentsToFile();
				break;
			case 3:
				editStudents();
				saveStudentsToFile();
				break;
			case 4:
				delStudents();
				saveStudentsToFile();
				break;
			case 5:
				findStudents();
				break;
			case 6:
				sortStudents();
				saveStudentsToFile();
				break;
			case 7:
				printf("Thoat chuong trinh\n");
				break;						
				default:
				printf("Lua chon khong hop le thu lai!\n");
		}
		
		
		
	} while (choice != 7);
	
	return 0;
}

void loadStudentsFromFile() {
	FILE *fptr = fopen("Students.dat", "rb");
	if(fptr==NULL){
		printf("Khong tim thay du lieu trong file. Khoi tao mang rong!\n");
		n=0;
	}
	n= fread(students, sizeof(Student), 100 , fptr);
	fclose(fptr);
	printf("Tai thong tin thanh cong!\n");
}
void saveStudentsToFile() {
	FILE *fptr = fopen("Students.dat", "wb");
	if(fptr==NULL){
		printf("Loi mo file!\n");
	}
	fwrite(students, sizeof(Student), n , fptr);
	printf("Luu thong tin thanh cong!\n");
	fclose(fptr);
	
}
void printStudents(){
	if(n==0){
		printf("Danh sach sv trong\n");
		return;
	}
	printf("Danh sach sinh vien:\n");
	int i;
	for(i=0; i<n; i++){
		printf("\nId: %d\n", students[i].id);
		printf("Name: %s\n", students[i].name);
		printf("Age: %d\n", students[i].age);
	}

}
void addStudents() {
	int addStd;
	printf("Nhap so luong sv can them: ");
	scanf("%d", &addStd);
	
	int i;
	for(i=0; i<addStd; i++){
		Student std;
		printf("\nNhap ID sv: ");
		scanf("%d", &std.id);
		printf("Nhap Ten sv: ");
		getchar();
		fgets(std.name, sizeof(std.name), stdin);
		std.name[strcspn(std.name, "\n")]='\0';
		printf("Nhap tuoi sv: ");
		scanf("%d", &std.age);
		students[n++]=std;
	}
}
void editStudents() {
	int editId;
	printf("Nhap id sinh vien can sua: ");
	scanf("%d", &editId);
	int i;
	for(i=0; i<n; i++){
		if(students[i].id==editId){
			printf("Nhap Ten sv moi: ");
			getchar();
			fgets(students[i].name, sizeof(students[i].name), stdin);
			students[i].name[strcspn(students[i].name, "\n")]=0;
			printf("Nhap tuoi sv moi: ");
			scanf("%d", &students[i].age);
			}	
		}
		printf("Id khong ton tai\n");
	}
void delStudents() {
	int delId;
	printf("Nhap id sinh vien can xoa: ");
	scanf("%d", &delId);
	int i, j;
	int check=-1;
	for(i=0; i<n; i++){
		if(students[i].id==delId){
			for(j=i; j<n-1; j++){
				students[j]=students[j+1];
			}
			n--;
			check=1;
			break;
		}
	}
	if(check==-1){
		printf("Khong tim thay id sinh vien vua nhap.\n");
	}
}		
void findStudents() {
	char findStd[50];
	printf("Nhap ten sinh vien can tim: ");
	getchar();
	fgets(findStd, sizeof(findStd), stdin);
	findStd[strcspn(findStd, "\n")]=0;
	int i; 
	int check=-1;
	for(i=0; i<n; i++){
		if(strcmp(findStd, students[i].name)==0) {
			printf("Sinh vien tim duoc: \n");
			printf("Id: %d\n", students[i].id);
			printf("Name: %s\n", students[i].name);
			printf("Age: %d\n", students[i].age);
			check=1;
			break;
		}
	}
	if(check==-1){
		printf("Khong tim thay ten sinh vien vua nhap.\n");
	}	
}
void sortStudents() {
    Student temp;
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (students[i].id > students[j].id) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep sv theo thu tu tang dan\n");
}




