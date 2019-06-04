// Author: Ajit J.
// Subject: Data Structures

#include "../mydef.h"
#include <sys/resource.h>

// Memory Limit 32MB
struct rlimit r1 = {33554432, 33554432};

long int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
    int num = 0;
    setrlimit(RLIMIT_AS, &r1);
    if(argc == 1){
        printf("Enter number to find fibonacci:\n");
        scanf("%d", &num);
    } else {
        num = atoi(argv[1]);
    }
    printf("Fibonacci for number %d is: %ld\n", num, fib(num));
    return 0;
}
