/**
 * @file fibIt.c    
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Print fibonacci sequence
 * @date 04-07-2019
 * @subject Data Structures
 * 
 */

#include "../mydef.h"
#include <ctype.h>

/**
 * @brief Prints fibonacci sequence of length **num**
 * 
 * @param num length of fibonacci sequence
 */
void fib(unsigned int num)
{
    unsigned int a = 0, b = 1;
    pi(a); pi(b);
    for(; num > 2; num--)
    {
        a += b;
        pi(a);
        a += b;
        b = a - b;
        a = a - b;
    }
}

int main(int argc, char const *argv[])
{
    unsigned int num = 0;
    if(argc == 1){
        printf("Enter number to find fibonacci:\n");
        scanf("%d", &num);
    } else {
        if(!isdigit(argv[1][0])) {
            printf( Yellow "Enter integer number as first argument "
                    "\nto find fibonacci. Example: %s" Bold_Yellow " 50\n", argv[0]);
            exit(1);
        }
        num = atoi(argv[1]);
    }
    printf("Fibonacci sequence of length %d:\n", num);
    fib(num); ps("");
    return 0;
}
