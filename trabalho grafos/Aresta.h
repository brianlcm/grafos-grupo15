#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"

class Aresta
{
public:
    Aresta(int id);
    float getPeso(){return peso;};
    void setPeso(float novoPeso){peso = novoPeso;};
    Aresta* getProx(){return prox;};
    void setProx(Aresta* novoProx){prox = novoProx;};
    void setNoAdj(No* no){noAdj = no;}
    No* getNoAdj(){return noAdj;}
    void imprime();
private:
    No* noAdj;
    int id;
    float peso;
    Aresta *prox;
};

#endif // ARESTA_H_INCLUDED
