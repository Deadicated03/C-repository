#include <stdio.h>

char *string_end(char *str){
	char * pnty = str;
	int i = 1;
	while(*pnty != '\0'){
		pnty = &str[i];
		i++;
			
	}
	return pnty;
	
}
void string_reverse(char *str){
	char * pntlast = string_end(str);
	char temp;
	int i = 0;
	int g = -1;	
	while((&pntlast[g] != &str[i]) && (&pntlast[g]+1 != &str[i])){
		temp = str[i];	
		str[i] = pntlast[g];
		pntlast[g] = temp;
		i++;
		g--;
		
	}
	
	
}

int main(){
	
	char str[10];
	printf("enter your string: ");
	scanf("%s",str);
	string_reverse(str);
	printf("reversed string: %s", str);
	return 0;
	
}