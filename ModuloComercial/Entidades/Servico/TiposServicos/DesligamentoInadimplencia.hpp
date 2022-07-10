#ifndef DES_INA_H
#define DES_INA_H

#include "../Servico.hpp"
//TORNA E A UC INATIVOS

class DesligamentoInadimplencia : public Servico{
  public:   
    DesligamentoInadimplencia(Endereco endereco,Cliente *_cliente,std::string tipoUC);
    std::string FinalizaServico() override;
    DesligamentoInadimplencia();
};

#endif