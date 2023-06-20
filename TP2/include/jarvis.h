#ifndef JARVIS_H
#define JARVIS_H

#include "ponto.h"
#include "functions.h"
#include "pilha.h"

// Prints convex hull of a set of n points.
void jarvisHull(Ponto points[], int n, bool toPrint)
{
	// There must be at least 3 points
	if (n < 3) return;

	// Initialize Result
	Pilha hull(n);

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].getX() < points[l].getX())
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again. This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q;
	do
	{
		// Add current point to result
		hull.Empilha(points[p]);

		// Search for a point 'q' such that orientation(p, q,
		// x) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		// If i is more counterclockwise than current q, then
		// update q
		if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l); // While we don't come to first point

    // Now stack has the output points, print contents of stack
    if(toPrint){
        std::cout << "FECHO CONVEXO:" << std::endl;
        hull.printPilhaInversa();
        std::cout << std::endl;
    }
    
    /*while (!hull.Vazia())
    {
        Ponto p = hull.getTopo();
        std::cout << "(" << p.getX() << ", " << p.getY() <<")" << std::endl;
        hull.Desempilha();
    }*/
}

#endif