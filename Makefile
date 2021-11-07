CC=clang
CFLAGS=-WCL4 -g

all: mainapp

mainapp: main.o algorithms.o chooseAlgorithm.o execAll.o selectFolderData.o selectRandomData.o
	$(CC) $(CFLAGS) main.o algorithms.o chooseAlgorithm.o execAll.o selectFolderData.o selectRandomData.o -o mainapp

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm a.out *.o mainapp
