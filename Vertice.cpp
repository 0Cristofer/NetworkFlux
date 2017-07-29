/*Implementação da classe Vertice
  Autor: Cristofer Oswald
  Data: 23/05/2017 */

#include "include/Vertice.h"
#include <climits>

Vertice::Vertice(std::string& nome){
  nome_ = nome;
}

Vertice::~Vertice(){
}

void Vertice::setRetorno(bool retorno){
    retorno_ = retorno;
}

void Vertice::setDescobrimento(int descobrimento){
  descobrimento_ = descobrimento;
}

void Vertice::setTermino(int termino){
  termino_ = termino;
}

void Vertice::setDistancia(int distancia){
  distancia_ = distancia;
}

void Vertice::setLow(int low){
  low_ = low;
}

void Vertice::addVizinho(Vertice* vertice, int peso){
  vizinhos_[vertice] = std::make_pair(peso, 0);
}

void Vertice::setCor(Cor cor){
  cor_ = cor;
}

void Vertice::setPredecessor(Vertice* predecessor){
  predecessor_ = predecessor;
}

bool Vertice::isRetorno(){
    return retorno_;
}

int Vertice::getDescobrimento(){
  return descobrimento_;
}

int Vertice::getTermino(){
  return termino_;
}

int Vertice::getDistancia(){
  return distancia_;
}

int Vertice::getLow(){
  return low_;
}

std::string& Vertice::getNome(){
  return nome_;
}

std::unordered_map<Vertice*, std::pair<int, int>>& Vertice::getVizinhos(){
  return vizinhos_;
}

Cor Vertice::getCor(){
  return cor_;
}

Vertice* Vertice::getPredecessor(){
  return predecessor_;
}

void Vertice::printVizinhos(){
  int i = 0;
  std::cout << "Vizinhos de " << nome_ << ":" << std::endl;

  for(auto& v : vizinhos_){
    std::cout << "\t" << v.first->getNome() << std::endl;
    std::cout << "\t" << v.second.first << std::endl;
    i++;
  }
}

void Vertice::limparDados(){
  setDescobrimento(INT_MAX);
  setTermino(INT_MAX);
  setLow(INT_MAX);
  setCor(Cor::BRANCO);
  setPredecessor(NULL);
}
