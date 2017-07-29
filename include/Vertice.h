/*Definição de um vértice
  Autor: Cristofer Oswald e Bruno Cesar
  Data: 23/05/2017 */

#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

enum Cor{
  BRANCO, CINZA, PRETO
};

class Vertice{
public:
  Vertice(std::string& nome);
  ~Vertice();

  void setRetorno(bool retorno);
  void setDescobrimento(int descobrimento);
  void setTermino(int termino);
  void setDistancia(int distancia);
  void setLow(int low);

  void addVizinho(Vertice* vertice, int peso);
  void setCor(Cor cor);
  void setPredecessor(Vertice* vertice);

  bool isRetorno();
  int getDescobrimento();
  int getTermino();
  int getDistancia();
  int getLow();

  std::string& getNome();
  std::unordered_map<Vertice*, std::pair<int, int>>& getVizinhos();
  Cor getCor();
  Vertice* getPredecessor();

  void printVizinhos();
  void limparDados();
private:
  bool retorno_ = false;
  int descobrimento_ = 0;
  int termino_ = 0;
  int distancia_ = 0;
  int low_ = 0;

  std::string nome_;
  std::unordered_map<Vertice*, std::pair<int, int>> vizinhos_;
  Cor cor_ = Cor::BRANCO;
  Vertice* predecessor_ = NULL;
};

#endif //VERTICE_H
