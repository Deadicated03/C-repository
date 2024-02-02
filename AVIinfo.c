#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h>



int main(int argc,char *argv[]){
	
	int fd;
	int wight;
	int height;
	int buffer;
	int videoframes;
	int datarate;
	int timescale;
	int fps;
	
	if(argc != 2)
		printf("wrong input!");
	
	fd = open(argv[1],O_RDONLY);
		if(fd < 0){	
			printf("cant open file %s",argv[1]);
			exit(1);		
		}
	
    lseek(fd,32,SEEK_SET);	
	lseek(fd,16,SEEK_CUR);
	read(fd,&videoframes,sizeof(int));
	lseek(fd,12,SEEK_CUR);
	read(fd,&wight,sizeof(int));
	read(fd,&height,sizeof(int));
	read(fd,&timescale,sizeof(int));
	read(fd,&datarate,sizeof(int));	
	
	fps = datarate/timescale;
	
	
	
	
	printf("pixels of the video %d/%d\n",wight,height);
	printf("framerate of the video %d\n",fps);
	printf("time of the video %d secs\n",videoframes/fps);
	
	return 0;
}