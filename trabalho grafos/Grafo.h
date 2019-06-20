#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include "Aresta.h"

class Grafo
{
public:
    Grafo();
    int getOrdem(){return ordem;};
    void setOrdem(int novaOrdem){ordem = novaOrdem;};
    int getGrau(){return grau;};
    void setGrau(int novoGrau){grau = novoGrau;};
    bool getDirecaoNos(){return direcaoNos;};
    void setDirecaoNos(bool novaDirecaoNos){direcaoNos = novaDirecaoNos;};
    bool getArestasPond(){return arestasPonderadas;};
    void setArestasPond(bool novaArestaPond){arestasPonderadas = novaArestaPond;};
    bool getEhOrientado(){return ehOrientado;};
    void setEhOrientado(bool ehOrienttado){ehOrientado = ehOrientado;};

    void leArquivo(char arquivo[50]);
    void insereVetor(int v1, Grafo* gr);
    void eh_orientado(char chave);
    bool verificaVetor(int v1, Grafo* gr);
    void criaListaNos(int tam);
    void insereNo(int id);
    void insereAresta(int id,int IDorigem, int IDdestin);
    No* buscaNoId(int id);
    void imprime();
    void caminhamentoLargura(int no);
    void dijkstra(int no1, int no2);
    void AGMKruskal();
private:
    int ordem;
    int grau;
    bool direcaoNos;
    bool arestasPonderadas;
    bool ehOrientado;
    No* ListaNos;
};

#endif // GRAFO_H_INCLUDED
