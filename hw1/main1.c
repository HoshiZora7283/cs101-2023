#include<stdio.h>
int main(){
	char a[]="AABBBCCCCddd";
	int len=sizeof(a);
	int A=0,B=0,C=0,D=0;
	for(int i=0;i<len;i++){
		if(a[i]==65){
			A++;
		}
		if(a[i]==66){
			B++;
		}
		if(a[i]==67){
			C++;
		}
		if(a[i]==100){
			D++;
		}
	}
	printf("A%d B%d C%d d%d",A,B,C,D);
	return 0;
}
