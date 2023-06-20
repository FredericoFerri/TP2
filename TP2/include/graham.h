#ifndef GRAHAM_H
#define GRAHAM_H

#include "ponto.h"
#include "pilha.h"
#include "functions.h"
#include "radixSort.h"
#include "mergeSort.h"
#include "insertionSort.h"
#include <cmath>

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Ponto p0;

// A utility function to find next to top in a stack
Ponto nextToTop(Pilha &S)
{
	Ponto p = S.getTopo();
	S.Desempilha();
	Ponto res = S.getTopo();
	S.Empilha(p);
	return res;
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Ponto *p1 = (Ponto *)vp1;
    Ponto *p2 = (Ponto *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void grahamHull(Ponto points[], int n, int op, bool toPrint)
{
    // Find the bottommost point
    int ymin = points[0].getY(), min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].getY();

        // Pick the bottom-most or choose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
            points[i].getX() < points[min].getX()))
            ymin = points[i].getY(), min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];

    if(op == 0){mergeSort(points, 1, n, points[0]);}
    else if(op == 1){insertionSort(&points[1], n-1, p0);} 
    else if(op == 2){radixSort(&points[1], n-1, p0);}
    else{std::cout << "ERRO! Método de ordenação não selecionado. Encerrando..." << std::endl; exit(1);}

    /*std::cout << "Pontos ordenados!" << std::endl;
    for(int it = 0; it < n; it++){
        std::cout << "(" << points[it].getX() << "," << points[it].getY() << "): " << radius(points[it], p0) << std::endl;
    }
    std::cout << std::endl;*/

    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n-1 && orientation(p0, points[i],
                                        points[i+1]) == 0)
            i++;


        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) return;

    // Create an empty stack and push first three points
    // to it.
    Pilha S(n);
    S.Empilha(points[0]);
    S.Empilha(points[1]);
    S.Empilha(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.getTamanho()>1 && orientation(nextToTop(S), S.getTopo(), points[i]) != 2)
            S.Desempilha();
        S.Empilha(points[i]);
    }

    // Now stack has the output points, print contents of stack
    if(toPrint){
        std::cout << "FECHO CONVEXO:" << std::endl;
        S.printPilhaInversa();
        std::cout << std::endl;
    }
    

    //Deleting stack 
    /*while (!S.Vazia())
    {
        Ponto p = S.getTopo();
        std::cout << "(" << p.getX() << ", " << p.getY() <<")" << std::endl;
        S.Desempilha();
    }*/
}

//qsort(&points[1], n-1, sizeof(Ponto), compare);
#endif