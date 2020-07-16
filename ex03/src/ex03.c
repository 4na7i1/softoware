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

void input_matrix(int n,float (*A)[n]);
void multiply_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n]);
void output_matrix(int n,float(*C)[n]);


int main(void) {
	int k=2;
	printf("Compute the %d-square of the regular matrix of n×n.\n",k);
	int n;
	printf("Input n >> ");scanf("%d",&n);
	if(n>5){
		printf("Please enter number 'n' less than or equal 5\n");
		return -1;
	}
	float A[n][n];
	float C[n][n];
	input_matrix(n,A);
	multiply_matrix(n,A,A,C);
	output_matrix(n,C);

	return 0;
}

void input_matrix(int n,float (*A)[n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Input A[%d][%d]=",i+1,j+1);scanf("%f",&A[i][j]);
		}
	}
}

void multiply_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n]){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			C[i][j]=0;
		}
	}
	for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	      for(k=0; k<n; k++){
		      C[i][j]=C[i][j]+A[i][k]*A[k][j];
	      }
	    }
	  }
}

void output_matrix(int n,float(*C)[n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("C[%d][%d]= %f \n",i+1,j+1,C[i][j]);
		}
	}
}
