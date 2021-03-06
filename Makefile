CC=clang
CFLAGS=-WCL4 -g

all: main

main: main.o algorithms.o chooseAlgorithm.o execAll.o selectFolderData.o selectRandomData.o eatLine.o
	$(CC) $(CFLAGS) main.o algorithms.o chooseAlgorithm.o execAll.o selectFolderData.o selectRandomData.o eatLine.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm a.out *.o main
