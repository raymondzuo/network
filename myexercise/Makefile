include Make.defines

PROGS =	myclient myserver tcpcli tcpsvr cliselect \
		svrselect

all:	${PROGS}

myclient:	myclient.o
		${CC} ${CFLAGS} -o $@ myclient.o ${LIBS}
myserver:	myserver.o
		${CC} ${CFLAGS} -o $@ myserver.o ${LIBS}
tcpcli:	tcpcli.o
		${CC} ${CFLAGS} -o $@ tcpcli.o ${LIBS}
tcpsvr:	tcpsvr.o
		${CC} ${CFLAGS} -o $@ tcpsvr.o ${LIBS}
cliselect:	cliselect.o strcliselect.o
		${CC} ${CFLAGS} -o $@ cliselect.o strcliselect.o ${LIBS}
strcliselect.o:	strcliselect.c
		${CC} ${CFLAGS} -o $@ -c strcliselect.c ${LIBS}
svrselect:	svrselect.o
		${CC} ${CFLAGS} -o $@ svrselect.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
