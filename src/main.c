#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {

	// Init the REPL
	puts("Lispy Version 0.0.0.1");
	
	while(1) {
		// Prints to stdout without newline
		fputs("lispy> ", stdout);
		// Waits for user input and assigns to `input`	
		fgets(input, 2048, stdin);

		printf("No you're a %s", input);
	}

	return 0;
}
