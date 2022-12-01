#include<stdio.h>
#include<string.h>
#define STRSIZ 10

typedef union {
	int wears_wig;
	char color[20];
} hair_t;

typedef struct {
	int bald;
	hair_t h;
} hair_info_t;

void print_hair_info(hair_info_t hair) { /* input - structure to display */
	if (hair.bald) {
		printf("Subject is bald");
		if (hair.h.wears_wig)
			printf(", but wears a wig.\n");
		else
			printf(" and does not wear a wig.\n");
	} else {
		printf("Subject's hair color is %s.\n", hair.h.color);
	}
}

int main(){
	hair_info_t mr_Smith;
	mr_Smith.bald = 1;
	mr_Smith.h.wears_wig = 0;
	
	print_hair_info(mr_Smith);
	
	hair_info_t mrs_Smith;
	mrs_Smith.bald = 0;
	strcpy(mrs_Smith.h.color, "blonde");
	
	print_hair_info(mrs_Smith);	
}
