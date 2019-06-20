#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Aresta.h"

using namespace std;

Aresta::Aresta(int id)
{
    this->id = id;
    this->prox = NULL;
}

void Aresta::imprime()
{
    cout << " --|" << this->id << "|-->" << this->noAdj->getId() << " ";
}
