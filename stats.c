#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stats[26];

void charstats(char* input){
	int n;
	
	while (*input != '\0'){
		
			if(isalpha(*input)){
				
				n = *input - 'a';
				stats[n]++;
				
			}
		input++;
		
	}
	
	
}

int main(){
	char input[100];
	printf("type ### for exit: \n");
	printf("enter anyletter for the program to counter each one: ");
		fgets(input,100,stdin);
		while (strncmp(input, "###",3) != 0){
				charstats(input);
				printf("enter anyletter for the program to counter each one: ");
				fgets(input,100,stdin);
		}

			
		for(int i = 0; i < 26; i++){
			printf("%c appeared %d times\n", 'a'+i, stats[i]);
	
		}
		

	return 0;
}