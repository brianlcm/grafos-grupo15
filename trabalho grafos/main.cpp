#include <iostream>
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"

using namespace std;

//void cabecalhoTrabalho()
//{
//
//    cout << "#----------------------------------------------------------------------------#"<< endl;
//    cout << "-----------------  Trabalho de Grafos 2019-1  - Grupo 15 --------------------" << endl;
//    cout << "-----------------           Equipe de Alunos             --------------------" << endl;
//    cout << "-----------------       Brian Maia                - 201665512B---------------" << endl;
//    cout << "-----------------       Daniel Ferreira           - 201665519AB--------------" << endl;
//    cout << "-----------------       Luis Guilherme Cipriani   - 201776040 ---------------" << endl;
//    cout << "-----------------       Thallys da Silva Nogueira - 201365390B---------------" << endl;
//    cout << "-----------------     Professor orientador: Stênio Sã         ---------------" << endl;
//    cout << "#----------------------------------------------------------------------------#" << endl;
//    cout << endl;
//
//}
//
//void leArquivo(char arquivo[50], Grafo* gr)
//{
//    int tam;
//    //int contadorAux = 0;
//    char chave;
//    int eh_orientado = 0;
//    FILE* file;
//    file = fopen(arquivo, "r");
//
//    if (file == NULL)
//    {
//        cout << " Falha ao ler o arquivo." << endl;
//        exit(0);
//    }
//
//    cout << "O GRAFO É ORIENTADO? [S/N] = ";
//    cin >> chave;
//    while(chave!= 'S' && chave!= 'N' && chave!= 's' && chave != 'n')
//    {
//        cout << "DIGITE O TIPO DO GRAFO" << endl;
//        cout << "(S) PARA ORIENTADO" << endl;
//        cout << "(N) PARA NÃO ORIENTADO" << endl << " = ";
//        cin>> chave;
//    }
//
//    if(chave == 'S'||chave=='s')
//
//        eh_orientado = 1;
//    else
//        eh_orientado = 0;
//
//
//    if(!feof(file))
//        fscanf(file,"%d \n \n", &tam);
//        gr.setOrdem(tam);
//
//    else exit(0);
//    //int vis[tam];///para ser passado como parametro para a busca em largura em funcionalidades
//
//    while(!feof(file))
//    {
//        int v1, v2;
//        float peso;
//        fscanf(file, "%d %d %f\n", &v1, &v2, &peso);
//        ///insereAresta(gr,v1,v2,eh_orientado,peso);
//        ///insereVetor(v1, gr);
//        ///insereVetor(v2, gr);
//    }
//    ///verificaGrauTotal(gr);
//    ///funcionalidades(gr, vis, tam);
//}

int main()
{
//    cabecalhoTrabalho();
//    Grafo grafo();
//    leArquivo("entrada.txt", grafo); ///Leitura do grafo

    Grafo* grafo = new Grafo();
    for(int i=0;i<5;i++)
    {
        grafo->insereNo(i);
    }

    grafo->insereAresta(1, 1, 2);
    grafo->insereAresta(2, 1, 4);
    grafo->insereAresta(3, 3, 0);
    grafo->insereAresta(4, 0, 1);
    grafo->insereAresta(5, 0, 3);
    grafo->insereAresta(6, 3, 1);

    grafo->imprime();

    //Testando caminhamento em largura
    //grafo->caminhamentoLargura(1);

    return 0;
}
