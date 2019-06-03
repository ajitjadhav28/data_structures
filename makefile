outputs = rmo.bin ltm.bin StackUsingArray.bin
all: $(outputs)
rmo.bin : rmo.c mydef.h
	gcc -Wall rmo.c -o rmo.bin

ltm.bin : lowerTrangularMatrix.c mydef.h mylib.c
	gcc -Wall $^ -o $@

StackUsingArray.bin : StackUsingArray.c mydef.h 
	gcc -Wall $^ -o $@

clean:
	rm $(outputs)