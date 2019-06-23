CC = gcc
CFLAG = -Wall
BIN = ./bin/
LIST = rmo.bin ltm.bin StackUsingArray.bin StackUsingLl.bin \
		fibRec.bin fibIt.bin linearQueue.bin mulRec.bin mulIt.bin \
		intDivisionIt.bin intDivisionRec.bin circularQueue.bin \
		arrayTraversal.bin reverseLinkedList.bin factorialRec.bin \
		arrayOperations.bin binarySearchTree.bin
PROGS = $(addprefix $(BIN), $(LIST))
COMPL = $(CC) $(CFLAG) $^ -o $@
mylibs = mydef.h mylib.c

all: $(PROGS)

$(BIN)rmo.bin : rmo.c mydef.h
	$(CC) $(CFLAG) $^ -o $@

$(BIN)ltm.bin : lowerTrangularMatrix.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)StackUsingArray.bin : StackUsingArray.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)StackUsingLl.bin : StackUsingLl.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)fibRec.bin : ./recursion/fib.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)fibIt.bin : ./iteration/fibIt.c $(mylibs) 
	$(CC) $(CFLAG) $^ -o $@

$(BIN)linearQueue.bin : linearQueue.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)circularQueue.bin : circularQueue.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)mulRec.bin : ./recursion/multiplication.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)mulIt.bin : ./iteration/multiplication.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)intDivisionIt.bin : ./iteration/intDivision.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)intDivisionRec.bin : ./iteration/intDivision.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)arrayTraversal.bin : ./recursion/arrayTraversal.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)reverseLinkedList.bin : ./recursion/reverseLinkedList.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

$(BIN)factorialRec.bin : ./recursion/factorial.c $(mylibs)
	$(COMPL)

$(BIN)arrayOperations.bin : ./recursion/arrayOperations.c $(mylibs)
	$(COMPL)

$(BIN)binarySearchTree.bin : bst.c bTree.c $(mylibs)
	$(COMPL)

$(shell mkdir -p bin)

clean:
	rm $(PROGS)