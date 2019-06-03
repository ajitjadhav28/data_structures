outputs = rmo.bin ltm.bin
all: $(outputs)
rmo.bin : rmo.c mydef.h
	gcc -Wall rmo.c -o rmo.bin

ltm.bin : lowerTrangularMatrix.c mydef.h mylib.c
	gcc -Wall $^ -o $@

clean:
	rm $(outputs)