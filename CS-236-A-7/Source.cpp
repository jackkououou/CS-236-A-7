#include <iostream>
#include <random>
#include <ctime>
#include <time.h>
#include "QSort.h"

using namespace std;

int main()
{

	int arrSize, *Qarray = 0;
	char choice = 'N' ;
	clock_t start, end;
	int cpu_time_middle_qSort, cpu_time_median_qSort, cpu_time_middle_insert_qSort, cpu_time_median_insert_qSort;
	
	
	do	
	{
		cpu_time_middle_qSort = 0;
		cpu_time_median_qSort = 0;
		cpu_time_middle_insert_qSort = 0;
		cpu_time_median_insert_qSort = 0;

		cout << "Enter array size to be sorted: ";
		cin >> arrSize;
		Qarray = new int[arrSize];			//Creating user defined array
		Qshuffle(Qarray, arrSize);			//Filling with random numbers

		int *copyArr;						//Copying array so that it can be reused by other algorithims
		copyArr = new int[arrSize];

		copy(Qarray, copyArr, arrSize);
		start = clock();
		middle_quickSort(copyArr, arrSize);
		end = clock();
		cpu_time_middle_qSort = end - start;
		

		copy(Qarray, copyArr, arrSize);
		start = clock();
		median_quickSort(copyArr, arrSize);
		end = clock();
		cpu_time_median_qSort = end - start;


		copy(Qarray, copyArr, arrSize);
		start = clock();
		middle_insertion_quickSort(copyArr, arrSize);
		end = clock();
		cpu_time_middle_insert_qSort = end - start;


		copy(Qarray, copyArr, arrSize);
		start = clock();
		median_insertion_quickSort(copyArr, arrSize);
		end = clock();
		cpu_time_median_insert_qSort = end - start;

		delete Qarray;
		delete copyArr;


		cout << "Quick sort time, with pivot middle element = " << cpu_time_middle_qSort << endl;
		cout << "Quick sort time, with pivot median element = " << cpu_time_median_qSort << endl;
		cout << "Quick sort time and insertion sort time, with pivot middle element = " << cpu_time_middle_insert_qSort << endl;
		cout << "Quick sort time and insertion sort time, with pivot median element = " << cpu_time_median_insert_qSort << endl;
		cout << "Would you like to enter another array size (Y / N)? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');


	system("PAUSE");
	return 0;
}