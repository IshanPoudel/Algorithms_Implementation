#include <stdio.h>
#include <stdlib.h>


int factorial(int num)
{
	int value;
	if(num ==0 )
	{
		return 1;
	}

	value = num * factorial(num-1);
	return value;
}

int main()
{

	int num =2;

	int value = factorial(num);

	printf("The factorial of %d is %d\n" , num , value);
}