CC=gcc
CFLAG=-Wall
PROGS = rmo.bin ltm.bin StackUsingArray.bin StackUsingLl.bin \
		fibRec.bin fibIt.bin linearQueue.bin mulRec.bin
mylibs = mydef.h mylib.c

all: $(PROGS)

rmo.bin : rmo.c mydef.h
	$(CC) $(CFLAG) rmo.c -o rmo.bin

ltm.bin : lowerTrangularMatrix.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

StackUsingArray.bin : StackUsingArray.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

StackUsingLl.bin : StackUsingLl.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

fibRec.bin : ./recursion/fib.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

fibIt.bin : ./iterative/fibIt.c $(mylibs) 
	$(CC) $(CFLAG) $^ -o $@

linearQueue.bin : linearQueue.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

mulRec.bin : ./recursion/multiplication.c $(mylibs)
	$(CC) $(CFLAG) $^ -o $@

clean:
	rm $(PROGS)