#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include "ponto.h"

double radius(Ponto p, Ponto p0) {
    if (p0.getX() == p.getX()) {
        return M_PI/2;
    }
    int dy = p.getY() - p0.getY();
    int dx = p.getX() - p0.getX();
	//ponto p está a esquerda de p0
	if(dx < 0){return (M_PI - atan(dy/abs(dx)));}
	return atan((double)dy/dx);
}

// A utility function to swap two points
void swap(Ponto &p1, Ponto &p2)
{
	Ponto temp(p1.getX(), p1.getY());
    p1.setX(p2.getX());
    p1.setY(p2.getY());
	p2.setX(temp.getX());
    p2.setY(temp.getY());
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Ponto p1, Ponto p2)
{
	return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
		(p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

void orderHelp(Ponto arr[], int n, const Ponto p0){

    for(int i = n - 1; i >= 0; i--) {
		if (i > 0 && (radius(arr[i], p0)) == (radius(arr[i - 1], p0))) {
            double distance1 = distSq(arr[i], p0);
            double distance2 = distSq(arr[i-1], p0);
            if (distance1 < distance2) {
				swap(arr[i-1], arr[i]);
				i++;
            }
        }
	}
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Ponto p1, Ponto p2, Ponto p3) {
    int val = (p2.getY() - p1.getY()) * (p3.getX() - p2.getX()) - (p2.getX() - p1.getX()) * (p3.getY() - p2.getY());
    if (val == 0) {
        return 0;  // Collinear
    }
    return (val > 0) ? 1 : 2;  // Clockwise or Counterclockwise
}

#endif