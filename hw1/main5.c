#include<stdio.h>
int main(){
	char a[]="-9 8 7 6 5 -4 3 -2 1";
	int i=4,j,k;
	int len=sizeof(a);
	int b[9];
	int tmp;
	for(j=0,k=0;j<len;j++,k++){
		if(a[j]==' '){
			k--;
			continue;
		}
		else if(a[j]=='-'){
			j++;
			b[k]='0'-a[j];
			continue;
		}
		else{
			b[k]=a[j]-'0';
		}
	}
	for(j=8;j>0;j--){
		for(int k=0;k<j;k++){
			if(b[k]<b[k+1]){
				tmp=b[k];
				b[k]=b[k+1];
				b[k+1]=tmp;
			}
		}
	}
	printf("%d",b[i-1]);
	return 0;
}
