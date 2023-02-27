#include<stdio.h>
int main(){
	char a[]="Hello";
	int i,len=sizeof(a)-1;
	char b[len],tmp;
	for(int i=0;i<len;i++){
		b[i]=a[i];
	}
	for(int i=0;i<len/2;i++){
		tmp=b[i];
		b[i]=b[len-i-1];
		b[len-i-1]=tmp;
	}
	for(int i=0;i<len;i++){
		if(a[i]<91&&b[i]>96){
			b[i]=b[i]-32;
		}
		else if(a[i]>96&&b[i]<91){
			b[i]=b[i]+32;
		}
		else{
			continue;
		}
	}
	printf("a = %s\na = %s",a,b);
	return 0;
}
