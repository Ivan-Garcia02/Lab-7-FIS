CXX=g++
CFLAGS=-g -std=c++17 -Wall -Wextra -Wpedantic

main: system.o user.o functions.o graphics.o main.o 
	${CXX} ${CFLAGS} system.o user.o main.o functions.o graphics.o -o dorf

clean:
	rm -rf *.o dorf