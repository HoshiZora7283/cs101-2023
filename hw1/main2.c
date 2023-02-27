#include<stdio.h>
void printA(int A){
	for(int i=0;i<A;i++){
		printf("A");
	}
}
void printB(int B){
	for(int i=0;i<B;i++){
		printf("B");
	}
}
void printC(int C){
	for(int i=0;i<C;i++){
		printf("C");
	}
}
int main(){
	char a[]="A3B2C4A9";
	int A,B,C;
	int len=sizeof(a);
	for(int i=0;i<len;i++){
		if(a[i]==65){
			A=a[i+1]-'0';
			printA(A);
		}
		if(a[i]==66){
			B=a[i+1]-'0';
			printB(B);
		}
		if(a[i]==67){
			C=a[i+1]-'0';
			printC(C);
		}
	}
	return 0;
}
