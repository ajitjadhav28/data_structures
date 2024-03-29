CC = gcc
CFLAG = -Wall
BIN = ./bin/
LIST = rmo.bin ltm.bin StackUsingArray.bin StackUsingLl.bin \
		fibRec.bin fibIt.bin linearQueue.bin mulRec.bin mulIt.bin \
		intDivisionIt.bin intDivisionRec.bin circularQueue.bin \
		arrayTraversal.bin reverseLinkedList.bin factorialRec.bin \
		arrayOperations.bin avlTree.bin structure.bin
PROGS = $(addprefix $(BIN), $(LIST))
COMPL = $(CC) $(CFLAG) $^ -o $@
mylibs = mylib.c

all: $(PROGS)

$(BIN)rmo.bin : rmo.c 
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

$(BIN)avlTree.bin : ./avl_tree/bst.c ./avl_tree/bTree.c stack.c darray.c $(mylibs)
	$(COMPL) -lm 

$(BIN)structure.bin : structure.c stack.c $(mylibs)
	$(COMPL)
	
$(shell mkdir -p bin)

docs:
	@doxygen 
	@open ./docs/html/index.html

clean:
	rm -rf $(PROGS)

clean-docs:
	rm -rf ./docs

clean-all:
	rm -rf $(PROGS) ./docs
