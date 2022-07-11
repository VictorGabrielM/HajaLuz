#pragma once

#include "Log.hpp"

class LogAcessoNegado : public Log{

  private:
    std::string entidade_acessada;
    std::string funcao_acessada;

  public:
    std::string GetEntidade();
    std::string GetFuncao();
    LogAcessoNegado( std::string, std::string, std::string, Data);
    void ExibirLog();
    LogAcessoNegado(){};

};

