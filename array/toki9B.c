//https://tlx.toki.id/courses/basic/chapters/09/problems/B
#include <stdio.h>

int main(){
	int N, arr[105];
	while(scanf("%d", &arr[N]) != EOF)
		N++;
	int i;
	for(i=N-1;i>=0;i--)
		printf("%d\n", arr[i]);
}
