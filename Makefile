test:
	make build_tests && ./tests

build_tests:
	cc --std=c99 -Wall src/unit_tests.c src/helpers.c src/libs/mpc.c -o tests -ledit -lm

build:
	cc --std=c99 -Wall src/main.c src/helpers.c src/libs/mpc.c -o main -ledit -lm
