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
void output(char *argv1,int n, SRec *rec);
int comp_gpa(const void *,const void *);
int comp_credit(const void *,const void *);
int comp_name(const void *,const void *);
int sort(char *argv1,int n,SRec *rec);


int main(int argc,char *argv[]){
	SRec *rec;
	if (argc != 4){
			printf("Check the input/output file names of command line arguments.\n");
			return 1;
		}
	int n;
	n =input(argv[2],&rec);
	sort(argv[1],n,rec);
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
	printf("The integers written to %s are \n",argv3);
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

int sort(char *argv1,int n,SRec *rec){
	printf("\nSorted by %s\n\n",argv1);
	if(strcmp(argv1,"gpa")==0){
		qsort(rec,n,sizeof(SRec),comp_gpa);
	}
	else if(strcmp(argv1,"credit")==0){
		qsort(rec,n,sizeof(SRec),comp_credit);
	}
	else if(strcmp(argv1,"name")==0){
		qsort(rec,n,sizeof(SRec),comp_name);
	}
	else {
		printf("The first argument of the command argument must be one of gpa, credit or name\n");
		return 1;
	}
	return 0;
}
