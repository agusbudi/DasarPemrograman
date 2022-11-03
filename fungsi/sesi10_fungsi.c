// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

void cetak(int n){
    for(int j=0;j<n;j++){
        for(int i=0;i<=j;i++){
            printf("*");
        }
        printf("\n");
    }
}

void swap(int *a, int *b){
    int temp = *b;
    *b=*a;
    *a= temp;
}

float hitungAkhir(int a, int b){    //passing by value
    a=a+1;
    b=b-1;
    return sqrt(a*a + b*b);
}

void Phytagoras(int a, int b, float *c){  //passing by value and reference (for var c)
    *c=sqrt(a*a + b*b);
    a=a+1;
    b=b+1;
}

int main() {
    int n;
    scanf("%d", &n);
    cetak(n);
    int a, b;
    float c = 0.0;
    scanf("%d %d", &a, &b);
    Phytagoras(a,b, &c);
    swap(&a,&b);
    printf("%d %d %.2f", a, b, c);
    
    return 0;
}
