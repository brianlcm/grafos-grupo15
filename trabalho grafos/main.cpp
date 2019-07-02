#include <iostream>
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void cabecalhoTrabalho()
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

void leArquivo(char arquivo[50], Grafo* gr)
{
    int tam;
    FILE* file;
    file = fopen(arquivo, "r");

    if (file == NULL)
    {
        cout << " Falha ao ler o arquivo." << endl;
        exit(0);
    }

    gr->eh_orientado();

    if(!feof(file))
    {
        fscanf(file,"%d \n \n", &tam);
        gr->setOrdem(tam);
    }

    else exit(0);

    while(!feof(file))
    {
        int v1, v2;
        float peso;
        fscanf(file, "%d %d %f\n", &v1, &v2, &peso);
        if(!gr->buscaNoId(v1))
            gr->insereNo(v1);
        if(!gr->buscaNoId(v2))
            gr->insereNo(v2);
        if(gr->getEhOrientado() == false)
        {
            gr->insereAresta(peso, v1, v2);
            gr->insereAresta(peso, v2, v1);
        }else
        gr->insereAresta(peso, v1, v2);
    }
}

int main()
{
    cabecalhoTrabalho();
    Grafo* grafo = new Grafo();

    leArquivo("entrada.txt", grafo);

    grafo->imprime();
    /*vector<No*> teste;
    teste = grafo->guloso();

    for(unsigned int i=0;i<teste.size();i++)
    {

        cout << teste.at(i)->getId() << endl;
    }
    cout<< teste.size() << endl;
    cout<<"flag"<<endl;*/
    grafo->componentesForteConexas();
    return 0;
}
