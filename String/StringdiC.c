/*referensi : 
	https://tlx.toki.id/courses/basic/chapters/11/lessons/A
	https://www.tutorialspoint.com/c_standard_library/string_h.htm
*/
#include<stdio.h>
#include<string.h>

int main() {
	char s[100];
	char t[100];
	
	scanf("%s %s", s, t);
	int i;
	
	//mencetak string sampai bertemu null 
	for(i=0;s[i]!= '\0';i++){
		printf("%c-", s[i]);
	}
	printf("\n");
	i=0;
	//dengan while
	while(s[i]!='\0')
		printf("%c-", s[i++]);

	//mencetak string secara ringkas
	printf("\n%s\n", s);
	
	//mengetahui panjang string
	printf("panjang string: %d\n", strlen(s));
	
	// Buruk, O(N^2)
	for (i = 0; i < strlen(s); i++){
		printf("%c", s[i]);
	}
	printf("\n");	
	// Baik, O(N)
	int len = strlen(s);
	for (i = 0; i < len; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
	printf("Perbandingan: %d\n", strcmp(s, t)); //jika sama, maka return value 0
	
	//copy string to another string variable
	strcpy(s,t);
	printf("Copy string ke variabel yg lain: %s --- %s\n", s, t);
	
    memset(s,'#',4);
    printf("Memset: %s\n", s);
    
	//mencetak string tanpa printf
  	puts(t);  
    char nama[100];
    
//    opsi selain scanf %s
//	gets(nama);  // a common source of buffer overflow vulnerabilities and should never be used;
	fgets(nama, sizeof(nama), stdin);
	
    puts(nama);
    

   return(0);
}
