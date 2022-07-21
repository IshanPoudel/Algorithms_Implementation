#include <stdio.h>
#include <stdlib.h>





void place(int *c , int to_be_placed_at , int current_position , int size_of_array) 
{
	int val_at_current_position = *(c+current_position);
	int val_taking_up_spot = *(c+to_be_placed_at);

	//remove val_at_current_position_from the array
	for (int i=current_position; i<size_of_array-1; i++)
	{
		*(c+i) = *(c+i+1);
	}

	

	
	for (int i= size_of_array-1;i>to_be_placed_at;i--)
	{
		//shift everything to the right.
		*(c+i) = *(c+i-1);
		printf("Shifting %d to the right\n", *(c+i) );
	}

	

	//replace the value

	*(c+to_be_placed_at) = val_at_current_position;


}

int main()
{
	int c[] = {4 , 6 , 9 , 7 , 8 , 10 };

	int size_of_array = 6;

	//swap 5 with 9
	place(c  , 2 , 3 , size_of_array);

	for (int i=0; i<size_of_array;i++)
	{
		printf("%d\n", c[i] );
	}
	
}