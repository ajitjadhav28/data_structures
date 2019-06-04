outputs = rmo.bin ltm.bin StackUsingArray.bin StackUsingLl.bin
mylibs = mydef.h mylib.c

all: $(outputs)

rmo.bin : rmo.c mydef.h
	gcc -Wall rmo.c -o rmo.bin

ltm.bin : lowerTrangularMatrix.c $(mylibs)
	gcc -Wall $^ -o $@

StackUsingArray.bin : StackUsingArray.c mydef.h 
	gcc -Wall $^ -o $@

StackUsingLl.bin : StackUsingLl.c $(mylibs)
	gcc -Wall $^ -o $@

clean:
	rm $(outputs)