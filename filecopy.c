#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h>



int main(int argc,char *argv[]){
	
	char buffer;
	size_t integer;
	
	
	int fd = open(argv[1],O_RDONLY);
		if (fd<0){
			printf("cant open file %s",argv[1]);
			exit(1);
			
		}
	int outfile = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0755);
		if (outfile<0){
				printf("cant open file %s",argv[2]);
				exit(1);
				
			}
	
	 while((integer = read(fd,&buffer,sizeof(buffer))) > 0){
		 
		 write(outfile,&buffer,sizeof(buffer));
	 }
	
	close(outfile);
	close(fd);
	
	return 0;
}