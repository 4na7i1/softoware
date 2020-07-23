/*
 ============================================================================
 Name        : Buturi_zikken.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void heikoutan_heikoutan(int a,int b);
void heikoutan_kaikoutan(int a,int b);

int main(void) {
	double a=331.45;
	int b;char c;
	printf("input 2000 or 3000 or 4000");scanf("%d",&b);
	printf("input hei_hei-> h hei_kai->h_k");scanf("%c",&c);
	if("c==h"){
		heikoutan_heikoutan(a,b);
	}
	else if("c==h_k"){
		heikoutan_kaikoutan(a,b);
	}


}

void heikoutan_heikoutan(int a,int b){
	double l_n;
	int n=1;
	while(n!=5){
		l_n=(double)(a*n)/(2*b);
		l_n=l_n*100;
		printf("l_n=%f n=%d",l_n,n);
		n++;
	}
}

void heikoutan_kaikoutan(int a,int b){
	double l_n;
	int n=1;
	while(n!=5){
		l_n=(double)(a*(2*n-1))/(4*b);
		l_n=l_n*100;
		printf("l_n+ƒ¢l=%f n=%d",l_n,n);
		n++;
	}
}
