#include <stdio.h>
#include <stdlib.h>



void insertion_sort(int arr[] , int size)
{

	//add each element to a list and compare it to all the elements already on the list and swap places.
	// the way the swapping works :
	// ifind the smallest number that is biggest in the sorting list.

	// you can sort in place.

	int index=0;


	for (int i=0; i<size-1;i++)
	{
		int value_to_be_checked = arr[i+1];
		int index = i;


		printf("I am checking %d with %d\n", value_to_be_checked , arr[index]);

		while (value_to_be_checked < arr[index] & index>=0)

		{

			// see whenre the val_to_be_checked_should be placed. 
			arr[index+1] = arr[index];
			//move the value one step forward/
			index--;


			
		}

		// at this point , place the value in the index
		
		arr[index+1] = value_to_be_checked;

		//if value is bigger than the previous value , then

		//index gives where to place the value_to_be_checked

		//everything to the right of the index should be shifted once to the right.
		//
	}


				


			

		
}


int main()
{
	int arr[] = { 5  , 1 , 67 , 343 , 24 , 67 , 9 , 235 , 3563 , 64 , 3534 ,56};

	int size = 12;


	insertion_sort(arr , size);

	for (int i=0; i<size;i++)
	{
		printf("%d\t", arr[i] );
	}
}

// { add 5 to the sorted list }
// {add 1 to the left of 5}
// check 5 with 