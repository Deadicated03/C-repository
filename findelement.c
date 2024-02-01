#include <stdio.h> 



int *search(int array[],int size,int number){
	
	int *pointer;
	
	for(int i = 0; i <= size ; i++){
		if (array[i] == number){
			pointer = &array[i];
			return pointer;
		}
	}
	return NULL;
	
}

int main(){
	
	int array[] = {1,24,3,34,5,6,73,86,95,10};
	int size = 10;
	int number = 73;
	int *address;

	address = search(array,size,number);

	if(address == NULL){
		
		printf("NOTHING");
		
	}
	
	int element = *address;
	int position = address - array;
	
	printf("element in 7th place of array : %d\n" , element);
	printf("position of element in array: %d" , position);
	
	
}