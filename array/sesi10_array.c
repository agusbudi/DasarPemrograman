// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // int usia1, usia2, usia3;    //tanpa array
    // scanf("%d %d %d", &usia1, &usia2, &usia3);
    
    int n;  
    scanf("%d", &n);
    int usia[n];    //pakai array
    for(int i=0;i<n;i++)
        scanf("%d", &usia[i]);
    
    for(int i=0;i<n;i++)
        printf(" %d", usia[i]);
    
    return 0;
}