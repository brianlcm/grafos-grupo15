#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"

class Aresta
{
public:
    Aresta(int id);
    int getId(){return id;}
    float getPeso(){return peso;};
    void setPeso(float novoPeso){peso = novoPeso;};
    Aresta* getProx(){return prox;};
    void setProx(Aresta* novoProx){prox = novoProx;};
    Aresta* getProx1(){return prox1;}
    void setProx1(Aresta* novoProx){prox1 = novoProx;}
    void setNoAdj(No* no){noAdj = no;}
    No* getNoAdj(){return noAdj;}
    void setNoOrigem(No* no){noOrigem = no;}
    No* getNoOrigem(){return noOrigem;}
    void imprime();
private:
    No* noAdj;
    No* noOrigem;
    int id;
    float peso;
    Aresta *prox;
    Aresta *prox1;
};

#endif // ARESTA_H_INCLUDED
