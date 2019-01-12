# Builds and runs hello world program
echo "Compiling"
cc --std=c99 -Wall helloworld.c -o hello_world
echo "Compiled"
./hello_world
