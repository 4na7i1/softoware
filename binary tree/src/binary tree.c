/*
 ============================================================================
 Name        : binary.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	char label;
};

void inorder(struct node *p);

int main(void) {
	inorder();
	return 0;
}

void inorder(struct node *p){
	if(p==NULL){
		return;
	}
	inorder(p->left);
	printf("%c",p->label);
	inorder(p->right);
}
