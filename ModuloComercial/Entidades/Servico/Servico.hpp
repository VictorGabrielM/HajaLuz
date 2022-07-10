#ifndef SERVICO_H
#define SERVICO_H

#include "../Cliente/Cliente.hpp"
#include "../Data/Data/Data.hpp"
#include "../Localizacao/Endereco.hpp"

class Servico{
  protected:
    std::string tipoUC;
    Endereco endereco;
    Data dataConclusao;
    Cliente* cliente;
    bool completo = 0;

  public:
  virtual std::string FinalizaServico();
  bool getCompleto(){
    return this->completo;
  }
  Servico();
};

#endif
