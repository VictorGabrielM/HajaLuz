#pragma once

#include "../Servico.hpp"
//TORNA E A UC INATIVOS

class DesligamentoInadimplencia : public Servico{
  public:   
    DesligamentoInadimplencia(Endereco endereco,Cliente *_cliente,std::string tipoUC);
    std::string FinalizaServico() override;
    DesligamentoInadimplencia();
};
