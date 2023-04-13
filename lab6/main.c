#include<stdio.h>
int multiplication(int i, int j) {
	if (i == 9 && j == 9) {
		printf("%d*%d=%d", i, j, i * j);
		return 0;
	}
	if (i == 9) {
		printf("%d*%d=%d ", i, j, i * j);
		multiplication(i, j + 1);
		return 0;
	}
	else if (j == 9) {
		printf("%d*%d=%d \n", i, j, i * j);
		multiplication(i + 1, j - 8);
	}
	else {
		printf("%d*%d=%d ", i, j, i * j);
		multiplication(i, j + 1);
	}
}
int main() {
	multiplication(1, 1);
	return 0;
}