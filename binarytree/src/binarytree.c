/*
 ============================================================================
 Name        : binarytree.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node NOD;

struct node {
	struct node *left;
	struct node *right;
	char label;
	NOD *next;
};


void inorder(struct node *p);


int main(void) {
	 NOD *p;
	p=(NOD*)malloc(2);
	p[0]->label="B";
	p[0]->left->label;="A";
	inorder(p);
	return 0;
}

void inorder(struct node *p){
	if(p==NULL)return;
	inorder(p->left);
	printf("%c",p->label);
	inorder(p->right);
}


