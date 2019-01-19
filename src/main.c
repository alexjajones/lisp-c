// Anything with the # symbol will be evaluated within preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

#include "mpc.h"

int main(int argc, char **argv) {
    // Define parsers
    mpc_parser_t *Start = mpc_new("start");
    mpc_parser_t *End = mpc_new("end");
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    // Define the basic language
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                   \
    start    : /wow/ ;                                  \
    end      : /lispy/ ;                                \
    number   : /-?[0-9]+/ | /[0-9]+\\.[0-9]+/ ;         \
    operator : '+' | '-' | '*' | '/' | /add/ | /sub/ | /mul/ | /div/ ; \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/<start> <operator> <expr>+ <end>/$/ ; \
    ", Start, End, Number, Operator, Expr, Lispy);

    // Init the REPL
    puts("Lispy Version 0.0.0.1");

    while (1) {
        // Outputs to prompt and gets user input
        char *input = readline("lispy> ");

        // Adds the input to history
        add_history(input);

        mpc_result_t r;

        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        // mpc_cleanup(4, Number, Operator, Expr, Lispy);

        // Free memory of input value
        free(input);
    }

    return 0;
}
