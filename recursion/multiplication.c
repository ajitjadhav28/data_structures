#include "../mydef.h"

long mul(int a, int b)
{
	if(a==1) return b;
	return b+mul(a-1, b);
}

int main()
{
	printf("%ld\n",mul(6,3));
	return 0;
}