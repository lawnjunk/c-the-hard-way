CLAGS=-Wall -g
BUILD_DIR=build

all: ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 play

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

ex10: 
	cc ${CFLAGS} -o ${BUILD_DIR}/ex10 ex10.c

ex11:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex11 ex11.c

ex12:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex12 ex12.c

ex13:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex13 ex13.c

ex14:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex14 ex14.c

ex15:
	cc ${CFLAGS} -o ${BUILD_DIR}/ex15 ex15.c
	
play:
	cc ${CFLAGS} -o ${BUILD_DIR}/play pointer-play.c

clean: 
	rm -f buld/*
