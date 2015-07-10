CFLAGS=-Wall -g
BUILD_DIR=build

all: ex1 ex3

ex1:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex1 ex1.c 

ex3:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex3 ex3.c

clean: 
	rm -f buld/*
