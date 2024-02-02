#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(){
	FILE *infile , *positives, *negatives;
	int *numbers;
	int total_numbers, buffer,p_num,num;
	infile = fopen("data.txt", "r");
	positives = fopen("positives.txt", "w+");
	negatives = fopen("negatives.txt", "w+");
	
	
	if(infile == NULL){
		return 1;
	}
	if(positives == NULL){
		return 1;
	}
	if(negatives == NULL){
		return 1;
	}
	
	fscanf(infile,"%d",&total_numbers);
	numbers = (int *)malloc(total_numbers*sizeof(int));
	int pos = 0;
	int neg = 0;
	for(int i = 0; i < total_numbers; i++){
		
		fscanf(infile,"%d",&buffer);
		if (buffer >= 0){
			pos++;
		}
		else{
			neg++;
		}
		numbers[i] = buffer;
	}
	
	fprintf(positives,"%d\n",pos);
	fprintf(negatives,"%d\n",neg);
	
	for(int i = 0; i < total_numbers; i++){
		
		if(numbers[i] >=0){
			fprintf(positives,"%d\n",numbers[i]);	
		}
		else{
			fprintf(negatives,"%d\n",numbers[i]);
		}
		
	}
	fclose(infile);
	fclose(negatives);
	rewind(positives);
	
	
	
	int sum = 0;
	
	fscanf(positives, "%d", &p_num);
	for(int i = 0; i < p_num; i++){
		
		fscanf(positives,"%d",&num);
		sum += num;
		
	}
	printf("sum of positives is %d", sum);
	
	fclose(positives);
	
	
	
	
	
	return 0;
}