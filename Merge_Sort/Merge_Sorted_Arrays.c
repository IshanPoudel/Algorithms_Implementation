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

	printf("The two subarrays are\n"  );
	for (int i=0; i<size_of_left_arr;i++)
	{
		printf("%d\n" , left_arr[i]);
	}
	printf("\n" );

	for (int i=0; i<size_of_right_arr;i++)
	{
		printf("%d\n" , right_arr[i]);
	}




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
			printf("Added %d from left \n" , left_arr[i]);
			i++;

		}
		else
		{
			arr[counter] = right_arr[j];
			printf("Added %d from right \n" , right_arr[j]);
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



}
int main()
{

	//Given a array with n elements , 

	// sort a select  elements by dividing it into two equal halves.

	// int arr[] = { 3 , 4 ,  5 , 6 ,12 , 25 , 8 ,13 , 89 , 90  ,99, 56 , 24};
	// int len =13;


	int arr[] = {2 , 1};



	// // a certain sect is sorted into two equal halves divide it
	// 5 ,6 , 12 , 25
	// 8 , 13 , 89 , 90
	
	// merge(arr , 2 , 5 , 9  );
	// merge(array , left , mid , right)

	//print the array

	merge(arr , 0 , 0 , 1);



	for (int i=0; i<2; i++)
	{
		printf("%d\t", arr[i] );
	}

}