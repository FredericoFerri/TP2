#ifndef LINHA_H
#define LINHA_H

#include <iostream>

class Ponto{
    private:
        double x;
        double y;
        //Ponto* next;

    public:
        Ponto() : x(0) , y(0) {}
        Ponto(double xDef, double yDef) : x(xDef) , y(yDef) {}
        ~Ponto(){}

        double getX() {return x;}
        double getY() {return y;}
        //Ponto* getNext() {return next;}
        void setX(double value) {x = value;}
        void setY(double value) {y = value;}
        //void setNext(Ponto* prox) {next = prox;}
};

/*class Linha{
    private:
        Ponto* P;
        double angle;

    public:
        Linha(){}
        ~Linha(){}

        double getAngle() {return angle;}
};*/

#endif