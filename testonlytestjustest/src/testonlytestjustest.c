/*
 ============================================================================
 Name        : testonlytestjustest.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double function(void);

int main(void) {
	double p=0;
	double f=function();
	p=2/(double)f;
	printf("%.10lf",p);
}

double function(void){
	double f=1;
	int a=1,b=3,c=2;
	int k;
	for(k=1;k<=30000;k++){
		double tmp;
		tmp=(double)(a*b)/(double)(c*c);
		f=(double)f*(double)tmp;
		a=a+2;b=b+2;c=c+2;
	}
	return f;
}
