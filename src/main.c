// Anything with the # symbol will be evaluated within preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

#include "mpc.h"

int main(int argc, char** argv) {

	// Init the REPL
	puts("Lispy Version 0.0.0.1");
	
	while(1) {
		// Outputs to prompt and gets user input
		char* input = readline("lispy> ");

		// Adds the input to history
		add_history(input);

		printf("No you're a %s\n", input);

		// Frees up memory of input value
		free(input);
	}

	return 0;
}
