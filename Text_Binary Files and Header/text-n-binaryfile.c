#include<stdio.h>

int main(){

//	//escape sequences	
//	printf("\f\t\t\tFinal Report\r\t\t\t____________ \\ %% \n");
//	printf("%5d%4d\n",100, 2);

	//read file	
	FILE *infilep;
	infilep = fopen("data.txt", "r");
	
	if (infilep == NULL){
		printf("Cannot open data.txt for input\n");
		return 0;
	}		
	int num;
	fscanf(infilep, "%d", &num);
	printf("%d", num);
	
	fclose(infilep);

//
//	FILE *outfilep;
//	outfilep = fopen("results.txt", "w");
//	fprintf(outfilep,"Number = %d\n", num);
	
	return 0;
}
