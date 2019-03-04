include Make.defines

PROGS =	myclient myserver

all:	${PROGS}

myclient:	myclient.o
		${CC} ${CFLAGS} -o $@ myclient.o ${LIBS}
myserver:	myserver.o
		${CC} ${CFLAGS} -o $@ myserver.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
