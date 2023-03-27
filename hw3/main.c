#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
	int receipt_id;
	int receipt_price;
	char receipt_time[32];
	int lotto_set[5][7];
}lotto_record_t;

int main() {
	int n, lotto[7];
	int no = 0;
	int a, b, c;
	lotto_record_t lotto_detail1[1];
	lotto_record_t lotto_detail2[1];
	time_t curtime = time(0);
	char* dt = ctime(&curtime);
	dt[strlen(dt) - 1] = 0;

	FILE* fp;
	FILE* fp1;
	if ((fp1 = fopen("record.bin", "rb")) == NULL) {
		no = 1;
		lotto_detail1[0].receipt_id = 1;
	}
	else if ((fp1 = fopen("record.bin", "rb")) != NULL) {
		while ((fread(lotto_detail2, sizeof(lotto_record_t), 1, fp1)) != NULL) {
			no = lotto_detail2[0].receipt_id + 1;
			lotto_detail1[0].receipt_id = lotto_detail2[0].receipt_id + 1;
		}
		fclose(fp1);
	}
	fp1 = fopen("record.bin", "ab+");

	srand((unsigned)time(NULL));
	int i, j, k;

	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩：");
	scanf("%d", &n);
	if (n == 0) {
		printf("請輸入中獎號碼（最多三個）：");
		scanf("%d%d%d", &a, &b, &c);
		printf("輸入中獎號碼為：%02d %02d %02d", a, b, c);
		printf("\n以下為中獎彩卷：\n");

		while (fread(lotto_detail2, sizeof(lotto_record_t), 1, fp1)) {
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 7; j++) {
					if (lotto_detail2[0].lotto_set[i][j] == a || lotto_detail2[0].lotto_set[i][j] == b || lotto_detail2[0].lotto_set[i][j] == c) {
						printf("彩卷 No. %d\n", lotto_detail2[0].receipt_id);
						printf("售出時間：%s\n", lotto_detail2[0].receipt_time);
						printf("號碼：");
						for (k = 0; k < 7; k++) {
							printf("%02d ", lotto_detail2[0].lotto_set[i][k]);
						}
						printf("\n");
						break;
					}
				}
			}
		}
	}
	else {
		lotto_detail1[0].receipt_price = 100 * n;
		printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt", n);

		char lottotxt[17] = "lotto[00001].txt";
		lottotxt[6] = (no / 10000) % 10 + '0';
		lottotxt[7] = (no / 1000) % 10 + '0';
		lottotxt[8] = (no / 100) % 10 + '0';
		lottotxt[9] = (no / 10) % 10 + '0';
		lottotxt[10] = (no % 10) + '0';

		fp = fopen(lottotxt, "w+");
		fprintf(fp, "====== lotto649 ======\n");
		fprintf(fp, "=====+ No.%05d +=====\n", no);
		fprintf(fp, "= %s =\n", dt);

		for (i = 0; i < 32; i++) {
			lotto_detail1[0].receipt_time[i] = dt[i];
		}
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
					lotto_detail1[0].lotto_set[i][j] = lotto[j];
				}
				do {
					lotto[6] = rand() % 10 + 1;
					for (k = 0; k < 6; k++) {
						if (lotto[6] == lotto[k]) break;
					}
				} while (k != 6);
				lotto_detail1[0].lotto_set[i][6] = lotto[6];
				for (int m = 0; m < 7; m++) {
					fprintf(fp, "%02d ", lotto[m]);
				}
				fprintf(fp, "\n");
			}
			else {
				fprintf(fp, " [%d]:  -- -- -- -- -- -- --\n", i + 1);
				for (j = 0; j < 6; j++) {
					lotto_detail1[0].lotto_set[i][j] = 0;
				}
			}
		}
		fprintf(fp, "=====  csie@CGU  =====");
		fwrite(lotto_detail1, sizeof(lotto_record_t), 1, fp1);
		fclose(fp);
		fclose(fp1);
	}
	return 0;
}