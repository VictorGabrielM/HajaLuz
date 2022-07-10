#ifndef ELETRICISTA_H
#define ELETRICISTA_H

#include "Funcionario.hpp"

class Eletricista : public Funcionario{
  public:
    Eletricista(std::string _nome, std::string _cpf, double _chapa, int _status,std::string _telefone);
    Eletricista();
};

#endif
