#include <stdio.h>

int sum = 0;
int counter = -5;
int array[5] = {3, 4, 5, 6, 7};
int* pointer = array;

int main () {
	for (counter; counter != 0; counter++) {
		sum = sum + *pointer;
		pointer++;
	}
	printf("%x", sum);
	return 0;
}
