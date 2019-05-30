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
    void cabecalhoTrabalho();
    void leArquivo(char arquivo[50]);
    void insereVetor(int no);
    bool verificaVetor(int no);
    void criaListaNos(int tam);
    void insereNo(int id);
    void insereAresta(int id,int IDorigem, int IDdestino);
    void insereArestaPonderada(int id,int IDorigem, int IDdestino, float peso);
    No* buscaNoId(int id);
    void imprime();

    void caminhamentoLargura(int no);
private:
    int ordem;
    int numArestas = 0;
    int grau;
    bool direcaoNos;
    bool arestasPonderadas;
    No* ListaNos;

};

#endif // GRAFO_H_INCLUDED
