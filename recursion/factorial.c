// Author: Ajit Jadhav
// Subject: Data Structures
// Date: 09-06-2019 16:51
// Desc: Finding factorial recursively

#include "../mydef.h"
#include <sys/resource.h>

MEM_LIMIT_32MB;

long long unsigned int factorial(unsigned int n)
{
    if(n == 0) return 1;
    return n * factorial(n-1);      // `n--` is wrong!
}

int main(int argc, char const *argv[])
{
    int i = 0;
    /* code */
    setrlimit(RLIMIT_AS, &r1);
    if(argc == 1) {
        ps("Enter number to calculate factorial.");
        si(i);
    } else {
        i = strtol(argv[1], NULL, 10);
    }
    if(i < 0){
        printError("Factorial of negative number not defined.");
        exit(1);
    }
    printf("Factorial of %d is: %llu\n", i, factorial(i));
    return 0;
}
