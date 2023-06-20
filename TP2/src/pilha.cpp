#include "pilha.h"

Pilha::Pilha(int n){
    stack = (Ponto*) malloc(n*sizeof(Ponto));
    tamanho = 0;
    maxSize = n;
    topo = -1;
}

void Pilha::Empilha(Ponto p){
    if(topo == maxSize-1){
        std::cout << "Pilha cheia! Operacao abortada" << std::endl;
        exit(1);
        return;
    }
    else{
        topo++;
        tamanho++;
        stack[topo] = p;
    }
}

void Pilha::Desempilha(){
    if(topo == -1){
        std::cout << "Pilha vazia! Operacao abortada" << std::endl;
        exit(1);
        return;
    }
    else{
        topo--;
        tamanho--;
    }
}

void Pilha::setPilha(){}

void Pilha::printPilha(){
    int auxTopo = topo;

    while(auxTopo != -1){
        std::cout << "Ponto " << auxTopo << ": (" << stack[auxTopo].getX() << "," << stack[auxTopo].getY() << ")" << std::endl;
        auxTopo--;
    }
}

void Pilha::printPilhaInversa(){
    for(int i = 0; i < tamanho; i++){
        std::cout << stack[i].getX() << " " << stack[i].getY() << std::endl;
    }
}