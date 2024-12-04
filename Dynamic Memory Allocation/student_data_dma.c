#include <stdio.h>
#include <stdlib.h> 
struct Student{
	char name[20];
	int id;
	float gpa;
};
int main(){
	int n;
	printf("Enter number total number of students : ");
	scanf("%d",&n);
	struct Student *PFStudents=(struct Student *) malloc(n*sizeof(struct Student));
	//input student data 
	for(int i=0; i<n; i++){
		printf("Enter student-%d details : \n",i+1);
		printf("Name: ");
		scanf("%s", &(PFStudents+i)->name);
		printf("Id: ");
		scanf("%d", &(PFStudents+i)->id);
		printf("GPA: ");
		scanf("%f", &(PFStudents+i)->gpa);

	}
	//print students details 
	printf("---------------------------------------------\n");
	for(int i=0; i<n; i++){
		printf("Enter student-%d details : \n",i+1);
		printf("Name: %s\n",(PFStudents+i)->name);
		printf("Id: %d\n",(PFStudents+i)->id);
		printf("GPA: %.2f\n",(PFStudents+i)->gpa);

	}

	free(PFStudents);
	PFStudents=NULL;
	return 0;
}
