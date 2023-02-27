#include<stdio.h>
void print(char a[],int len){
	for(int i=0;i<len;i++){
		if(a[i]<97){
			printf("%c",a[i]);
		}
	}
	printf("\n");
}
int main(){
	char a[]="-99acbc";
	char b[]="99acbc";
	char c[]="ac-99bc";
	int lena=sizeof(a);
	int lenb=sizeof(b);
	int lenc=sizeof(c);
	print(a,lena);
	print(b,lenb);
	print(c,lenc);
	return 0;
}
