#pragma once

#include "Funcionario.hpp"

class Eletricista : public Funcionario{
  public:
    Eletricista(std::string _nome, std::string _cpf, std::string _chapa, int _status,std::string _telefone);
    Eletricista();
};


