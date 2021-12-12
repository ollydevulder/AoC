#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	char buf[12] = {};
	int arr[12] = {};
	int i, n;

	FILE *fp = fopen("input", "r");

	while (fscanf(fp, "%[01] ", buf) != EOF) {
		n = strtol(buf, NULL, 2);

		for (i = 0; i < 12; i++)
			if (n & (int) pow(2, 11 - i)) arr[i]++;
	}

	fclose(fp);	

	int g, e;
	g = 0;

	for (i = 0; i < 12; i++) {
		g += (arr[i] > 500) * pow(2, 11 - i);
	}

	e = ~g & 0xFFF; // 12-bit negation

	printf("Part 1: %d\n", g * e);
	
	return 0;
}
