#include <stdio.h>
#include <stdlib.h>


void merge(int arr[] , int left , int mid , int right )
{
	//create two sub arrays

	int size_of_left_arr = mid-left+1;
	int size_of_right_arr = right-mid;

	int left_arr[size_of_left_arr];
	int right_arr[size_of_right_arr];


	for (int i=left; i<=mid ; i++)
	{
		left_arr[i-left] = arr[i];
		

	}

	for(int i = mid+1; i<=right ; i++)
	{
		right_arr[i-mid-1] =arr[i];
		
	}

	// printf("The two subarrays in this function call are\n"  );
	// for (int i=0; i<size_of_left_arr;i++)
	// {
	// 	printf("%d\t" , left_arr[i]);
	// }
	// printf("\n" );

	// for (int i=0; i<size_of_right_arr;i++)
	// {
	// 	printf("%d\t" , right_arr[i]);
	// }




	//write the sort path 

	 // a, b ,c , 
	 // d , e , f  compare a with d and write it on the arr[]
	 // if a less than d , compare b iwth d now

	int i=0;
	int j=0;

	// counter to write to the main array
	int counter = left;

	while(i<size_of_left_arr && j<size_of_right_arr)
	{
		
		if (left_arr[i] < right_arr[j])
		{
			arr[counter]=left_arr[i];
			// printf("Added %d from left \n" , left_arr[i]);
			i++;

		}
		else
		{
			arr[counter] = right_arr[j];
			// printf("Added %d from right \n" , right_arr[j]);
			j++;
		}

		counter++;
	}

	//write the remaining values. 

	while(i<size_of_left_arr)
	{
		arr[counter] = left_arr[i];
		counter++;
		i++;
	}

	while(j<size_of_right_arr)
	{
		arr[counter] = right_arr[j];
		counter++;
		j++;
	}


	printf("\nAfter merging the current state is \n");
	for (int i=0; i<=right;i++)
	{
		printf("%d\t", arr[i] );
	}
	printf("\n" );


	printf("\n\n");

}

void merge_sort(int arr[] , int left , int right)
{

	int mid = left + (right-left)/2;
	//check for base case 
	if (left ==right)
	{
		//if left is equal to right , you can go sn
		return;
	}


    //divide [art]
	merge_sort(arr , left , mid);
	merge_sort(arr , mid+1 , right);

	//combine the two sub-arrays
	// give the starting position of the first sub array , 
	// the ending position(mid) and the place where the next array ends

	merge(arr , left , mid , right);

	printf("Popped from stack\n\n");


}

int main()
{

	//Given an array

	int arr[] = { 3 , 4  , 55 , 23 , 9 , 34 , 16 , 78 , 80 , 99 };
	int size = 11;

	merge_sort(arr , 0 , size);


	for (int i=0; i<size;i++)
	{
		printf("%d\n",arr[i] );
	}
}