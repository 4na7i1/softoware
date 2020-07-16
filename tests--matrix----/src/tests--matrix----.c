/*
 ============================================================================
 Name        : ex03.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void input_matrix(int n,float A[n][n]);
void input_matrix2(int n,float(*A)[n]);


int main(void) {
	int k=2;
	printf("Compute the %d-square of the regular matrix of n×n.\n",k);
	int n;
	printf("Input n >> ");scanf("%d",&n);
	float A[n][n];
	input_matrix(n,A);
	input_matrix(n,A);

	return 0;
}

void input_matrix(int n,float A[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("A[%d][%d]=",i,j);scanf("%f",&A[j][i]);
		}
	}
}

void input_matrix2(int n,float (*A)[n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("A[%d][%d]=",i,j);scanf("%f",&A[j][i]);
		}
	}
}
