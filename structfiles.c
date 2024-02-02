#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{	
	char name[50];
	int am;
	int grade;
}student;

student *create_struct_table(FILE *file,int student_num){
	
	student *student_table;
	char buffer[50];
	
	
	student_table = (student*)malloc(sizeof(student_table)*student_num);
	if(file == stdin){
		for(int i = 0; i < student_num; i++){
			printf("give student name: ");
			fgets(buffer,50,file);
			buffer[strlen(buffer) -1] = '\0';
			strcpy(student_table[i].name,buffer);
			
			printf("give student am: ");
			fgets(buffer,50,file);
			student_table[i].am = atoi(buffer);
			
			printf("give student grade: ");
			fgets(buffer,50,file);
			student_table[i].grade = atoi(buffer);
		}		
	}
	else{
		for(int i = 0; i < student_num; i++){
			fgets(buffer,50,file);
			buffer[strlen(buffer) -1] = '\0';
			strcpy(student_table[i].name,buffer);
			
			fgets(buffer,50,file);
			student_table[i].am = atoi(buffer);
			
			fgets(buffer,50,file);
			student_table[i].grade = atoi(buffer);
			
		}
	}	
	return student_table;
}


void show_struct_table(student *table,int student_num){
	printf("Here are the student data:\n");
	for(int i = 0; i < student_num; i++){
		
		printf("Onoma: %s, AM: %d, Vathmos: %d\n", table[i].name, table[i].am, table[i].grade);

	}
	
	
	
	
}


void write_file_from_table(student *table,int student_num){
	
	FILE *file;	
	file = fopen("students.txt","w");
	fprintf(file,"%d\n",student_num);
	for(int i = 0; i < student_num; i++)
		fprintf(file, "%s\n%d\n%d\n", table[i].name, table[i].am, table[i].grade);
	
	fclose(file);
	
	
}




int main(){
	
	int student_num;
	FILE *infile;
	student *student_table;
	
	infile = fopen("students.txt","r");
	
	if(infile == NULL){
		printf("file not found give the number of student: ");
		scanf("%d",&student_num);
		getc(stdin);
		student_table = create_struct_table(stdin,student_num);
	}
	else{
		printf("file found!!");
		fscanf(infile, "%d", &student_num);
		getc(infile);
		student_table = create_struct_table(infile,student_num);
		fclose(infile);
	}
	
	
	write_file_from_table(student_table, student_num);
	show_struct_table(student_table, student_num);
	printf("Data saved to file students.txt...\n");	
	return 0;
}