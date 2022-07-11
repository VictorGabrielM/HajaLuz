#ifndef MEDICAO_H
#define MEDICAO_H

#include "../Servico.hpp"

class Medicao : public Servico{
  public:
    Medicao(Endereco endereco,Cliente *_cliente,std::string tipoUC);
    std::string RegistraConsumo(Endereco endereco,Cliente &_cliente, float _novaMedicao);
    std::string FinalizaServico() override;
    Medicao(){};
  
};

#endif