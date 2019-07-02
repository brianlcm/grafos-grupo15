#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class Aresta;

class No
{
public:
    No(int id);
    int getId(){return id;}
    void setId(int novoId){id = novoId;}
    int getIdComp(){return idComp;}
    void setIdComp(int novoId){idComp = novoId;}
    int getPeso(){return peso;}
    void setPeso(float novoPeso){peso = novoPeso;}
    int getGrau(){return grau;}
    void setGrau(int novoGrau){grau = novoGrau;}
    int getGrauEntrada(){return grauEntrada;}
    void setGrauEntrada(int novoGrauEntrada){grauEntrada = novoGrauEntrada;}
    int getGrauSaida(){return grauSaida;}
    void setGrauSaida(int novoGrauSaida){grauSaida = novoGrauSaida;}
    void setProx(No* proxi){prox= proxi;}
    No* getProx(){return prox;}
    void setAdj(Aresta* aresta){adj=aresta;}
    Aresta* getAdj(){return adj;}
    bool getMarcado(){  return this->marcado;   };
    void setMarcado(bool marcado){  this->marcado = marcado;  };
    int getDistancia(){return d;}
    void setDistancia(int novaDistancia){d = novaDistancia;}
    int getPred(){return p;}
    void setPred(int novoPred){p = novoPred;}
    void imprime();
    int getIdAux(){return idAux;}
    void setIdAux(int novoId){idAux = novoId;}
    int getTamanho(){return tamanho;}
    void setTamanho(int novotam){tamanho = novotam;}


private:
    int id;
    int idComp;
    float peso;
    Aresta* adj;
    No* prox;
    int grau;
    int grauEntrada;
    int grauSaida;
    bool marcado;
    int d; // distancia          São utilizados em dijskra
    int p; // predecessor

    int idAux; // Variavel auxiliar para a função de componentes fortemente conexas
    int tamanho; // Variavel auxiliar para a função de componentes fortemente conexas
};


#endif // NO_H_INCLUDED
