#include<stdio.h>
int main(){
	char a[]="81c8g8u168";
	int len=sizeof(a);
	for(int i=0;i<len;i++){
		if(a[i]=='1') printf("I ");
		else if(a[i]=='2') printf("II ");
		else if(a[i]=='3') printf("III ");
		else if(a[i]=='4') printf("IV ");
		else if(a[i]=='5') printf("V ");
		else if(a[i]=='6') printf("VI ");
		else if(a[i]=='7') printf("VII ");
		else if(a[i]=='8') printf("VIII ");
		else if(a[i]=='9') printf("IX ");
		else printf("%c ",a[i]);
	}
	return 0;
}
