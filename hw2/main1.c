#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main() {
	int n, lotto[7];

	time_t curtime = time(0);
	char* dt = ctime(&curtime);
	dt[strlen(dt) - 1] = 0;

	FILE* fp;
	srand((unsigned)time(NULL));

	printf("�w����{�����ֳz�m�ʶR���x\n�аݱz�n�R�X�ռֳz�m�G");
	scanf("%d", &n);
	printf("�w���z�ʶR�� %d �ռֳz�զX��X�� lotto.txt", n);
	int i, j, k;

	fp = fopen("lotto.txt", "w+");
	fprintf(fp, "====== lotto649 ======\n");
	fprintf(fp, "= %s =\n", dt);
	for (i = 0; i < 5; i++) {
		if (i < n) {
			fprintf(fp, " [%d]:  ", i + 1);
			for (j = 0; j < 6; j++) {
				do {
					lotto[j] = rand() % 69 + 1;
					for (k = 0; k < j; k++) {
						if (lotto[j] == lotto[k]) break;
					}
				} while (k != j);
			}
			do {
				lotto[6] = rand() % 10 + 1;
				for (k = 0; k < 6; k++) {
					if (lotto[6] == lotto[k]) break;
				}
			} while (k != 6);
			for (int m = 0; m < 7; m++) {
				fprintf(fp, "%02d ", lotto[m]);
			}
			fprintf(fp, "\n");
		}
		else {
			fprintf(fp, " [%d]:  -- -- -- -- -- -- --\n", i + 1);
		}
	}
	fprintf(fp, "=====  csie@CGU  =====");
	return 0;
}