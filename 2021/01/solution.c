#include <stdio.h>


int main() {
	int n1, n2, a, b, c, d;
	n1 = n2 = 0;

	FILE *fp = fopen("input", "r");

	fscanf(fp, "%d", &b);
	while (fscanf(fp, "%d", &a) != EOF) {
		n1 += a > b;
		b = a;
	}

	rewind(fp);

	fscanf(fp, "%d %d %d", &a, &b, &c);
	while (fscanf(fp, "%d", &d) != EOF) {
		n2 += a < d; // Equivalent to (a + b + c) < (b + c + d)
		a = b;
		b = c;
		c = d;
	}

	fclose(fp);

	printf("Part 1: %d\n", n1);
	printf("Part 2: %d\n", n2);

	return 0;
}
