#include<stdio.h>
#include<stdlib.h> 
int main(){
	int a[]={1,2,3};
	char b[]="ABC";
	float c[]={1.1,1.2,1.3};
	int a_read[sizeof(a)-1];
	FILE* fp;
	
	fp=fopen("a.bin","wb+");
	fwrite(a,sizeof(a),1,fp);
	fread(a_read,sizeof(a),1,fp);
	for(int i=1;i<sizeof(a);i++){
		printf("%d",a[i]);
	}
	fclose(fp);
	
	return 0;
}
