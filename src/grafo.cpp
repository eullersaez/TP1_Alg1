#include "headers/grafo.h"
#include <iostream>
#include <list>

Grafo::Grafo(int _numero_vertices){                             //construtor, recebe o numero de vertices e aloca o espaco devido para lista de adjacencia.
    this->numero_vertices = _numero_vertices;
    lista_adjacencia = new std::list<int>[numero_vertices];
    this->repeticao = false;                                    //inicialmente assume-se que nao ha ciclos alcancaveis por um centro de vacinacao dentro do grafo.
    vetor_de_postos_alcancados = new int[_numero_vertices];     
    for (int i = 0; i < _numero_vertices; i++){                 //vetor dos postos que serao alcancados no grafo inicializado totalmente zerado, pois ainda nao se executou nenhuma
        vetor_de_postos_alcancados[i] = 0;                      //instancia da dfs.
    }
}


void Grafo::adiciona_aresta(int a, int b){      //adiciona-se uma aresta do vertice A para B ao colocar B no final da lista encadeada da posicao A da lista de adjacencia.
    lista_adjacencia[a].push_back(b);
}


void Grafo::imprime_postos_alcancados(int numero_de_centros){
    int numero_alcancado = 0;
    for (int i = numero_de_centros; i < numero_vertices; i++){  //primeira parte realiza contagem do numero de postos alcancados no vetor de postos alcancados a partir da posicao
        if(vetor_de_postos_alcancados[i]>=1){                   //numero_de_centros pois no intervalo de 0 a numero_de_centros-1 teremos apenas os centros de distribuicao, que nao nos
            numero_alcancado++;                                 //interessa para saber quantos postos foram alcancados.
        }
    }
    if (numero_alcancado == 0){                                 //condicao para quando nenhum posto eh alcancado.
        std::cout<<"0"<<std::endl;
        std::cout<<"*"<<std::endl;
    }else{
        std::cout<<numero_alcancado<<std::endl;                     //impressao do numero de postos alcancados quando este eh > 0.
        for (int i = numero_de_centros; i < numero_vertices; i++){  //impressao dos numeros dos postos alcancados. como os postos se encontram a partir da posicao numero_de_centros, precisamos
            if(vetor_de_postos_alcancados[i]>=1){                   //subtrair esse valor do numero da posicao do posto no grafo verdadeiramente e somar 1 pois os postos comecam do 1 e nao do
                std::cout<<i-numero_de_centros+1<<" ";              //zero, como na lista de adjacencia.
            }
        }
        std::cout<<std::endl;
    }
    
    if (repeticao == true){                                 //impressao de 0 ou 1 da variavel repeticao, que sera modificada apenas quando durante uma execucao da dfs seja alcancado um 
        std::cout<<"1"<<std::endl;                          //ciclo.
    }else{
        std::cout<<"0"<<std::endl;
    }
}

void Grafo::dfs(int vertice, int profundidade_percorrida, int profundidade_maxima, int* explorados){

    if(profundidade_percorrida>profundidade_maxima){ //condicao de parada. checa se eh possivel continuar para os proximos vertices, retorna se chegar ao limite. 
        return;

    }else if (explorados[vertice] == -1){            //condicao de parada. se o valor do vertice no vetor de explorados eh -1 isso significa que todos os caminhos a partir desse vertice 
        return;                                      //ja foram explorados, portanto deve-se retornar.

    }else if(explorados[vertice] == 1){              //checa no vetor de explorados se o vertice atual ja foi explorado em algum momento anterior e por isso esta sendo repetido no caminho,
        repeticao = true;                            //ou seja, ha um ciclo no grafo na parte caminhada. muda-se o atributo repeticao para verdadeiro.

    }
    
    explorados[vertice] = 1;                         //marca o vertice atual como explorado no vetor de explorados.
    
    vetor_de_postos_alcancados[vertice] = 1;         //marca o vertice atual como alcancado no vetor atributo vetor_de_postos_alcancados.

    std::list<int>::iterator u;
    for (u = lista_adjacencia[vertice].begin(); u != lista_adjacencia[vertice].end(); u++){    //para todos os demais vertices incidentes a vertice, recursivamente executa-se o mesmo processo,
        dfs(*u, profundidade_percorrida+1,profundidade_maxima, explorados);                    //incrementando sempre a profundidade percorrida a cada execucao.
    }
    
    explorados[vertice] = -1;   //marca-se o vertice como -1 pois todos os caminhos a partir dele ja foram percorridos nas pilhas de execucao de cada iteracao do for.

}