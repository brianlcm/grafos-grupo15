#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include <queue>

using namespace std;

Grafo::Grafo()
{
     ListaNos = NULL;
}

//void Grafo::insereVetor(int v1, Grafo* gr)
//{
//    if(verificaVetor(vertice,gr)==false)
//    {
//        gr->setOrdem(gr->getOrdem()+1);
//        gr->ListaNos[gr->tamanho-1]=v1;
//    }
//}

//bool Grafo::verificaVetor (int v1, Grafo *gr)
//{
//    for(int i=0; i<gr->getOrdem(); i++)
//    {
//        if(gr->vet[i]==v1)
//            return true;
//    }
//    return false;
//}

void Grafo::insereNo(int id)
{
//    No* no = new No(id);
//    if(this->ListaNos == NULL)
//    {
//        this->ListaNos = no;
//    }
//    else
//    {
//        this->ListaNos->setProx(no);
//    }
    // Decidir qual a melhor implementação. Ou fazer um loop (não indicado) ou usar uma variavel que já aponta.
    No* no = new No(id);
    no->setProx(this->ListaNos);
    this->ListaNos = no;
}

void Grafo::insereAresta(int id,int IDorigem, int IDdestino)
{
    No *origem, *destino;

    origem = this->buscaNoId(IDorigem);
    destino = this->buscaNoId(IDdestino);

    Aresta *adj = origem->getAdj();

    Aresta *aresta = new Aresta(id);
    origem->setAdj(aresta);
    aresta->setNoAdj(destino);


    aresta->setProx(adj);
}

No* Grafo::buscaNoId(int id)
{
    No* no = this->ListaNos;
    while(no!=NULL)
    {
        if(no->getId()==id)
        {
            return no;
        }
        no = no->getProx();
    }
    return NULL;
}

void Grafo::imprime()
{
    No* no = this->ListaNos;
    while(no!=NULL)
    {
        no->imprime();
        no = no->getProx();
    }
}

void Grafo::caminhamentoLargura(int no)
{
    No* i = buscaNoId(no);
    int contador=0; // contador que é atualizada a cada inserção na fila
    queue<No*> fila;
    for(; i!=NULL; i = i->getProx()) // Inicializa todos os nós como não marcados para fazer a comparação depois
    {
        i->setMarcado(false);
    }
    i = buscaNoId(no); // atualiza variável i para valor de "no", pois o for anterior modificou esse valor
    cout << i->getId() << " inserido." << endl; /// print para verificar algoritmo (excluir?)
    contador++;
    i->setMarcado(true);
    fila.push(i); // insere na fila
    while(!fila.empty())
    {
        for(Aresta* aresta = fila.front()->getAdj(); aresta != NULL; aresta = aresta->getProx())
        {
            if(!aresta->getNoAdj()->getMarcado())
            {
                fila.push(aresta->getNoAdj());
                cout << aresta->getNoAdj()->getId() << " inserido." << endl; /// print para verificar algoritmo (excluir?)
                contador++;
                aresta->getNoAdj()->setMarcado(true);
            }
        }
        fila.pop(); // Excluir primeiro elemento da fila
    }
    cout << "Contador: " << contador;
}

void Grafo::eh_orientado(char chave)
{
    Grafo* grafo = new Grafo();
    cout << "O GRAFO EH ORIENTADO? [S/N] = ";
    cin >> chave;
    while(chave!= 'S' && chave!= 'N' && chave!= 's' && chave != 'n')
    {
        cout << "DIGITE O TIPO DO GRAFO" << endl;
        cout << "(S) PARA ORIENTADO" << endl;
        cout << "(N) PARA NAO ORIENTADO" << endl << " = ";
        cin>> chave;
    }

    if(chave == 'S'||chave=='s')

        grafo->setEhOrientado(true);
    else
        grafo->setEhOrientado(false);
}
