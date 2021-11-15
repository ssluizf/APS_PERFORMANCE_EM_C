# APS PERFORMANCE EM C

### For Windows users:
To compile the code on terminal use:
```
  gcc -c main.c algorithms.c chooseAlgorithm.c execAll.c selectFolderData.c selectRandomData.c eatLine.c
```
Then create and execute the .exe file with:
```
  gcc -o main main.o algorithms.o chooseAlgorithm.o execAll.o selectFolderData.o selectRandomData.o eatLine.o
  start main.exe
```

### For Linux users with Make file:
To compile the code on terminal use, with the Makefile:
```
  make
```
Then execute the file with:
```
  ./main
```
