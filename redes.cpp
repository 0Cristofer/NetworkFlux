/*Arquivo pincipal da leitura do grafo de Game of Thrones
  Autor: Cristofer Oswald e Bruno Cesar
  Data: 23/05/2017 */

#include "include/redes.h"

int main(int argc, char** argv){
  if(!verificaArgs(argc)){
    return 0;
  }

  int tempo = 0;
  int filhos = 0;
  std::string nome_arquivo(argv[1]);
  std::string vertice1, vertice2;
  Vertice* fonte;
  Vertice* sumidouro;

  std::cout << "Lendo grafo: " << nome_arquivo << std::endl ;
  leGrafo(nome_arquivo, fonte, sumidouro);

  //Printa o grafo
  for(std::pair<std::string, Vertice*> v : grafo){
    v.second->printVizinhos();
  }

  //Excutando algoritmo de caminho mínimo
  reiniciaVerices(grafo);

  std::cout << std::endl << "Fim" << std::endl;
  return 0;
}

bool verificaArgs(int argc){
  if(argc != 2){
    std::cout << "Argumentos inválidos, modo de execução:";
    std::cout << " got nome_do_grafo" << std::endl;
    return false;
  }
  return true;
}

//Lê um grafo dado o nome do arquivo
void leGrafo(std::string& nome_file, Vertice* fonte, Vertice* sumidouro){
  std::ifstream input_file;
  std::string linha, origem, destino, peso, s, t;

  input_file.open(nome_file);

  if(input_file.is_open()){
    getline(input_file, linha, FIM_DE_LINHA); //Ignora a primeira linha
    //Ignora os dois primeiros dados
    s = strtok(&linha[0], " ");
    s = strtok(NULL, " ");
    s = strtok(NULL, " ");
    t = strtok(NULL, " ");

    while(getline(input_file, linha, FIM_DE_LINHA)){
      origem = strtok(&linha[0], " ");
      destino = strtok(NULL, " ");
      peso = strtok(NULL, " ");

      //Verifica se o vertice de origem está no hash de vertices
      if(grafo.find(origem) == grafo.end()){
        grafo[origem] = new Vertice(origem);
      }

      //Verifica se o vertice de destino está no hash de vertices
      if(grafo.find(destino) == grafo.end()){
        grafo[destino] = new Vertice(destino);
      }

      //Adiciona o destino como vizinho da origem
      grafo[origem]->addVizinho(grafo[destino], stoi(peso));
    }

    fonte = grafo[s];
    sumidouro = grafo[t];
  }
  else{
    std::cout<< "Arquivo inválido" << std::endl;
  }
}