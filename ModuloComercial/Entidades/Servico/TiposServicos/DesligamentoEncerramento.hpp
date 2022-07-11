#ifndef DES_ENC_H
#define DES_ENC_H

#include <string>
#include "../Servico.hpp"

//TORNA O CLIENTE E A UC INATIVOS
class DesligamentoEncerramento : public Servico{
  public:
  DesligamentoEncerramento(Endereco endereco,Cliente* cliente,std::string tipoUC);
  std::string FinalizaServico() override;
  DesligamentoEncerramento(){};
};

#endif