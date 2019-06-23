/**
 * @file factorial.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Finding factorial recursively
 * @date 09-06-2019
 */

#include "../mydef.h"
#include <sys/resource.h>

MEM_LIMIT_32MB;

/**
 * @brief Recursive defination of factorial
 * 
 * @param n
 *  Integer number to find factorial
 * @return long long unsigned int 
 *  Factorial of n
 */
long long unsigned int factorial(unsigned int n)
{
    if(n == 0) return 1;
    return n * factorial(n-1);      // `n--` is wrong!
}

int main(int argc, char const *argv[])
{
    int i = 0; 
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
