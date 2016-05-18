#include <stdio.h>

int vf1 = 0;
int vf2 = 1;
int temp = 0;

int main () {
	while (1) {
		temp = vf1 + vf2;
		printf("%x ", temp);
		vf1 = vf2;
		vf2 = temp;
	}
	return 0;
}
