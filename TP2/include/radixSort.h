#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "ponto.h"
#include "functions.h"

// A utility function to get maximum value in arr[]
Ponto getMax(Ponto arr[], int n, Ponto p0)
{
	Ponto mx = arr[0];
	for (int i = 1; i < n; i++)
		if (radius(arr[i],p0) > radius(mx,p0))
			mx = arr[i];
	return mx;
}

void countSort(Ponto arr[], int n, double exp, Ponto p0)
{

	Ponto output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++){
		count[(int)(radius(arr[i],p0) / exp) % 10]++;
	}

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	// Build the output array
	for(i = n - 1; i >= 0; i--) {
		int index = count[(int)(radius(arr[i], p0) / exp) % 10] - 1;
		output[index] = arr[i];
		count[(int)(radius(arr[i],p0) / exp) % 10]--;

		// If two points have the same angle, sort based on the smaller Euclidean distance
        /*if (i > 0 && (radius(arr[i], p0)) == (radius(arr[i - 1], p0))) {
            double distance1 = distSq(arr[i], p0);
            double distance2 = distSq(arr[i-1], p0);
            if (distance1 < distance2) {
				swap(arr[i-1], arr[i]);
				i++;
            }
        }*/

		//Fase ponto: 0.785
		//Modulo ponto: raiz de 3
		//temp = 0.7851,73
		
		//Fase ponto: 0.785
		//Módulo ponto: 2
		//temp = 0.7852

		//Fase ponto: 0.7851
	}

	orderHelp(output, n, p0);

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(Ponto arr[], int n, Ponto p0)
{
	// Find the maximum number to know number of digits
	Ponto m = getMax(arr, n, p0);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	//radius(m, p0) / exp > 0.001
	for (double exp = 0.0001; exp <= 1; exp *= 10)
		countSort(arr, n, exp, p0);
}

#endif

/*double polarAngle(Ponto p, Ponto p0) {
    if (p0.getY() == p.getY()) {
        return -M_PI;
    }
    int dy = p0.getY() - p.getY();
    int dx = p0.getX() - p.getX();
    return std::atan2(dy, dx);
}*/

/*// Apply secondary sorting based on Euclidean distance
    for (i = 0; i < 10; i++) {
        int start = count[i];
        int end = (i == 9) ? (n - 1) : (count[i + 1] - 1);
        if (start < end) {
            // Sort the subarray with the same angle based on Euclidean distance
            for (int j = start; j <= end; j++) {
                for (int k = j + 1; k <= end; k++) {
                    if (distSq(p0, output[k]) < distSq(p0, output[j])) {
                        std::swap(output[j], output[k]);
                    }
                }
            }
        }
    }*/