#include <iostream>
#include <math.h>   //para uso da funcao floor
#include <sstream>  //para uso da funcao istringstream
#include "headers/grafo.h"

int main(){
    int numero_centros, numero_postos, temperatura;
    
    std::string linha;                          //leitura e atribuicao inicial de valores.
    std::getline(std::cin,linha);
    std::istringstream leitura_inicial(linha);

    leitura_inicial>>numero_centros;
    leitura_inicial>>numero_postos;
    leitura_inicial>>temperatura;
    
    
    int numero_max_de_postos;  //declaracao do numero maximo de postos possiveis de serem percorridos levando em conta a temperatura das vacinas e checagem de divisao por 0.
    if(temperatura == 0){
        numero_max_de_postos = 1000000;
    }else{
        numero_max_de_postos = std::floor(30/temperatura);
    }
    
    Grafo rotas(numero_centros+numero_postos);                      //declaracao do grafo de rotas.

    for (int i = 0; i < numero_centros + numero_postos; i++){       //insercao dos centros de distribuicao + postos de vacinacao no grafo.
        std::getline(std::cin,linha);                               //as primeiras numero_centros-1 posicoes sao ocupadas por centros de distribuicao e a partir dai as demais
        std::istringstream leitura(linha);                          //sao ocupadas por postos de vacinacao. para que as arestas sejam adicionadas corretamente a cada vertice,
        int aux=-1;                                                 //soma-se numero_centros-1 ao valor entrado para cada posto.
        while (leitura>>aux && aux != 0){
            rotas.adiciona_aresta(i, aux + numero_centros - 1);
        }
    }


    int explorados[numero_centros+numero_postos];                   //inicializacao do vetor de vertices explorados.
    for (int i = 0; i < numero_centros; i++){                       //para cada centro i, verifica-se os postos que se pode alcancar a partir dele.
        for (int j = 0; j < numero_centros+numero_postos; j++){     //zera-se todo o vetor de explorados a cada execucao inicial do metodo dfs.
            explorados[j] = 0;              
        }
        rotas.dfs(i,0,numero_max_de_postos, explorados);            //executa-se a dfs para o centro i, com 0 de profundidade percorrida e passando o valor maximo de postos a serem percorridos
    }                                                               //e o vetor de vertices explorados inicialmente todo zerado.
    
    rotas.imprime_postos_alcancados(numero_centros);                //realiza-se a impressao da saida esperada.

    return 0;
}