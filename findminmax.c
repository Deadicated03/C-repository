#include <stdio.h> 


double minmaxavg(double array[],int num,double *minp,double *maxp){
	
	double sum = 0;
	double average = 0;
	double min = array[0];
	double max = array[0];
	double *help1 = minp;
	double *help2 = maxp;
	for(int i = 0; i< num; i++){		
		sum += array[i];
		printf("%f\n",array[i]);
	if (array[i] <= min){
		min = array[i];
		
	}
	if (array[i] >= max){
		max = array[i];
	}
	}
	
	*help1 = min;
	*help2 = max;
	
	average = sum/num;
	return average;
}

int main(){
	
	double array[] = {1.3,2.2,3.5,5.3,23.2,2.2,5.1};
	int num = 7;
	double min = 0.0;
	double max = 0.0;
	double average;
	
	
	average = minmaxavg(array,num,&min,&max);
	printf("average number is: %f\n",average);
	printf("max number is: %f\n",max);
	printf("min number is: %f\n",min);
		
	
	
}