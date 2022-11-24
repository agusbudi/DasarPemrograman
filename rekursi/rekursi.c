#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void cekPalindrom(char *kata){	//iterative
	int i, status=0;
	int length = strlen(kata);
	
	//contoh: kasurrusak
	for(i=0;i<(length/2); i++){
		if(kata[i]!=kata[length-1-i]){
			status=1;
			break;
		}
	}
	if(status==0)
		printf("YA");
	else
		printf("TIDAK");
}

//recursive
int faktorial(int x) {
	if (x == 1)		//base case 1! = 1
		return 1;
	else
		return x * faktorial(x-1);	//contoh: recurrence: 6*5! --> 6*5*4! --> ... *1! = 720
}

int faktorialIteratif(int x) {
	int jawaban = 1; //base case: 1! = 1
	int i;
	for (i = 2; i <= x; i++)	//loop
		jawaban *= i;
		
	return jawaban;
}


//recursive
int fibonacci(int N) {
	if (N <= 1)
		return N;	//f1 = 1 
	else
		return fibonacci(N-1) + fibonacci(N-2);		//f(N) = f(N-1) + f(N-2)
}

int N=0;
int catat[100];
bool pernah[100];

//permutasi iteratif: problemnya looping harus ditulis manual!
void password(){
	int i, j,k;
	for (i = 1; i <= 3; i++) 
		for (j = 1; j <= 3; j++) 
			for (k = 1; k <= 3; k++) 
				printf("%d%d%d\n",i, j, k);
}

//permutasi: rekursif
void tulis(int kedalaman) {
	if (kedalaman >= N) {	//base case
		int i;
		for(i = 0; i < N; i++)
			printf("%d", catat[i]); 		// Cetak password
		printf("\n");
	} else {
		int i;
		// Masuk ke lapisan lebih dalam
		for(i = 1; i <= N; i++){
			if (!pernah[i]) { // i belum pernah?
				pernah[i] = true; // Gunakan
				catat[kedalaman] = i; // Catat di sini
				tulis(kedalaman + 1);		//recurrence relation
				pernah[i] = false; // Selesai menggunakan
			}
		}
	}
}

int main(){
	//palindrom:
//	char kata[100];
//	scanf("%s", kata);
//	cekPalindrom(kata);
	
	//fibonacci
	int x;
//	scanf("%d", &x);
//	printf("%d", fibonacci(x));

	//permutasi:
//	password();
	
	N = 3;
	tulis(0);

	return 0;
}
