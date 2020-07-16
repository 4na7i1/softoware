/*
 ============================================================================
 Name        : ex05-test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int *array;
	if (argc != 3){
		printf("Check the input/output file names of command line arguments.\n");
		return 1;
	}
	int n=0;
	FILE *fpi;
	fpi=fopen(argv[1],"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int x=14;printf("%d\n",x);
	array=(int *)malloc(sizeof(int)*x);
	if((array=(int*)malloc(sizeof(int)*x))==NULL){
		printf("Failed to allocate the specified size of memory\n");
		exit (1);
	}
	int p=0;
	while(fscanf(fpi,"%d",&array[p++])!=EOF){
		n++;
	}
	p=0;
	printf("The integers written in %s are ",argv[1]);
	while(p<n){
		printf("%d ",array[p++]);
	}
	fclose(fpi);


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




	FILE *fpo;
	fpo=fopen(argv[2],"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int q=0;
	printf("The integers written to %s are ",argv[2]);
	while(q<n){
		fprintf(fpo,"%d ",array[q]);
		printf("%d ",array[q]);
		i++;
	}


	fclose(fpo);
	free(array);
	return 0;
}
