#include "../mydef.h"
#include <sys/resource.h>
#include <ctype.h>

// Memory Limit 32MB
struct rlimit r1 = {33554432, 33554432};

long int fib(int num)
{
    long int sum = 0, a = 0, b = 1;
    int i;

    for(i=2; i <= num; i++)
    {
        sum = a + b;
        a = b;
        b = sum;    
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    setrlimit(RLIMIT_AS, &r1);
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
    printf("Fibonacci for number %d is: %ld\n", num, fib(num));
    return 0;
}
