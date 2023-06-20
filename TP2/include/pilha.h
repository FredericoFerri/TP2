#pragma once

#include "ponto.h"

//PILHA ESTÁTICA
class Pilha{
    private:
        int tamanho;
        int maxSize;
        int topo;
        Ponto* stack;

    public:
        Pilha(int n);
        ~Pilha(){free(stack);}
        int getTamanho() { return tamanho; }
        bool Vazia() {return topo==-1;}

        void Empilha(Ponto p);
        void Desempilha();

        Ponto getTopo() {return stack[topo];}
        void setPilha();
        void printPilha();
        void printPilhaInversa();
};