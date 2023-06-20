CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pilha.o
HDRS = $(INC)/mergeSort.h $(INC)/radixSort.h $(INC)/pilha.h $(INC)/ponto.h $(INC)/graham.h $(INC)/functions.h
CFLAGS = -Wall -c -I$(INC)

#EXE = $(BIN)/main

#run: $(EXE)	
#	$(EXE)

$(BIN)/fecho: $(OBJS)
	$(CC) -pg -o ./fecho $(OBJS) $(LIBS)

#$(BIN)/main: $(OBJS)
#	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp

see:
	gprof $(EXE) gmon.out

clean:
	rm -f $(EXE) $(OBJS) gmon.out
