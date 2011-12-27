#include <stdio.h>

int main (int argc, char** argv) {
	int highestExp = argc-2;
	if (highestExp < 0) {
		highestExp = 0;
	}
	int var = atoi(argv[argc-1]);
	int total = 0;
	int index, current;
	for (index = 0; index < argc-1, highestExp >= 0; index++, highestExp--) {
		int factor = atoi(argv[index]);
		current = factor * (power(var, highestExp));
		total += current;
	}
	printf("%d\n", total);
}

int power (int base, int exp) {
	int current = base;
	if (exp == 0) {
		return 1;
	}
	while (exp > 1) {
		current *= base;
		exp--;
	}
	return current;
}