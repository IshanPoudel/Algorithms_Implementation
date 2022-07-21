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
		// printf("Shifting %d to the right\n", *(c+i) );
	}

	

	//replace the value

	*(c+to_be_placed_at) = val_at_current_position;


}

int main()
{

	
	int c[] = {4 , 6 , 9 , 7 , 8 , 10 };

	int mid = 2;
	int size_of_array = 6;


	 
	int n1 = size_of_array/2;
	int n2 = size_of_array-n1;
	

	
	// create left and right array

	int a[n1];
	int b[n2];


    //create left half
	for (int i=0  ; i<n1 ; i++)
	{
		a[i] = c[i];
		printf("%d  \t" , a[i] );



	}
	printf("\n");



	//create right half

	for (int j=n1; j<size_of_array;j++)
	{
		b[j-n1] = c[j];
		printf("%d  \t" , b[j-n1] );
	}
	printf("\n");


	

	


	// //need to find a easier way to do it
	// L={ a , b , c}
	// R = {d , e , f}


	// repeatdely check one element with other , 
	// smaller one moves to new array , and the cursor moves to the next array

	// find the next one
	int counter=0;


	int i=0;
	int j=0;


	

	while(i<n1 && j<n2)
	{
		if (a[i]<b[j])
		{
			//move the value to the merged array
			//move the cursor one point to the right in the right array.
			c[counter]=a[i];
			i++;



		}
		else
		{
			//move the value to the right array
			//move the cursor to the right at the right side.
			c[counter]=b[j];
			j++;
		}

		counter++;

		

		//how to terminate
		// if i goes from 0 , 1 , 2 i.e all the values are gone from the right
		//if j gors from 0 ,1 ,2 i.e all the values are gone from the right

	}

	//move the remaining value
	while(i<n1)
	{
		// add to the array
		c[counter] = a[i];
		i++;
		counter++;
	}


	while(j<n2)
	{
		// add to the array
		c[counter] = b[j];
		j++;
		counter++;
	}

	printf("Array at this state\n");
		for (int i=0; i<size_of_array;i++)
		{
			printf("%d\n", c[i]);
		}
		printf("\n");



	//but at a point there will still be some 


	// the following implementation runs in n^2 time in the worst case no bueno

	// for (int i=0 ; i<n2;i++)
	// {
	// 	// for each value in b loop through a and see where it should eb placed.
	// 	int val_to_be_checked = c[mid-1+i];
	// 	place_holder = c[mid+i]; 
	// 	for (int j=n1; j>0;j--)
	// 	{
	// 		// iterate until you find where the value should be placed.
			
	// 		// find where the value should be placed.
	// 		if (val_to_be_checked<c[j])
	// 		{
	// 			//move place_holder once to the left
	// 			place_holder--;
	// 		}


	// 	}


	// 	//anytime the place_holder is in the same_place as the array , we break .
	// 	if (place_holder==i)
	// 	{
	// 		// break out of loop
	// 	}

	// 	//at this point , you get where the value should be placed.
	// 	printf("The value %d should be placed at position%d\n", val_to_be_checked , place_holder );
	// 	//swap until you get to the point where the value should be placed.
	// 	// swap the current position with the place_holder value

	// 	place(c , place_holder , i  , size_of_array);

		

	// 	//need to change mid accordingly


	// }

}