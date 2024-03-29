// Author: Ajit J.
// Subject: Data Structures
// Date: 05/06/2019

#include "../mydef.h"
#include <sys/resource.h>
#include <ctype.h>

MEM_LIMIT_32MB;

long int divide(int a, int b)
{
    if(b == 0){
		printError("Division by Zero!");
		exit(1);
	}
	if(a == 0) return 1;
	if(a < 0) return 0;
	return 1 + divide(a-b, b);
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
            printf( Yellow "Enter unsigned integer number as first & second argument "
                    "\nto calculate integer division. Example: %s" Bold_Yellow " 10 5\n", argv[0]);
            exit(1);
        }
        a = atoi(argv[1]);
		b = atoi(argv[2]);
    }
	
	printf("%ld\n",divide(a,b));
	
	return 0;
}