#pragma once

#include "Log.hpp"
#include <iostream>

class LogLeitura : public Log{

  private:

    std::string entidade_acessada;
    std::string atributo;

  public:

    std::string GetEntidade();
    std::string GetAtributo();
    LogLeitura( std::string, std::string, std::string, Data);
    void ExibirLog();
    LogLeitura();
  
};
