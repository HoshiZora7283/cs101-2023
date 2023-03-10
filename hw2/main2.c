#include<stdio.h>
int main() {
	char code[256];
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("main2.c", "r");
	fp2 = fopen("main2.txt", "w+");
	while ((fgets(code, sizeof(code), fp1)) != NULL) {
		fputs(code, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}