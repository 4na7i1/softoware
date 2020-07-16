#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 10

int input(char *argv1,int *array);
void sort(int n,int *array);
int output(char *argv2, int n,int *array);


int main(int argc, char *argv[]){
	int n;
	int array[MAXDATA];
	if (argc != 3){
	  fprintf(stderr,"引数の個数が正しくありません。\n");
	  return 1;
	}
	n = input(argv[1],array);

	sort(n,array);

	output(argv[2],n,array);
	return 0;
}

int input(char *argv1,int *array){
	int count = 0,temp[MAXDATA];
	int i=0;

	FILE *sfp;
	sfp=fopen(argv1, "r");


	if(sfp == NULL){
	  printf("コピー元のファイルがオープン出来ません。\n");
	  return 1;
	}
	while(fscanf(sfp, "%d",&temp[++i]) == 1){
	  if(count >= MAXDATA){
	   printf("データの個数が上限に達しています。\n");
	   return 1;
	  }
	  array[count++]=temp[i];
	}
	for(i=0;i<count;i++){
		printf("%d ",*array);
		array++;
	}
	fclose(sfp);
	return count;
}


int output(char *argv2, int n,int *array){
	FILE *dfp;
	int i;

	if((dfp = fopen(argv2, "w")) == NULL){
	  printf("コピー先のファイルがオープン出来ません。\n");
	  return 1;
	}
	for(i = 0; i < n; i++){
	  fprintf(dfp, "%d ", array[i]);
	}
	fclose(dfp);
	return 0;

}

void sort(int n,int *array){
           int i,j,max=0,c,m;
           for(j=1;j<n-1;j++){
        	   for(i=0;i<n-j;i++){
        		   if(array[i]>max){
        			   max=array[i];
								 c=i;
        		   }
        		   else   ;
                      }
        	   m=array[n-j];
        	   array[n-j]=array[c];
        	   array[c]=m;
           }
       	for(i=0;i<n;i++){
       		printf("%d ",*array);
       		array++;
       	}
           }
