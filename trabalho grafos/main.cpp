#include <iostream>
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"

using namespace std;



int main()
{
    Grafo* grafo = new Grafo();///Constroi um grafo
    grafo->cabecalhoTrabalho();///Chama o cabecalho com nome dos integrantes da equipe e professor
    grafo->leArquivo("entrada.txt"); ///Leitura do grafo

    grafo->imprime();
    grafo->caminhamentoLargura(12);

    return 0;
}
