#include<stdio.h>
int main(){
	char a[]="ABCabcABC";
	int shift=4;
	int len=sizeof(a)-1;
	char b[len];
	for(int i=0;i<len;i++){
		if((i+shift)<len){
			b[i]=a[i+shift];
			printf("%c",b[i]);
		}
		if((i+shift)>=len){
			b[i]=a[i+shift-len];
			printf("%c",b[i]);
		}
	}
	return 0;
}
