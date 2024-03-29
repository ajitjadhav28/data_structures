/**
 * @file multiplication.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Multiplication by addition
 * @date 05/06/2019
 * @subject Data Structures
 * 
 */

#include "../mydef.h"
#include <ctype.h>

/**
 * @brief mutiplication by iterative addition
 * 
 * @param a Number for multiplication
 * @param b Number for multiplication
 * @return long long int multiplication (a*b)
 */
long long int mul(int a, int b)
{
	long long int m = 0;
	short f = 0;
	
	if(a == 0 || b == 0) return 0;
	if(a == 1) return b;
	if(b == 1) return a;

	if(a < 0 && b < 0){
		a *= -1;
		b *= -1;
	} else if(a < 0 && b > 0){
		a *= -1;
		f = 1;
	} else if (a > 0 && b < 0){
		b *= -1;
		f = 1;
	}

	for(; a > 0; a--) 
		m += b;
	
	return f ? m *-1 : m;
}

int main(int argc, char *argv[])
{	
	int a=0, b=0;
	if(argc == 1){
        printf("Enter two number to calculate multiplication Ex.-3,2:\n");
        scanf("%d,%d", &a, &b);
    } else {
        if(!isdigit(argv[1][0]) || !isdigit(argv[2][0])) {
            printf( Yellow "Enter unsigned integer number as first & second argument "
                    "\nto calculate multiplication. Example: %s" Bold_Yellow " 10 5\n", argv[0]);
            exit(1);
        }
        a = atoi(argv[1]);
		b = atoi(argv[2]);
    }

	// Minimize iterations  
	if(a < b)
		printf("%lld\n",mul(a,b));
	else
		printf("%lld\n",mul(b,a));
	
	return 0;
}