# Creates a variable (this points to the compiler)
CC=gcc

# First target in the file, default.
all: HelloWorld

# Executes the source code
HelloWorld: HelloWorld.o
	./HelloWorld.o

# Compile the source code
HelloWorld.o: HelloWorld.c
	${CC}  HelloWorld.c   -o HelloWorld.o 

# Deletes the executable binary file
clean:
	rm -rf HelloWorld.o