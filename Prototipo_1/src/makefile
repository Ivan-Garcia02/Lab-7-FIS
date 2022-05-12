CXX=g++
CFLAGS=-g -std=c++17 -Wall -Wextra -Wpedantic

PRACTICA: main remove_o

main: petition.o system.o user.o main.o 
	${CXX} ${CFLAGS} petition.o system.o user.o main.o -o dorf

remove_o:
	rm -rf *.o

clean:
	rm -rf *.o dorf