#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "No.h"
#include "Aresta.h"

using namespace std;

No::No(int id)
{
    this->id = id;
    this->prox = NULL;
    this->adj = NULL;
    d = -1;
    p = -1;
    this->idAux = 0;
    this->tamanho = 0;
}

void No::imprime()
{
    cout << this->id;
    Aresta* aresta = this->adj;
    while(aresta!=NULL)
    {
        aresta->imprime();
        aresta = aresta->getProx();
    }
    cout << endl;
}
