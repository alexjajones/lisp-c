#include <stdio.h>

void print_x_hello_world(int x) {
		// Simple function that prints x hello worlds
	for (int i = 0; i < x; i++) {
		puts("Hello world");
	}
}
	

int main() {
	print_x_hello_world(9);	

	return 0;
}
