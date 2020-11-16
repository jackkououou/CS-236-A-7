#include "QSort.h"
#include <random>



void Qshuffle(int arr[], int size)
{
	std::random_device ranDev;

	for (int i = 0; i < size; i++)
		arr[i] = ranDev();
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void copy(int source_array[], int destination_array[], int size)
{
	for (int i = 0; i < size; i++)
		destination_array[i] = source_array[i];
}


void middle_quickSort(int arr[], int size)
{
	middle_quickSort(arr, 0, size - 1);

}
void middle_quickSort(int arr[], int low, int high)
{
	if (high > low)
	{
		int pivotIndex = middle_partition(arr, low, high);
		middle_quickSort(arr, low, pivotIndex - 1);
		middle_quickSort(arr, pivotIndex + 1, high);
	}
	
}
int middle_partition(int arr[], int first, int last)
{
	int pivot = arr[(last + first) / 2];
	int pivot_address = (last + first) / 2;		//Saving middle index
	int low = first;
	int high = last;
	while (high > low)
	{
		while (low <= high && arr[low] <= pivot)
			low++;

		while (low <= high && arr[high] > pivot)
			high--;

		if (high > low)
			swap(&arr[low], &arr[high]);
	}

	while (high > first && arr[high] >= pivot)
		high--;
	
	if (pivot > arr[high])
	{
		swap(&arr[high], &arr[pivot_address]);
		return high;
	}
	else
		return pivot_address;
}

void median_quickSort(int arr[], int size)
{
	median_quickSort(arr, 0, size - 1);
}

void median_quickSort(int arr[], int first, int last)
{
	if (last > first)
	{
		int pivotIndex = median_partition(arr, first, last);
		median_quickSort(arr, first, pivotIndex - 1);
		median_quickSort(arr, pivotIndex + 1, last);
	}
}

int median_partition(int array[], int first, int last)
{
	int f = array[first];
	int m = array[(first + last) / 2];
	int l = array[last];
	if ((f >= m && m >= l ) || (f <= m && m <= l))//middle median
	{
		return middle_partition(array, first, last);

	}
	else if ((m >= f && f >= l) || (m <= f && f <= l))//first median
	{
		int pivot = array[first];
		int low = first + 1;
		int high = last;
		
		while (high > low)
		{
			while (low <= high && array[low] <= pivot)
				low++;
			while (low <= high && array[high] > pivot)
				high--;
			
			if (high > low)
				swap(&array[high], &array[low]);
		}

		while (high > first && array[high] >= pivot)
			high--;

		if (pivot > array[high])
		{
			array[first] = array[high];
			array[high] = pivot;
			return high;
		}
		else
			return first;
	} 
	else	// last median
	{
		int pivot = array[last];
		int low = first;
		int high = last - 1;

		while (high > low)
		{
			while (low <= high && array[low] <= pivot)
				low++;
			while (low <= high && array[high] > pivot)
				high--;

			if (high > low)
				swap(&array[high], &array[low]);
		}

		while (high > first && array[high] >= pivot)
			high--;

		if (pivot > array[high])
		{
			array[last] = array[high];
			array[high] = pivot;
			return high;
		}
		else
			return last;
	}
}

void insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int currElement = arr[i];
		int k;

		for (k = i - 1; k >= 0 && arr[k] > currElement; k--)
			arr[k + 1] = arr[k];

		arr[k + 1] = currElement;
	}
}

void middle_insertion_quickSort(int arr[], int size)
{
	middle_insertion_quickSort(arr, 0, size - 1);
}

void middle_insertion_quickSort(int arr[], int first, int last)
{
	if (last - first >= 20 && last > first)				//Checking if bellow 20 ; send to insertion if < 20
	{
		int pivotIndex = middle_partition(arr, first, last);
		middle_quickSort(arr, first, pivotIndex - 1);
		middle_quickSort(arr, pivotIndex + 1, last);
	}
	else
		insertionSort(arr, first - last);
}

void median_insertion_quickSort(int arr[], int size)
{
	median_insertion_quickSort(arr, 0, size - 1);
}

void median_insertion_quickSort(int arr[], int first, int last)
{
	if (last - first >= 20 && last > first)			//Checking if bellow 20 ; send to insertion if < 20
	{
		int pivotIndex = median_partition(arr, first, last);
		median_quickSort(arr, first, pivotIndex - 1);
		median_quickSort(arr, pivotIndex + 1, last);
	}
	else
		insertionSort(arr, first - last);
}