/*
 ============================================================================
 Name        : ex01.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define maxdata 10

int input(char *argv1); //ファイルオープンして配列にファイルないの整数を書き込み //
void output(char *argv2,int n); //ファイルオープンして配列ないのソートした整数をファイルに書き込み //
void sort(int n); //選択ソートの最小値抽出//
void sort2(int n); //選択ソートの最大値抽出//
void quicksort(int j, int k); //pivotを配列の真ん中の数にしてクイックソート//
void avg(int n); //平均をもとめる//
void swap(int *a,int *b);



static int getint[10];


int main(int argc ,char *argv[]) {
	if (argc != 3){
		printf("Specify file name\n");
		return 1;
	}
	int n;

	n = input(argv[1]);
	printf("\n\nThe integers in %s are sorted ascending order and written to %s.\n\n",argv[1],argv[2]);
	sort(n);
	//sort2(n);
	//quicksort(0,n-1);
	//avg(n);
	//output(argv[2],n);

	int x=5,y=10;
	swap(&x,&y);
	return 0;
}

int  input(char *argv1){
	FILE *fpi;
	fpi=fopen(argv1,"r");
	if(fpi==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int count=0,i=0;
	printf("The integers written in %s are ",argv1);
	while(fscanf(fpi,"%d",&getint[i])!=EOF){
		count++;
		if(count>maxdata){
			printf("Check number of integers in %s.\nYou can enter up to 10 integers.\n",argv1);
			exit (1);
		}
		printf("%d ",getint[i]);
		i++;
	}
	return count;
	fclose(fpi);
}

void output(char *argv2,int n){
	FILE *fpo;
	fpo=fopen(argv2,"w");
	if(fpo==NULL){
		printf("FILE OPEN ERROR\n");
		exit (1);
	}
	int i=0;
	printf("The integers written to %s are ",argv2);
	while(i<n){
		fprintf(fpo,"%d ",getint[i]);
		printf("%d ",getint[i]);
		i++;
	}

	fclose(fpo);
}

void sort(int n){
	int i,j,min,tmp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(getint[j]<getint[min]){
				min=j;
			}
		}
		tmp=getint[min];
		getint[min]=getint[i];
		getint[i]=tmp;
	}
}

void sort2(int n){
	int i,max,tmp;
	while(n>=1){
		max=0;
		for(i=1;i<=n-1;i++){
			if(getint[max]<getint[i]){
				max=i;
			}
			if(getint[max]==getint[i]){
				continue;
			}
		}
		tmp=getint[n-1];
		getint[n-1]=getint[max];
		getint[max]=tmp;
		n--;
	}
}

void quicksort(int left,int right){
	int pivot;
	int i,j;
	i=left;
	j=right;
	pivot=getint[(left+right)/2];
	int tmp;

	while(1){
		while(getint[i]<pivot){
			i++;
		}
		while(pivot < getint[j]){
			j--;
		}
		if(i>=j){
			break;
		}
		tmp=getint[i];
		getint[i]=getint[j];
		getint[j]=tmp;
		i++;
		j--;

	}
	if(left < i-1){
		quicksort(left,i-1);
	}
	if(j+1 < right){
		quicksort(j+1,right);
	}
}

void avg(int n){
	int i=0,sum=0,avg;
	while(i < n){
		sum=sum+getint[i++];
	}
	avg=sum/n;
	printf("%d",avg);
}


void  swap(int  *a, int  *b){
  int  temp;
  printf("x=%d,y=%d \n",*a,*b);
  temp = *a;
  *a = *b;
  *b = temp;
  printf("x=%d,y=%d \n",*a,*b);
}










