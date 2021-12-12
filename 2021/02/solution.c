#include <stdlib.h>
#include <stdio.h>


int main() {
	char chr = 0;
	int num;
	
	int d1 = 0, p1 = 0;
	int d2 = 0, p2 = 0, a = 0;

	FILE *fp = fopen("input", "r");

	while (fscanf(fp, "%c%*[a-z] %d\n", &chr, &num) != EOF) {
		switch (chr) {
			case 'f':
				p1 += num;
				p2 += num;
				d2 += a * num;
				break;
			case 'd':
				d1 += num;
				a += num;
				break;
			case 'u':
				d1 -= num;
				a -= num;
		}
	}

	fclose(fp);

	printf("Part 1: %d\n", d1 * p1);
	printf("Part 2: %d\n", d2 * p2);

	return 0;
}
