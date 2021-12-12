#include <stdio.h>
#define UL unsigned long int

UL sum();
UL fish[9] = {};

int main() {
	int n, i, ans1; 
	UL new;

	FILE *fp = fopen("input", "r");

	while (fscanf(fp, "%d,", &n) != EOF)
		fish[n]++;

	fclose(fp);

	n = 0;
	while (n < 256) {
		if (n == 80) ans1 = sum();

		new = fish[0];
		for (i = 0; i < 8; i++)
			fish[i] = fish[i + 1];
		fish[6] += new;
		fish[8] = new;
		n++;
	}

	printf("Part 1: %d\n", ans1); 
	printf("Part 2: %lu\n", sum()); 

	return 0;
}


UL sum() {
	int i;
	UL t = 0;
	for (i = 0; i < 9; i++) t += fish[i];
	return t;
}
