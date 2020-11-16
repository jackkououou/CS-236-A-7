#pragma once

void Qshuffle(int array[], int size);								//Random number generator
void swap(int *a, int *b);											//Utility swap
void copy(int source_array[], int destination_array[], int size);	//Copy array	

int middle_partition(int array[], int first, int last);
void middle_quickSort(int array[], int size);
void middle_quickSort(int array[], int low, int high);


void median_quickSort(int array[], int size);
void median_quickSort(int array[], int fist, int last);
int median_partition(int array[], int first, int last);

void insertionSort(int arr[], int size);							//Insertion Sort utility

void middle_insertion_quickSort(int arr[], int size);
void middle_insertion_quickSort(int arr[], int first, int last);

void median_insertion_quickSort(int arr[], int size);
void median_insertion_quickSort(int arr[], int first, int last);

