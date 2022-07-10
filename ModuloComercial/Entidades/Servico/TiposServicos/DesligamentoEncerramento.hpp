#pragma once

#include <string>
#include "../Servico.hpp"

//TORNA O CLIENTE E A UC INATIVOS
class DesligamentoEncerramento : public Servico{
  public:
  DesligamentoEncerramento(Endereco endereco,Cliente* cliente,std::string tipoUC);
  std::string FinalizaServico() override;
  DesligamentoEncerramento();
};

