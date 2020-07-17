/*
 ============================================================================
 Name        : ex08-b.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct school_record SRec;
struct school_record{
	float gpa;
	int credit;
	char name[200];
	SRec *next;
	SRec *left ,*right;
};

SRec *input(char*inputfile);
void output(char *outputfile,SRec *p);
int comp_gpa(const void *,const void *);
int comp_credit(const void *,const void *);
int comp_name(const void *,const void *);
SRec *listsort(SRec *head,int (*compare)(const void*,const void*));
void dump_list(SRec *list);
void free_list(SRec *list);
SRec *comp_judgement(char *judge_comp,SRec *list);


int main(int argc,char *argv[]) {
	SRec *head;

	if (argc != 4){
			printf("Check the input/output file names of command line arguments.\n");
			return 1;
		}
	head=input(argv[2]);

	head=comp_judgement(argv[1],head);

	printf("\nSorted by %s\n",argv[1]);
	dump_list(head);
	output(argv[3],head);


	free_list(head);
	return 0;
}

SRec *input(char *inputfile){
	SRec *p;
	SRec *head=NULL;
	SRec **tail=&head;
	FILE *fpi;
	fpi=fopen(inputfile,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	printf("The integers written to %s are \n",inputfile);
	while(1){
		int end=fgetc(fpi);
		if(end!=EOF){
			ungetc(end,fpi);
		p=(SRec *)malloc(sizeof(SRec));
		if(p==NULL){
			printf("Failed to allocate the specified size of memory\n");
			exit (1);
		}
		fscanf(fpi,"%f %d %s\n",&(p->gpa),&(p->credit),p->name);
		printf("%f %d %s\n",p->gpa,p->credit,p->name);

		p->next=NULL;
		*tail=p;
		tail=&(p->next);
		p=p->next;
	}
		else{
			break;
		}
	}
	*tail=NULL;
	fclose(fpi);

	return head;
}

void output(char *outputfile,SRec *p){
	FILE *fpo;
	fpo=fopen(outputfile,"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	printf("\nThe integers written to %s are \n",outputfile);
	while(p!=NULL){
		fprintf(fpo,"%f %d %s\n",p->gpa,p->credit,p->name);
		printf("%f %d %s\n",p->gpa,p->credit,p->name);
		p=p->next;
	}

	fclose(fpo);
}

SRec *listsort(SRec *head,int (*compare)(const void*,const void*)){
    SRec *tree;
    SRec **p; //二分木用
    SRec **q; //連結リスト用

    tree = head;
    q = &(head->next);
    while(*q != NULL){
        p = &tree;
        while(*p != NULL){
            if(compare(*p, *q) > 0){
                p = &((*p)->left);
            }
            else{
                p = &((*p)->right);
            }
        }
        *p = *q;
        q = &((*q)->next);

    }

    return head;
}

SRec *comp_judgement(char *judge_comp,SRec *list){
	SRec *head=NULL;
	if(strcmp(judge_comp,"gpa")==0){
		head=listsort(list,comp_gpa);
	}
	else if(strcmp(judge_comp,"credit")==0){
		head=listsort(list,comp_credit);
	}
	else if(strcmp(judge_comp,"name")==0){
		head=listsort(list,comp_name);
	}
	else{
		printf("The first argument of the command argument must be one of gpa, credit or name\n");
		exit(1);
	}
	return head;
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

void dump_list(SRec *list)
{
    if(list == NULL){
        return;
    }
    else{
        printf("(%5.3f %3d %10s) n:%p l:%p r:%p \n", list->gpa, list->credit, list->name, list, list->left, list->right);
        dump_list(list->next);
    }
}

void free_list(SRec *list){
	if(list==NULL){
		return;
	}
	else{
		free_list(list->next);
		free(list);
	}
}
