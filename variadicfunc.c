#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h>
#include <stdarg.h>




void printnums(int n,...){
	va_list args;
	char t;
	int i;
	double d;
	va_start(args,n);
	
	for(int h = 0; h < n; h++){
		t = va_arg(args , int);
		if(t == 'i'){
			i = va_arg(args , int);
			printf("integer is %d\n",i);
			
		}
		else if(t == 'd'){
			d = va_arg(args , double);
			printf("double is %lf\n",d);
			
		}
		
		
	}
	va_end(args); 
	
	
	
}


int main(){
	
	
	printnums(3, 'i', 12, 'd', 23.4, 'i', 14);
	
	
	
	return 0;
}