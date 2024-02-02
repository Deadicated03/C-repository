#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc ,char *argv[]){
	int i;
	int result;
	int sum;
	
	if( *argv[1] == '+'){
		sum = 0;
		for(i = 2; i <= argc; i++){
			sum+= atoi(argv[i]);
			
		}
		
		result = sum;
		
	}
	
	else if( *argv[1] == '-'){
		sum = atoi(argv[2]);
		for(i = 3; i <= argc; i++){
			sum-= atoi(argv[i]);
			
		}
		
		result = sum;
		
	}
	
	else if( *argv[1] == 'x'){
		sum = 1;
		for(i = 2; i < argc; i++){
			
			sum *= atoi(argv[i]);
			
		}
		result = sum;
		
	}
	else if( *argv[1] == '/'){		
		sum = atoi(argv[2]);
		for(i = 3; i < argc; i++){
			
			 sum/= atoi(argv[i]);
			
		}
		
		result = sum;
		
	}
	
	printf("result: %d\n",result);
	return 0;
}