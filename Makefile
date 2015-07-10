CFLAGS=-Wall -g
BUILD_DIR=build

all: ex1 ex3 ex7 ex8

ex1:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex1 ex1.c 

ex3:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex3 ex3.c

ex7: 
	cc ${CFLAGS} -o ${BUILD_DIR}/ex7 ex7.c

ex8: 
	cc ${CFLAGS} -o ${BUILD_DIR}/ex8 ex8.c

ex9: 
	cc ${CFLAGS} -o ${BUILD_DIR}/ex9 ex9.c

clean: 
	rm -f buld/*
