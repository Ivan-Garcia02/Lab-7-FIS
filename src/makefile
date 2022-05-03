CXX=g++
CFLAGS=-g -std=c++17 -Wall -Wextra -Wpedantic

main: petition.o system.o user.o main.o 
	${CXX} ${CFLAGS} petition.o system.o user.o main.o -o dorf

clean:
	rm -rf *.o dorf