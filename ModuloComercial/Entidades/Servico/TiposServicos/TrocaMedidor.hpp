#ifndef TROCA_MEDIDOR_H
#define TROCA_MEDIDOR_H

#include "../Servico.hpp"

class TrocaMedidor : public Servico{
  private:
    std::string relatorioPericia;
  public:
    TrocaMedidor(Endereco endereco,Cliente *_cliente,std::string tipoUC);
    std::string FinalizaServico() override;
    TrocaMedidor(){};
  
};

#endif