/*
 ============================================================================
 Name        : badsearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int low,up,mid;
	int n=5;
	int x[5]={0,10,20,30,40};
	int t;printf("t >> ");scanf("%d",&t);
	low=0;
	up=n-1;
	while(low<=up){
		mid=(low+up)/2;
		printf("%d %d %d \n",low,mid,up);
		if(x[mid]<t){
			low=mid+1;
		}
		else if(x[mid]>t){
			up=mid-1;
		}
		else{
			return mid;
		}
	}
	return -1;

}
