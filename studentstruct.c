/* Skeleton file for LAB6, Problem 2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT_NUM 15


typedef struct{
  /* Add struct fields here */
  char name[50];
  int am;
  int grade;
  
}student;


/* Specify return type */
student *create_struct_table(char *namelist[],int *am,float *grade)
{
	student *studentlist;
	studentlist = (student*) malloc(STUDENT_NUM *sizeof(student));
	for(int i = 0; i < STUDENT_NUM; i++){
		strcpy(studentlist[i].name , namelist[i]);
		studentlist[i].am = am[i];
		studentlist[i].grade = grade[i];
	}
	
	return studentlist;

}

void show_struct_table(student *studentlist)
{
	for(int i = 0; i < STUDENT_NUM; i++){
		
		printf("student number %d name is: %s\n", i+1,studentlist[i].name);
		printf("student number %d AM is: %d\n", i+1,studentlist[i].am);
		printf("student number %d grade is: %d\n", i+1,studentlist[i].grade);
	}
	
	
	
}

float compute_average_grade(student *studentlist)
{
	float sum = 0.0;
	for(int i = 0; i < STUDENT_NUM; i++){
		
		sum += studentlist[i].grade;
	}
	
	sum = sum/STUDENT_NUM;
	return sum;
}

void print_failed_names(student *studentlist)
{
	for(int i = 0; i < STUDENT_NUM; i++){
		
		if(studentlist[i].grade < 10){
			
			printf("o bro pou kophke einai: %s\n",studentlist[i].name);
		}
	}
}

void change_failed_names(student *studentlist)
{
	char *string;
	for(int i = 0; i < STUDENT_NUM; i++){
		
		if(studentlist[i].grade < 10){
			
			string = strcat(studentlist[i].name , " (failed)");
			strcpy(studentlist[i].name , string);
		}	
	}

}

int main(void)
{
	char *onoma[] = {
		"Georgios Georgiou", "Vasilios Vasiliou", "Ioanna Ioannidou", 
		"Nikos Nikolaou", "Kiriakos Kiriakidis", "Kwstas Kwstantinidis", 
		"Spyros Spyropoulos", "Dimitris Dimitropoulos", "Dimitra Dimitriadi", 
		"Areti Aretidou", "Ilias Iliopoulos", "Kwstas Kwstoglou",
    "Aimilia Aimilianou", "Xristina Xristopoulou", "Theodoros Theodorou"
	};
    
	int am[] = {
		120, 122, 142, 130, 156, 132, 145, 133, 131, 140, 141, 150, 155, 134, 146
	};

	float vathmos[] = {
		12, 8.5, 15.5, 20, 7.5, 1, 19.5, 12, 17, 17.5, 15.5, 18, 19, 18, 19
	};
	
	student *list = create_struct_table(onoma,am,vathmos);
	show_struct_table(list);
	float sum = compute_average_grade(list);
	printf("mesos oros is: %f\n",sum);
	print_failed_names(list);
	change_failed_names(list);
	show_struct_table(list);
	
	
	return 0;
}