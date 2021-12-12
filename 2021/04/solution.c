#include <stdio.h>


void blotBoards(int);
int checkBoards();
int boardSum(int);

int nums[100];
int boards[100][5][5];

int main() {
	int i, j, k, ret, n;
	k = ret = 0;

	FILE *fp = fopen("input", "r");

	for (i = 0; i < 100; i++)
		fscanf(fp, "%d%*[, ]", &nums[i]);

	while (ret != EOF) {
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				ret = fscanf(fp, "%d", &boards[k][i][j]);
		k++;
	}

	fclose(fp);

	// numbers and boards are now in memory

	for (i = 0; i < 100; i++) {
		blotBoards(nums[i]);
		n = checkBoards();
		if (n != -1) break;
	}

	printf("Part 1: %d\n", nums[i] * boardSum(n));


	return 0;
}


void blotBoards(int n) {
	int i, j, k;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 5; j++)
			for (k = 0; k < 5; k++)
				if (boards[i][j][k] == n)
					boards[i][j][k] = -1;

}

int checkBoards() {
	int found = -1;
	int i, j, k;
	int sum = 0;

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				sum += boards[i][j][k];
			}
			if (sum == -5) {
				found = i;
				break;
			}
			sum = 0;
		}
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				sum += boards[i][k][j];
			}
			if (sum == -5) {
				found = i;
				break;
			}
			sum = 0;
		}
		if (found != -1) break;
	}


	return found;
}

int boardSum(int n) {
	int i, j, sum;
	sum = 0;

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			sum += boards[n][i][j] == -1 ? 0 : boards[n][i][j];
	return sum;
}
