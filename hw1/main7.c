#include<stdio.h>
void hex(char a[]){
	int total=0;
	int n=1;
	for(int i=7;i>=0;i--){
		if(a[i]=='1'){
			n=1;
			if(i<7){
				int j=7-i;
				while(j>0){
					n=n*2;
					j--;
				}
				total+=n;
			}
			else{
				total++;
			}
		}
	}
	printf("%X\n",total);
}
int main(){
	char a[]="10001111";
	char b[]="10011110";
	hex(a);
	hex(b);
	return 0;
}
