/*
 ============================================================================
 Name        : ex01.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define maxdata 10

int input(char *argv1);
void output(char *argv2,int n);
void sort(int n);


static int getint[10];


int main(int argc ,char *argv[]) {
	if (argc != 3){
		printf("Check the input/output file names of command line arguments.\n");
		return 1;
	}
	int n;

	n = input(argv[1]);
	printf("\n\nThe integers in %s are sorted ascending order and written to %s.\n\n",argv[1],argv[2]);
	sort(n);
   output(argv[2],n);

	return 0;
}

int  input(char *argv1){
	FILE *fpi;
	fpi=fopen(argv1,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int count=0,i=0;
	while(fscanf(fpi,"%d",&getint[i++])!=EOF){
		count++;
		if(count>maxdata){
			printf("Check number of integers in %s. You can only enter 10 items.\n",argv1);
			exit (1);
		}
	}
	i=0;
	printf("The integers written in %s are ",argv1);
	while(i<count){
		printf("%d ",getint[i++]);
	}
	return count;
	fclose(fpi);
}

void output(char *argv2,int n){
	FILE *fpo;
	fpo=fopen(argv2,"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int i=0;
	printf("The integers written to %s are ",argv2);
	while(i<n){
		fprintf(fpo,"%d ",getint[i]);
		printf("%d ",getint[i]);
		i++;
	}

	fclose(fpo);
}

void sort(int n){
	int i,max,tmp;
	while(n>=1){
		max=0;
		for(i=1;i<=n-1;i++){
			if(getint[max]<getint[i]){
				max=i;
			}
			if(getint[max]==getint[i]){
				continue;
			}
		}
		tmp=getint[n-1];
		getint[n-1]=getint[max];
		getint[max]=tmp;
		n--;
	}
}












