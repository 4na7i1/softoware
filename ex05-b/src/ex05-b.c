#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 10

int input(char *argv1,int *array);
void output(char *argv2, int n,int *array);
void sort(int n,int *array);


int main(int argc, char *argv[]){
	int n;
	int array[MAXDATA];
	if (argc != 3){
		printf("Check the input/output file names of command line arguments.\n");
		return 1;
	}
	n = input(argv[1],array); // n = input(argv[1],&array);
	printf("\n\nThe integers in %s are sorted ascending order and written to %s.\n\n",argv[1],argv[2]);
	sort(n,array);  // sort(n,&array);
	output(argv[2],n,array); // output(argv[2],n,&array);

	return 0;
}

int input(char *argv1,int *array){
	FILE *fpi;
	fpi=fopen(argv1,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int count=0,i=0;
	while(fscanf(fpi,"%d",&array[i++])!=EOF){
		count++;
		if(count>MAXDATA){
			printf("Check number of integers in %s. You can only enter 10 items.\n",argv1);
			exit (1);
		}
	}
	i=0;
	printf("The integers written in %s are ",argv1);
	while(i<count){
		printf("%d ",array[i++]);
	}
	return count;
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
           }


