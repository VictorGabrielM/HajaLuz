#pragma once

#include "Funcionario.hpp"

class Leiturista : public Funcionario{
  public:
    Leiturista(std::string _nome, std::string _cpf, std::string _chapa, int _status,std::string _telefone);
    Leiturista();
};  



