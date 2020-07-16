/*
 ============================================================================
 Name        : ex06-b.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct school_record{
        float gpa;
        int credit;
        char name[200];
    }SRec;

int input(char *argv2,SRec **rec);
void output(char *argv3,int n, SRec *rec);
int comp_gpa(const void *,const void *);
int comp_credit(const void *,const void *);
int comp_name(const void *,const void *);
void simple_sort(int n,SRec *rec,int (*compare)(const void *, const void *));

int main(int argc,char *argv[]){
	SRec *rec;
	int (*compare)(const void *,const void *);
	if(strcmp(argv[1],"gpa")==0){
		compare=comp_gpa;
	}
	else if(strcmp(argv[1],"credit")==0){
		compare=comp_credit;
	}
	else if(strcmp(argv[1],"name")==0){
		compare=comp_name;
	}
	else{
		printf("The first argument of the command argument must be one of gpa, credit or name\n");
		return 1;
	}
	if (argc != 4){
			printf("Check the input/output file names of command line arguments.\n");
			return 1;
		}
	int n;
	n =input(argv[2],&rec);
	simple_sort(n,rec,compare);
	output(argv[3],n,rec);

	free(rec);
	return 0;
}

int input(char *argv2,SRec **rec){
	FILE *fpi;
	fpi=fopen(argv2,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int x;fscanf(fpi,"%d",&x);
	*rec=(SRec *)malloc(sizeof(SRec)*x);
	if(*rec==NULL){
		printf("Failed to allocate the specified size of memory\n");
		return 0;
	}
	int i=0;
	printf("The integers written in %s are \n",argv2);
	for(i=0;i<x;i++){
		fscanf(fpi,"%f %d %s\n",&(*rec)[i].gpa,&(*rec)[i].credit,(*rec)[i].name);
		printf("%f %d %s\n",(*rec)[i].gpa,(*rec)[i].credit,(*rec)[i].name);
	}
	return x;
	fclose(fpi);
}

void output(char *argv3,int n,SRec *rec){
	FILE *fpo;
	fpo=fopen(argv3,"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int i=0;
	printf("\nThe integers written to %s are \n",argv3);
	fprintf(fpo,"%d\n",n);
	while(i<n){
		fprintf(fpo,"%f %d %s\n",rec[i].gpa,rec[i].credit,rec[i].name);
		printf("%f %d %s\n",rec[i].gpa,rec[i].credit,rec[i].name);
		i++;
	}printf("\n");

	fclose(fpo);

}

int comp_gpa(const void *n1,const void *n2){
	if(((SRec*)n1)->gpa > ((SRec*)n2)->gpa){
		return -1;
	}
	else if(((SRec*)n1)->gpa < ((SRec*)n2)->gpa){
		return 1;
	}
	else {
		return 0;
	}
}

int comp_credit(const void *n1,const void *n2){
	if(((SRec*)n1)->credit > ((SRec*)n2)->credit){
		return -1;
	}
	else if(((SRec*)n1)->credit < ((SRec*)n2)->credit){
		return 1;
	}
	else {
		return 0;
	}
}

int comp_name(const void *n1,const void *n2){
	return strcmp(((SRec*)n1)->name,((SRec*)n2)->name);
}

void simple_sort(int n,SRec *rec,int (*compare)(const void *, const void *)){
	int i,max;
	SRec tmp;
	while(n>=1){
		max=0;
		for(i=1;i<n;i++){
			if((*compare)(&rec[max],&rec[i])<=0){
				max=i;
			}
		}
		tmp=rec[n-1];
		rec[n-1]=rec[max];
		rec[max]=tmp;
		n--;
	}
}



