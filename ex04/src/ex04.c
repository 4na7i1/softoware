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
void ini_matrix(int n,float(*X)[n]);
void multiply_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n]);
void power_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n],int k);
void output_matrix(int n,float(*C)[n],float(*B)[n],float(*A)[n],int k);


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
	output_matrix(n,C,B,A,k);

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
		      C[i][j]=C[i][j]+A[i][k]*B[k][j];
	      }
	    }
	  }
}

void power_matrix(int n,float(*A)[n],float(*B)[n],float(*C)[n],int k){
	if(k==1){
	}
	else if(k==2){
		multiply_matrix(n,A,A,B);
	}
	else if(k>2){
		int i;
		int l,m;
		printf("\nThe 2-square of the regular matrix of %dx%d \n",n,n);
		multiply_matrix(n,A,A,B); //2乗の計算をBに保存//
		for(l=0;l<n;l++){
			for(m=0;m<n;m++){
				printf("B[%d][%d]= %f \n",l+1,m+1,B[l][m]);
			}
		}
		printf("\n");
		for(i=3;i<=k;i++){
			printf("The %d-square of the regular matrix of %dx%d \n",i,n,n);
			if(i%2==1){
				multiply_matrix(n,B,A,C); //奇数乗の時はB×A//
				ini_matrix(n,B);
				for(l=0;l<n;l++){
					for(m=0;m<n;m++){
						printf("C[%d][%d]= %f \n",l+1,m+1,C[l][m]);
					}
				}
				printf("\n");
					}
			else if(i%2==0){
				multiply_matrix(n,C,A,B); //偶数乗の時はC×A//
				ini_matrix(n,C);
				for(l=0;l<n;l++){
					for(m=0;m<n;m++){
						printf("B[%d][%d]= %f \n",l+1,m+1,B[l][m]);
					}
				}
				printf("\n");
			}
		}
			}
		}

void output_matrix(int n,float(*C)[n],float(*B)[n],float(*A)[n],int k){
	int i,j;
	printf("Answer :\n");
	if(k==1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("A[%d][%d]= %f \n",i+1,j+1,A[i][j]);
			}
		}
	}
	if(k%2==1 && k>1){
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

void ini_matrix(int n,float(*X)[n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			X[i][j]=0;
		}
	}
}
