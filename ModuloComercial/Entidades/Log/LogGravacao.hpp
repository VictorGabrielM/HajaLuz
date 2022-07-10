#pragma once

#include "Log.hpp"
#include <iostream>

class LogGravacao : public Log{

  private:

    std::string entidade_alterada;
    std::string atributo;
    std::string valor_original;
    std::string valor_alterado;

  public:

    std::string GetEntidade();
    std::string GetAtributo();
    std::string GetValorOriginal();
    std::string GetValorAlterado();
    LogGravacao( std::string, std::string, std::string, std::string, std::string, Data);
    void ExibirLog();
    LogGravacao();

};
