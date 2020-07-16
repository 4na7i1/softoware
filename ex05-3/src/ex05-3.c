#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 12

int input(char *argv1,int **array);
void output(char *argv2, int n,int *array);
void sort(int n,int *array);


int main(int argc, char *argv[]){
	int n;
	int *array;
	/////////////////////////////////////////////////////////////////////////////////
	int i=0;printf("\n");
	printf("main first -->");
	for(i=0;i<12;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	///////////////////////////////////////////////////////////////////////////////
	if (argc != 3){
		printf("Check the input/output file names of command line arguments.\n");
		return 1;
	}
	n = input(argv[1],&array); // n = input(argv[1],&array);
	/////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("main input next -->");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	} ///////////////////////////////////////////////////////////////////////////////
	printf("\n\nThe integers in %s are sorted ascending order and written to %s.\n\n",argv[1],argv[2]);
	sort(n,array);  // sort(n,&array);
	///////////////////////////////////////////////////////////////////////////////////////
	printf("main sort next -->");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	//////////////////////////////////////////////////////////////////////////////////////
	output(argv[2],n,array); // output(argv[2],n,&array);

	free(array);
	return 0;
}

int input(char *argv1,int **array){
	FILE *fpi;
	fpi=fopen(argv1,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int x;fscanf(fpi,"%d",&x);printf("x=%d\n",x);
	*array=(int *)malloc(sizeof(int)*x);
	if(*array==NULL){
		printf("Failed to allocate the specified size of memory\n");
		return 0;
	}
	int i=0;
	int tmp;
	while(fscanf(fpi,"%d",&tmp)!=EOF){
		(*array)[i]=tmp;
		i++;
	}
	i=0;
	/////////////////////////////////////////////////////////////////
	printf("input last -->");
	/////////////////////////////////////////////////////////////////
	printf("The integers written in %s are ",argv1);
	for(i=0;i<x;i++){
		printf("%d ",*(array+i));
	}
	return x;
	fclose(fpi);
}

void output(char *argv2, int n,int *array){
	FILE *fpo;
	fpo=fopen(argv2,"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int i=0;
	printf("The integers written to %s are ",argv2);
	while(i<n){
		fprintf(fpo,"%d ",array[i]);
		printf("%d ",array[i]);
		i++;
	}

	fclose(fpo);
}


void sort(int n,int *array){
	int i,max,tmp;
	///////////////////////////////////////////////////////////////////////////////////////
	printf("sort first -->");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	//////////////////////////////////////////////////////////////////////////////////////
	while(n>=1){
		max=0;
		for(i=1;i<=n-1;i++){
			if(array[max]<array[i]){
				max=i;
			}
			if(array[max]==array[i]){
				continue;
			}
		}
		tmp=array[n-1];
		array[n-1]=array[max];
		array[max]=tmp;
		n--;
	}

	///////////////////////////////////////////////////////////////////////////////////////
	printf("sort last -->");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	//////////////////////////////////////////////////////////////////////////////////////
}


