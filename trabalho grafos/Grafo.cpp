#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include <queue>

using namespace std;

Grafo::Grafo()
{
    ListaNos = NULL;
}
/*
void Grafo::insereVetor(int no)
{
    if(verificaVetor(no)==false)
    {
        setOrdem(getOrdem()+1);
        ListaNos[getOrdem()-1] = no;
    }
}

bool Grafo::verificaVetor (No *lista,int no)
{
    for(int i=0; i<getOrdem(); i++)
    {
        if(ListaNos[i]==no)
            return true;
    }
    return false;
}*/


void Grafo::cabecalhoTrabalho()
{

    cout << "#----------------------------------------------------------------------------#"<< endl;
    cout << "-----------------  Trabalho de Grafos 2019-1  - Grupo 15 --------------------" << endl;
    cout << "-----------------           Equipe de Alunos             --------------------" << endl;
    cout << "-----------------       Brian Maia                - 201665512B---------------" << endl;
    cout << "-----------------       Daniel Ferreira           - 201665519AB--------------" << endl;
    cout << "-----------------       Luis Guilherme Cipriani   - 201776040 ---------------" << endl;
    cout << "-----------------       Thallys da Silva Nogueira - 201365390B---------------" << endl;
    cout << "-----------------     Professor orientador: Stênio Sã         ---------------" << endl;
    cout << "#----------------------------------------------------------------------------#" << endl;
    cout << endl;
}

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

void Grafo::insereArestaPonderada(int id,int IDorigem, int IDdestino, float peso)
{
    No *origem, *destino;

    origem = this->buscaNoId(IDorigem);
    destino = this->buscaNoId(IDdestino);

    Aresta *adj = origem->getAdj();

    Aresta *aresta = new Aresta(id);
    origem->setAdj(aresta);
    aresta->setNoAdj(destino);
    aresta->setPeso(peso);

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
    if(getArestasPond() == true)
    {
        while(no!=NULL)
        {
            no->imprimePonderado();
            no = no->getProx();
        }
    }
    else
    {
        while(no!=NULL)
        {
            no->imprime();
            no = no->getProx();
        }
    }
}


void Grafo::leArquivo(char arquivo[50])
{
    string dado1,dado2,dado3,dado4;
    ifstream infile;
    int i = 0;
    char chave1,chave2;
    infile.open(arquivo);

    if (arquivo == NULL)
    {
        cout << " Falha ao ler o arquivo." << endl;
        exit(0);
    }

    cout << "O GRAFO É ORIENTADO? [S/N] = ";
    cin >> chave1;
    while(chave1!= 'S' && chave1!= 'N' && chave1!= 's' && chave1!= 'n')
    {
        cout << "DIGITE O TIPO DO GRAFO" << endl;
        cout << "(S) PARA ORIENTADO" << endl;
        cout << "(N) PARA NÃO ORIENTADO" << endl << " = ";
        cin>> chave1;
    }
    if(chave1 == 'S'||chave1 =='s')
        this->direcaoNos = 1;
    else
        this->direcaoNos = 0;

    cout << "O GRAFO É PONDERADO NAS ARESTAS? [S/N] = ";
    cin >> chave2;
    while(chave2!= 'S' && chave2!= 'N' && chave2!= 's' && chave2!= 'n')
    {
        cout << "DIGITE O TIPO DO GRAFO" << endl;
        cout << "(S) PARA ORIENTADO" << endl;
        cout << "(N) PARA NÃO ORIENTADO" << endl << " = ";
        cin>> chave2;
    }
    if(chave2 == 'S'||chave2 =='s')
        this->arestasPonderadas = 1;
    else
        this->arestasPonderadas = 0;


    if (infile.is_open() && infile.good())
    {
        infile >> dado1;
        int i_dado1 = atoi(dado1.c_str());
        cout << "Quantidade de Nós do grafo é: ";
        setOrdem(i_dado1);
        cout<< getOrdem();
        if(this->arestasPonderadas == true )
        {
            while(!infile.fail())
            {
                infile >> dado2 >> dado3 >> dado4;
                int i_dado2 = atoi(dado2.c_str());
                int i_dado3 = atoi(dado3.c_str());
                float f_dado4 = atof(dado4.c_str());
                insereNo(i_dado2);
                insereNo(i_dado3);
                insereArestaPonderada(i,i_dado2,i_dado3,f_dado4);
                i = i + 1;
            }
        }
        else
        {
            while(!infile.fail())
            {
                infile >> dado2 >> dado3 >> dado4;
                int i_dado2 = atoi(dado2.c_str());
                int i_dado3 = atoi(dado3.c_str());
                insereNo(i_dado2);
                insereNo(i_dado3);
                insereAresta(i,i_dado2,i_dado3);
                i = i + 1;
            }
        }
        infile.close();
    }

}

void Grafo::caminhamentoLargura(int no)
{
    No* i = buscaNoId(no);
    int contador=0;
    queue<No*> fila;
    for(; i!=NULL; i = i->getProx()) // Inicializa todos os nós como não marcados
    {
        i->setMarcado(false);
    }

    i = buscaNoId(no);
    ///print
    cout << i->getId() << " inserido." << endl;
//    while(i!=NULL)
//    {
//        if(!i->getMarcado())
//        {
            contador++;
            i->setMarcado(true);
            fila.push(i);
            while(!fila.empty())
            {
                for(Aresta* aresta = fila.front()->getAdj(); aresta != NULL; aresta = aresta->getProx())
                {
                    if(!aresta->getNoAdj()->getMarcado())
                    {
                        fila.push(aresta->getNoAdj());
                        ///print
                        cout << aresta->getNoAdj()->getId() << " inserido." << endl;
                        contador++;
                        aresta->getNoAdj()->setMarcado(true);
                    }
                }
                fila.pop();
            }
            cout << "contador: " << contador;
//        }
//        cout << i->getId() << endl;
//        i = i->getProx();
//    }
}
