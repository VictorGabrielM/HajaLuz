#ifndef LEITURISTA_H
#define LEITURISTA_H

#include "Funcionario.hpp"

class Leiturista : public Funcionario{
  public:
    Leiturista(std::string _nome, std::string _cpf, double _chapa, int _status,std::string _telefone);
    Leiturista(){};
};  

#endif



