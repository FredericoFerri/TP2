#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "ponto.h"
#include "functions.h"

// Function to sort an array using
// insertion sort
void insertionSort(Ponto arr[], int n, const Ponto p0)
{
	int i, j;
    double key;
	for (i = 1; i < n; i++) {
		key = radius(arr[i],p0);
        Ponto pointKey(arr[i].getX(),arr[i].getY()); 
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key,
		// to one position ahead of their
		// current position
		while (j >= 0 && radius(arr[j],p0) > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = pointKey;
        orderHelp(arr, n, p0);
	}
}

#endif
