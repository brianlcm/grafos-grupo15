#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include "Aresta.h"
#include <stack>
#include <vector>

using namespace std;

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
    void setEhOrientado(bool novoehOrientado){ehOrientado = novoehOrientado;};

    void leArquivo(char arquivo[50]);
    void insereVetor(int v1, Grafo* gr);
    bool verificaVetor(int v1, Grafo* gr);
    void criaListaNos(int tam);

    void insereNo(int id);
    void insereAresta(int id,int IDorigem, int IDdestin);
    No* buscaNoId(int id);
    No* getListaNos(){return ListaNos;}
    Aresta* getListaArestas(){return ListaArestas;}
    void imprime();
    void eh_orientado();

    void caminhamentoLargura(int no);

    void caminhamentoProfundidade(int no); // realiza caminhamento em profundidade a partir de um determinado vertice,
                                           // imprimindo a ordem de vertices visitados
    vector<No*> ordenacaoTopologica(int no); // retorna um vetor ordenado topologicamente a partir de um determinado vértice

    void dijkstra(int no); // calcula caminho mínimo a partir de um determinado vértice considerando arestas ponderadas
    //void dijsktra2(int no); // dijkstra para grafo orientado ??????????
    void relaxaAresta(Aresta* adj, No* no); // atualiza o valor das distancias dos vértices abertos
    bool existeFalse(); // verifica a existencia de vértices marcados como false no grafo
    No* menorDist(); // fornece o vertice aberto com a menor distancia presente no grafo
    void informaCaminhoMin(int origem, int destino); // feito apos dijkstra, o caminho é impresso considerando arestas ponderadas

    vector<Aresta*> prim(int no); // calcula sub árvore mínima a partir de um determinado vértice
    int getPrimTotal(vector<Aresta*> subArvore); // imprime as arestas referentes a sub árvore e
                                                 // retorna o seu peso total obtido pelo algoritmo de prim
    bool buscaVerticeVector(vector<No*> vertices, No* no); // função de busca
    //warning: comparison between signed and unsigned integer expressions RESOLVER!!!!!!!!!!!!

    vector<Aresta*> kruskal();
    static bool ordenaAux(Aresta* a1, Aresta* a2);
    static bool ordenaAux2(No* n1, No* n2);

    void caminhamentoProfundidadeModificado(No* no, int idAtual, bool cond);
    void AuxCaminhamentoProfundidadeModificado(No* no, int idAtual, bool cond);
    void componentesForteConexas();

    vector<No*> guloso();
    vector<No*> gulosoRandomizado();
    vector<No*> gulosoReativo();

    bool confereCobertura(vector<No*> solucao);
    void removeCandidato(No* candidato, vector<No*> candidatos);

    int getTamanho2(){return tamanho2;}
    void setTamanho2(int novotam){tamanho2 = novotam;}

private:
    int ordem;
    int grau;
    bool direcaoNos;
    bool arestasPonderadas;
    bool ehOrientado;
    No* ListaNos;
    Aresta* ListaArestas;

    void caminhamentoProfundidadeAux(No* no); // funcao recursiva do caminhamento em profundidade
    void ordenacaoTopologicaAux(No* no, stack<No*> pilha); // funcao recursiva da ordenacao topologica
    Aresta* primAux(vector<No*> vertices); // função responsável por selecionar a aresta que será adicionada na sub-árvorer mínima
    int tamanho2; // Variavel auxiliar para a função de componentes fortemente conexas
};

#endif // GRAFO_H_INCLUDED
