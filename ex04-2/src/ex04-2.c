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
void ini_matrix(int n,float(*C)[n]);
void multiply_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n]);
void power_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n],int k);
void output_matrix(int n,float(*C)[n],float(*B)[n],int k);


int main(void) {
	int k;
	printf("Compute the k-square of the regular matrix of n×n.\n");
	printf("Input k >> ");scanf("%d",&k);
	int n;
	printf("Input n >> ");scanf("%d",&n);
	if(n>5){
		printf("Please enter number 'n' less than or equal 5\n");
		return -1;
	}
	float A[n][n];
	float B[n][n];
	float C[n][n];
	input_matrix(n,A);
	ini_matrix(n,C); ini_matrix(n,B);
	power_matrix(n,A,B,C,k);
	output_matrix(n,C,B,k);

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

	for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	      for(k=0; k<n; k++){
		      C[i][j]=C[i][j]+A[i][k]*A[k][j];
	      }
	    }
	  }
}

void power_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n],int k){
	if(k==1){
		A=C;
	}
	else if(k==2){
		multiply_matrix(n,A,A,B);
	}
	else if(k>2){
		int i;
		multiply_matrix(n,A,A,B); //2乗の計算をBに保存//
		output_matrix(n,C,B,k);
		for(i=0;i<k;i++){
			if(k%2==1){
				multiply_matrix(n,B,A,C); //奇数乗の時はB×A//
				output_matrix(n,C,B,k);
					}
			else if(k%2==0){
				multiply_matrix(n,C,A,B); //偶数乗の時はC×A//
				output_matrix(n,C,B,k);
			}
			k--;
		}
			}
		}

void output_matrix(int n,float(*C)[n],float(*B)[n],int k){
	int i,j;
	if(k%2==1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("C[%d][%d]= %f \n",i+1,j+1,C[i][j]);
			}
		}
	}
	else if(k%2==0){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("B[%d][%d]= %f \n",i+1,j+1,B[i][j]);
			}
		}

	}
}

void ini_matrix(int n,float(*C)[n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			C[i][j]=0;
		}
	}
}
