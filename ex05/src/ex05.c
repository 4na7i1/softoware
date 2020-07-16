/*
 ============================================================================
 Name        : ex05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define maxdata 10

int input(char *argv1,int *array);
void sort(int n,int *array);
void output(char *argv2, int n,int *array);


int main(int argc, char *argv[]){
	int *array;
	if (argc != 3){
		printf("Check the input/output file names of command line arguments.\n");
		return 1;
	}
	int n;
	n = input(argv[1],&array);
	sort(n,array);
	output(argv[2],n,array);
	free(array);
	return 0;
}

int input(char *argv1,int *array){
	FILE *fpi;
	fpi=fopen(argv1,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int x;x=fgetc(fpi);printf("%d",x);
	array=(int *)malloc(sizeof(int)*x);
	if((array=(int*)malloc(sizeof(int)*x))==NULL){
		printf("Failed to allocate the specified size of memory\n");
		exit (1);
	}
	int count=0,i=0;
	while(fscanf(fpi,"%d",&array[i++])!=EOF){
		count++;
	}
	i=0;
	printf("The integers written in %s are ",argv1);
	while(i<count){
		printf("%d ",array[i++]);
	}
	return count;
	fclose(fpi);
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

