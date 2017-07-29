/*Arquivo que contém a implementação de algoritmos em grafos
  Autor: Cristofer Oswald e Bruno Cesar
  Data: 23/05/2017 */

#include "include/algoritmos.h"
#include "include/Vertice.h"

#include <queue>
#include <iostream>
#include <algorithm>

int fluxoMaximo(std::unordered_map<std::string, Vertice*>& grafo, Vertice* fonte, Vertice* sumidouro){
    int fluxo_maximo = 0;
    int gargalo = 0;
    bool tem_caminho = true;

    std::unordered_map<std::string, Vertice*>* grafo_residual;

    while(tem_caminho){
        montaResidual(grafo, &grafo_residual);
        distancia((*grafo_residual)[fonte->getNome()], (*grafo_residual)[sumidouro->getNome()], *grafo_residual);

        gargalo = encontraGargalo(*grafo_residual, (*grafo_residual)[fonte->getNome()], tem_caminho);

        if(tem_caminho){
            fluxo_maximo = fluxo_maximo + gargalo;
            setFluxos(grafo);
        }
    }
    
    return fluxo_maximo;
}

void montaResidual(std::unordered_map<std::string, Vertice*>& grafo, std::unordered_map<std::string, Vertice*>** grafo_residual){
    if(*grafo_residual){
        for(auto& a : (**grafo_residual)){
            free(a.second);
        }
        free(*grafo_residual);
    }

    (*grafo_residual) = new std::unordered_map<std::string, Vertice*>();

    for(auto& a : grafo){
        Vertice* origem = a.second;

        for(auto& b : origem->getVizinhos()){
            Vertice* destino = b.first;
            std::pair<int, int> capacidade_fluxo = b.second;

            if((*grafo_residual)->find(origem->getNome()) == (*grafo_residual)->end()){
                (**grafo_residual)[origem->getNome()] = new Vertice(origem->getNome());
                origem = (**grafo_residual)[origem->getNome()];
            }
            if((*grafo_residual)->find(destino->getNome()) == (*grafo_residual)->end()){
                (**grafo_residual)[destino->getNome()] = new Vertice(destino->getNome());
                destino = (**grafo_residual)[destino->getNome()];
            }

            if(capacidade_fluxo.second > 0){
                destino->addVizinho(origem, capacidade_fluxo.second );
            }

            if(capacidade_fluxo.first == capacidade_fluxo.second){

            }
        }
    }
}

int distancia(Vertice* u, Vertice* v, std::unordered_map<std::string, Vertice*>& grafo){
  std::queue<Vertice*> fila;
  Vertice *atual;

  u->setCor(Cor::CINZA);
  //As outras inicializações já acontecem em reinicia;

  fila.push(u);
  while(!fila.empty()){
    atual = fila.front();
    fila.pop();
    for(auto& a : atual->getVizinhos()){
      Vertice* vizinho = a.first;
      if(vizinho->getCor() == Cor::BRANCO){
        vizinho->setCor(Cor::CINZA);
        vizinho->setDistancia(atual->getDistancia() + 1);
        vizinho->setPredecessor(atual);
        fila.push(vizinho);
      }
      atual->setCor(Cor::PRETO);
    }
  }

  return v->getDistancia();
}

int encontraGargalo(std::unordered_map<std::string, Vertice*>& grafo, Vertice* fonte, bool& tem_caminho){
    int gargalo = 0;

    return gargalo;
}

void setFluxos(std::unordered_map<std::string, Vertice*>& grafo){

}

void reiniciaVerices(std::unordered_map<std::string, Vertice*>& grafo){
  for(auto& vertice : grafo){
    vertice.second->limparDados();
  }
}
