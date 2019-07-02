#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include <queue>
#include <stack>
#include <limits>
#include <vector>
#include <limits.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

Grafo::Grafo()
{
     ListaNos = NULL;
     this->tamanho2 = 0;
}

void Grafo::insereNo(int id)
{
    No* no = new No(id);
    no->setProx(this->ListaNos);
    this->ListaNos = no;
    this->setOrdem(getOrdem()+1);
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
    aresta->setNoOrigem(origem);

    aresta->setProx(adj);

    aresta->setProx1(this->ListaArestas);
    this->ListaArestas = aresta;
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

    while(i != NULL)  // Inicializa todos os nós como não marcados para fazer a comparação depois
    {
        i->setMarcado(false);
        i = i->getProx();
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

void Grafo::caminhamentoProfundidade(int no)
{
    No* i = buscaNoId(no);

    while(i != NULL)  // Inicializa todos os nós como não marcados para fazer a comparação depois
    {
        i->setMarcado(false);
        i = i->getProx();
    }

    i = buscaNoId(no);

    while(i != NULL)
    {
        if(!i->getMarcado())
        {
            caminhamentoProfundidadeAux(i);
        }
        i = i->getProx();
    }
}

void Grafo::caminhamentoProfundidadeAux(No* no)
{
    int g = no->getGrauSaida();
    no->setMarcado(true);
    cout<<"Leu vertice "<<no->getId()<<endl;

    if(g!=0)
    {
        Aresta* point;
        for(point = no->getAdj(); point != NULL; point = point->getProx())
        {
            if(!point->getNoAdj()->getMarcado())
            {
                caminhamentoProfundidadeAux(point->getNoAdj());
            }
        }
    }
}


vector<No*> Grafo::ordenacaoTopologica(int no)
{
    No* i = buscaNoId(no);

    while(i != NULL)  // Inicializa todos os nós como não marcados para fazer a comparação depois
    {
        i->setMarcado(false);
        i = i->getProx();
    }
    i = buscaNoId(no);// ??????????

    stack<No*> pilha;

    while(i != NULL)
    {
        if(!i->getMarcado())
        {
            ordenacaoTopologicaAux(i,pilha);
        }
        i = i->getProx();
    }

    vector<No*> ordenacao;

    while(!pilha.empty())
    {
        ordenacao.push_back(pilha.top());
        pilha.pop();
    }

    return ordenacao;
}


void Grafo::ordenacaoTopologicaAux(No* no, stack<No*> pilha)
{
    int g = no->getGrauSaida();
    no->setMarcado(true);

    if(g!=0)
    {
        Aresta* point;
        for(point = no->getAdj(); point != NULL; point = point->getProx())
        {
            if(!point->getNoAdj()->getMarcado())
            {
                ordenacaoTopologicaAux(point->getNoAdj(), pilha);
            }
        }
    }
    pilha.push(no);
}


void Grafo::dijkstra(int no)
{
    No* i = buscaNoId(no);
    No* a = i;
    Aresta* adjacente;

    while(a != NULL) // Inicializa todos os nós como abertos para fazer a comparação depois
    {
        a->setMarcado(false);
        a->setDistancia(INT_MAX/2);
        a->setPred(-1);
        a = a->getProx();
    }
    i->setDistancia(0);

    //marcado = true se no esta fechado
    //marcado = false se no esta aberto
    while(existeFalse())
    {
        a = menorDist();
        a->setMarcado(true);
        adjacente = a->getAdj();
        while(adjacente!=NULL)
        {
            if(!adjacente->getNoAdj()->getMarcado()) // && destinoDeAdjacente != a(orientado)
            {
                relaxaAresta(adjacente, a);
            }
            adjacente = adjacente->getProx();
        }
    }
}


void Grafo::relaxaAresta(Aresta* adjacente, No* no)
{
    int novaDist;

    novaDist = no->getDistancia() + adjacente->getPeso();
    if(novaDist < adjacente->getNoAdj()->getDistancia())
    {
        no->setDistancia(novaDist);
        no->setPred(no->getId());
    }
}


bool Grafo::existeFalse()
{
    No* no = getListaNos();

    while(no != NULL)
    {
        if(!no->getMarcado())
        {
            return true;
        }
        no = no->getProx();
    }

    return false;
}


No* Grafo::menorDist()
{
    No* no = getListaNos();
    int menorDist = INT_MAX/2;

    /*
    while(no != NULL)// loop realizado para obter o primeiro valor de menorDist
    {
        if(!no->getMarcado())
        {
            menorDist = no->getDistancia();
            break;
        }
        no = no->getProx();
    }
    */
    int novaDist;
    No* noAlvo;
    while(no != NULL)// loop realizado para obter de fato a nova menor distancia entre os nos abertos
    {
        if(!no->getMarcado())
        {
            novaDist = no->getDistancia();
            if(novaDist<menorDist)
            {
                menorDist = novaDist;
                noAlvo = no;
            }
        }
        no = no->getProx();
    }

    return noAlvo;
}

void Grafo::informaCaminhoMin(int origem, int destino)
{
    No* i = buscaNoId(destino);
    int distTotal = 0;
    cout<<"Caminho Mínimo de "<<origem<<" ate "<<destino<<endl;

    while(i != buscaNoId(origem))
    {
        cout<<"< "<<i->getId()<<" >"<<endl;
        distTotal += i->getDistancia();
        i = buscaNoId(i->getPred());
    }
    cout<<"< "<<i->getId()<<" >"<<endl;
    distTotal += i->getDistancia();
    cout<<endl<<"Valor Total do Caminho : "<<distTotal<<endl;
}


vector<Aresta*> Grafo::prim(int no)
{
    No* i = buscaNoId(no);

    vector<No*> acessados; // vertices ja acessados
    vector<Aresta*> subArvore; // conjunto de vértices pertencentes a solução
    Aresta* menor; // ponteiro para a aresta que será adicionada a solução

    acessados.push_back(i); // adiciona o vértice referencial aos acessados
    while(acessados.size()!=getOrdem()) // loop ira parar quando todos vértices do grafo forem acessados
    {
        menor = primAux(acessados);
        acessados.push_back(menor->getNoAdj()); // adiciona o vértice adjacente de menor aos acessados
        subArvore.push_back(menor); // adiciona menor a solução
    }

    acessados.clear(); // limpa o vetor de acessados

    return subArvore; // retorna sub-árvore mínima
}


Aresta* Grafo::primAux(vector<No*> vertices)
{
    int menorValor = INT_MAX/2; // valor iniciado para comparação do menor peso
    Aresta* alvo; // aresta retornada para solução
    Aresta* aux;

    for(int i = 0; i<vertices.size(); i++) // percorre todos os vértices acessados
    {
        aux = vertices.at(i)->getAdj();
        while(aux!=NULL) // percorre todas arestas adjacentes ao vértice em questão
        {
            if(!buscaVerticeVector(vertices, aux->getNoAdj())) // confere se o vértice da aresta adjacente em questão
            {                                                  // ja foi acessado, o que evita cliclos
                if(aux->getPeso() < menorValor) // atualiza o conteúdo de menorValor e alvo
                {
                    menorValor = aux->getPeso();
                    alvo = aux;
                }
            }
            aux = aux->getProx();
        }
    }

    return alvo;
}


bool Grafo::buscaVerticeVector(vector<No*> vertices, No* no)
{
    for(unsigned int i = 0; i<vertices.size(); i++)
    {
        if(vertices.at(i) == no)
        {
            return true;
        }
    }
    return false;
}


int Grafo::getPrimTotal(vector<Aresta*> subArvore)
{
    int pesoTotal = 0;

    cout<<"Sub-Árvore Mínima"<<endl;
    for(unsigned int i = 0; i<subArvore.size(); i++)
    {
        cout<<"< "<<subArvore.at(i)->getId()<<" >"<<endl;
        pesoTotal += subArvore.at(i)->getPeso();
    }
    cout<<endl<<"Custo Total : "<<pesoTotal<<endl;

    return pesoTotal;
}


vector<Aresta*> Grafo::kruskal()
{
    std::vector<Aresta*> lista; // lista onde serao adicionadas todas arestas do grafo
    std::vector<Aresta*> solucao; // solucao a ser retornada
    No* noAux = getListaNos(); // usado para atualizar idComp de todos os nos do grafo
    Aresta* arestaAux = getListaArestas();


    while(noAux != NULL) // define idComp diferente para cada vértice
    {
        //cout<<"flag3"<<endl;
        noAux->setIdComp(noAux->getId());
        noAux = noAux->getProx();
    }

    while(arestaAux !=NULL) // adiciona todas as arestas em um vector
    {
        //cout<<"flag4"<<endl;
        lista.push_back(arestaAux);
        arestaAux = arestaAux->getProx1();
    }

    sort(lista.begin(), lista.end(), ordenaAux);
    int valorO, valorD;

    for(unsigned int i = 0; i<lista.size(); i++)
    {
        //cout<<"flag"<<endl;
        valorO = lista.at(i)->getNoOrigem()->getIdComp();
        valorD = lista.at(i)->getNoAdj()->getIdComp();
        if(valorO != valorD)
        {
            solucao.push_back(lista.at(i));
            noAux = getListaNos();
            while(noAux!=NULL)
            {
                //cout<<"flag2"<<endl;
                if(noAux->getIdComp()==valorO)
                {
                    noAux->setIdComp(valorD);
                }
                noAux = noAux->getProx();
            }
        }
        /*
        if(solucao.size()==(getOrdem()-1))
        {
            break;
        }
        */
    }

    return solucao;
}


bool Grafo::ordenaAux(Aresta* a1, Aresta* a2)
{
    return a1->getPeso() < a2->getPeso();
}

void Grafo::eh_orientado()
{
    char chave;
    cout << "Informe o Tipo do Grafo:" << endl;
    cout << "(S) Para ORIENTADO ou ";
    cout << "(N) Para NAO ORIENTADO" << endl;
    inicio:
    cin >> chave;
    switch(chave)
    {
        case 's':
        case 'S':
            cout << "-----GRAFO ORIENTADO-----" << endl << endl;
            ehOrientado = true;
        break;
        case 'n':
        case 'N':
            cout << "-----GRAFO NAO ORIENTADO-----" << endl << endl;
            ehOrientado = false;
            break;
        default:
            cout << "Escolha <S> ou <N>" << endl;
            goto inicio;
    }
}

void Grafo::caminhamentoProfundidadeModificado(No* no, int idAtual, bool cond)
{
    No* aux = no;
    while(no != NULL)  // Inicializa todos os nós como não marcados para fazer a comparação depois
    {
        no->setMarcado(false);
        no = no->getProx();
    }

     no = aux;

    while(aux != NULL)
    {
        if(aux->getMarcado()==false || cond==false || (cond==false && aux->getMarcado()==true))
        {
            AuxCaminhamentoProfundidadeModificado(aux, idAtual, cond);
        }
        aux = aux->getProx();
        setTamanho2(getTamanho2()+1);
    }
}

void Grafo::AuxCaminhamentoProfundidadeModificado(No* no, int idAtual, bool cond)
{
    int g = no->getGrauSaida();
    if(cond)
    {
        no->setMarcado(true);
        no->setIdAux(idAtual);
    }
    setTamanho2(getTamanho2()+1);
    if(g!=0)
    {
        Aresta* point;
        for(point = no->getAdj(); point != NULL; point = point->getProx())
        {
            if(point->getNoAdj()->getMarcado()==false || cond==false || (cond==false && point->getNoAdj()->getMarcado()==true))
            {
                AuxCaminhamentoProfundidadeModificado(point->getNoAdj(), idAtual, cond);
            }
        }
    }
}

void Grafo::componentesForteConexas()
{
    //Componentes conexas
    No* no  = getListaNos();
    No* aux = no;
    int idAtual = 1;
    while(no!=NULL)
    {
        if(no->getIdAux()==0)
        {
            caminhamentoProfundidadeModificado(no, idAtual, true);
            idAtual++;
            no->setTamanho(getTamanho2());
            setTamanho2(0);
        }
        no = no->getProx();
    }
    cout << "Quantidade de componentes conexas: " << idAtual-1 << endl;

    //Componentes fortemente conexas
    no  = getListaNos();
    while(no!=NULL)
    {
        caminhamentoProfundidadeModificado(no, 0, false);
        no->setTamanho(getTamanho2());
        setTamanho2(0);
        no = no->getProx();
    }

    no  = getListaNos();

    while(no!=NULL)
    {
        cout << no->getId() << " CC: " << no->getIdAux() << " CFC: " << no->getTamanho() << endl;
        no = no->getProx();
    }
}

vector<No*> Grafo::guloso()
{
    std::vector<No*> solucao;
    std::vector<No*> candidatos;
    Grafo* copia = new Grafo();
    copia = this;


    candidatos.reserve(this->getOrdem());

    No* aux = this->ListaNos;
    while(aux != NULL)
    {
        candidatos.push_back(aux);
        aux = aux->getProx();
    }

    sort(candidatos.begin(), candidatos.end(), ordenaAux2);
    No* escolhido = candidatos.at(0);
    solucao.push_back(escolhido);
    copia->removeCandidato(escolhido, candidatos);
    sort(candidatos.begin(), candidatos.end(), ordenaAux2);
    //solucao.size() == this->getOrdem() || !confereCobertura(solucao)
    while(solucao.size() == this->getOrdem() || !confereCobertura(solucao))
    {
        cout<<"flag1"<<endl;
        escolhido = candidatos.at(0);
        if(escolhido->getGrau() != 0)
        {
            solucao.push_back(escolhido);
            copia->removeCandidato(escolhido, candidatos);
            sort(candidatos.begin(), candidatos.end(), ordenaAux2);
        }
    }

    delete copia;
    copia = NULL;

    return solucao;
}


vector<No*> Grafo::gulosoRandomizado()
{
    std::vector<No*> solucao;
    std::vector<No*> escolhidos;
    std::vector<No*> candidatos;
    Grafo* copia = new Grafo();
    float p, alpha;

    No* escolhido;

    srand(time(NULL));
    alpha = rand()%100;

    copia = this;

    candidatos.reserve(this->getOrdem());

    No* aux = this->ListaNos;
    while(aux != NULL)
    {
        candidatos.push_back(aux);
        aux = aux->getProx();
    }

    sort(candidatos.begin(), candidatos.end(), ordenaAux2);

    while(solucao.size() == this->getOrdem() || !confereCobertura(solucao))
    {
        p = (int)(alpha*candidatos.size());

        for(int i = 0; i<p; i++)
        {
            escolhidos.push_back(candidatos.at(i));
        }
        //V[Rand()%v.size()]
        srand(time(NULL));
        escolhido = escolhidos.at(rand()%escolhidos.size());

        if(escolhido->getGrau() != 0)
        {
            solucao.push_back(escolhido);
            copia->removeCandidato(escolhido, candidatos);
            sort(candidatos.begin(), candidatos.end(), ordenaAux2);
        }

        escolhidos.clear();
    }

}


vector<No*> Grafo::gulosoReativo()
{

}


void Grafo::removeCandidato(No* candidato, vector<No*> candidatos)
{
    Aresta* adj = candidato->getAdj();

    while(adj != NULL)
    {
        adj->getNoAdj()->setGrau(adj->getNoAdj()->getGrau()-1);
        adj = adj->getProx();
    }
    candidatos.erase(candidatos.begin());
}


bool Grafo::confereCobertura(vector<No*> solucao)
{
    Aresta* aux = this->ListaArestas;
    cout<<"entrou"<<endl;
    int flag = 0;
    while(aux != NULL) // percorre todas as arestas do grafo
    {
        cout<<"loop"<<endl;
        for(unsigned int i = 0; solucao.size(); i++) // percorre toda possivel solução
        {
            if(aux->getNoAdj()==solucao.at(i) || aux->getNoOrigem()==solucao.at(i))
            {
                flag = 1;
            }
        }
        if(flag = 0)
                return false;
        aux = aux->getProx1();
        flag = 0;
    }
    return true;
}


bool Grafo::ordenaAux2(No* n1, No* n2)
{
    return (n1->getGrau()) < (n2->getGrau());
}

