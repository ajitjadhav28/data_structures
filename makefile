CC=gcc
PROGS = rmo.bin ltm.bin StackUsingArray.bin StackUsingLl.bin \
		fibRec.bin fibIt.bin linearQueue.bin mulRec.bin
mylibs = mydef.h mylib.c

all: $(PROGS)

rmo.bin : rmo.c mydef.h
	$(CC) -Wall rmo.c -o rmo.bin

ltm.bin : lowerTrangularMatrix.c $(mylibs)
	$(CC) -Wall $^ -o $@

StackUsingArray.bin : StackUsingArray.c $(mylibs)
	$(CC) -Wall $^ -o $@

StackUsingLl.bin : StackUsingLl.c $(mylibs)
	$(CC) -Wall $^ -o $@

fibRec.bin : ./recursion/fib.c $(mylibs)
	$(CC) -Wall $^ -o $@

fibIt.bin : ./iterative/fibIt.c $(mylibs) 
	$(CC) -Wall $^ -o $@

linearQueue.bin : linearQueue.c $(mylibs)
	$(CC) -Wall $^ -o $@

mulRec.bin : ./recursion/multiplication.c $(mylibs)
	$(CC) -Wall $^ -o $@

clean:
	rm $(PROGS)