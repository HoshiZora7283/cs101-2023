#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int n;
	time_t curtime;
	time(&curtime);
	FILE* fp;
	srand((unsigned)time(NULL));
	typedef struct lotto{
		int num0;
		int num1[5];
		int num2;
	}lotto;
	lotto lot;
	printf("�w����{�����ֳz�m�ʶR���x\n�аݱz�n�ʶR�X�ռֳz�m�G");
	scanf("%d",lot.num0);
	fp=fopen("lotto.txt","w+");
	fprintf(fp,"======== lotto649 ==========\n");
	fprintf(fp,"= %s =",ctime(&curtime));
	for(int i=0;i<lot.num;i++){
		printf("")
	}
	return 0;
}
