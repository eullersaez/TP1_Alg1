#ifndef GRAFO_H
#define GRAFO_H
#include <list>

class Grafo{
    private:
        int numero_vertices;
        std::list<int> *lista_adjacencia;
        bool repeticao;                     //variavel booleana para checagem posterior de ciclos alcancaveis dentro do grafo
        int* vetor_de_postos_alcancados;    //vetor para armazenar quais vertices do grafo ja foram alcancados em alguma execucao da dfs

    public:
        Grafo(int );                        //construtor, recebe o numero de vertices do grafo
        void adiciona_aresta(int, int );    //adiciona aresta entre o vertice A e B, colocando B na lista encadeada de A
        void imprime_postos_alcancados(int );   //metodo para impressao final do numero de postos, os numeros dos postos e a presenca ou nao de algum ciclo
        void dfs(int , int , int , int* );      //metodo que realiza o caminhamento dfs de forma recursiva
        
};

#endif