#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "graham.h"
#include "jarvis.h"

#define arquivo "ENTRADA1000.txt"

int main(int argc, char *argv[]){
	
	std::ifstream file(argv[1]);

	//verificação de arquivo aberto
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        exit(1);
    }

	// Count the number of lines
    std::string line;
    int n = 0;
    while (std::getline(file, line)) {
        n++;
    }

    file.close();

    // Reopening file
    file.open(argv[1]);
    //verificação de arquivo aberto
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        exit(1);
    }

	//Array of points
	Ponto points[n];
	
	int x, y = 0;
	for(int i=0; i<n; i++){
		file >> x >> y;
		Ponto p(x,y);
		points[i] = p;
		//std::cout << "Ponto " << "(" << points[i].getX() << "," << points[i].getY() << ")" << std::endl;//radius(points[i], points[3]) << std::endl; 
	}

	int nSize = sizeof(points)/sizeof(points[0]);

	//PRINTING CONVEX HULL
	grahamHull(points, nSize, 2, 1);
	std::cout << "FECHO CONVEXO:" << std::endl;

	// Início da contagem de tempo
    auto inicio = std::chrono::high_resolution_clock::now();

	//MERGESORT
	grahamHull(points, nSize, 0, 0);

	// Fim da contagem de tempo
    auto fim = std::chrono::high_resolution_clock::now();

	// Cálculo do tempo de execução em segundos
    std::chrono::duration<double> duracao = fim - inicio;
    double tempoExecucao = duracao.count();

	// Exibição do resultado
    //std::cout << "GRAHAM+MERGESORT: " << tempoExecucao << "s" << std::endl;
	printf("GRAHAM+MERGESORT: %.3lfs \n", tempoExecucao);

	//-----------------------------------------------------------

	// Início da contagem de tempo
	inicio = std::chrono::high_resolution_clock::now();

	//INSERTION SORT
	grahamHull(points, nSize, 1, 0);

	// Fim da contagem de tempo
	fim = std::chrono::high_resolution_clock::now();

	// Cálculo do tempo de execução em segundos
    duracao = fim - inicio;
	tempoExecucao = duracao.count();

	// Exibição do resultado
    //std::cout << "GRAHAM+INSERTIONSORT: " << tempoExecucao << "s" << std::endl;
	printf("GRAHAM+INSERTIONSORT: %.3lfs \n", tempoExecucao);

	//-----------------------------------------------------------

	// Início da contagem de tempo
	inicio = std::chrono::high_resolution_clock::now();

	//RADIX SORT
	grahamHull(points, nSize, 2, 0);

	// Fim da contagem de tempo
	fim = std::chrono::high_resolution_clock::now();

	// Cálculo do tempo de execução em segundos
    duracao = fim - inicio;
    tempoExecucao = duracao.count();

	// Exibição do resultado
    //std::cout << "GRAHAM+RADIX: " << tempoExecucao << "s" << std::endl;
	printf("GRAHAM+RADIX: %.3lfs \n", tempoExecucao);

	//-----------------------------------------------------------

	// Início da contagem de tempo
	inicio = std::chrono::high_resolution_clock::now();

	jarvisHull(points, nSize, 0);

	// Fim da contagem de tempo
	fim = std::chrono::high_resolution_clock::now();

	// Cálculo do tempo de execução em segundos
    duracao = fim - inicio;
    tempoExecucao = duracao.count();

	// Exibição do resultado
    //std::cout << "JARVIS: " << tempoExecucao << "s" << std::endl;
	printf("JARVIS: %.3lfs \n", tempoExecucao);

	//-----------------------------------------------------------

	return 0;
}
