#include "../mydef.h"
#include <sys/resource.h>
#include <ctype.h>

MEM_LIMIT_32MB;

long mul(int a, int b)
{
	if(a == 0 || b == 0) return 0;
	if(a == 1) return b;
	if(b == 1) return a;
	return b + mul(a-1, b);
}

int main(int argc, char *argv[])
{	
	int a=0, b=0;
	setrlimit(RLIMIT_AS, &r1);
	if(argc == 1){
        printf("Enter two number to calculate multiplication Ex.-3,2:\n");
        scanf("%d,%d", &a, &b);
    } else {
        if(!isdigit(argv[1][0]) || !isdigit(argv[2][0])) {
            printf( Yellow "Enter integer number as first & second argument "
                    "\nto calculate multiplication. Example: %s" Bold_Yellow " 10 5\n", argv[0]);
            exit(1);
        }
        a = atoi(argv[1]);
		b = atoi(argv[2]);
    }
	// Try 900000 * 2, Gives seg fault
	// printf("%ld\n",mul(a,b));

	// Minimize recursion depth, calculates 900000 * 2  
	if(a < b)
		printf("%ld\n",mul(a,b));
	else
		printf("%ld\n",mul(b,a));
	
	return 0;
}