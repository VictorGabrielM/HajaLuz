#pragma once

#include "../Servico.hpp"

//TORNA O CLIENTE ADIMPLENTE E A UC ATIVA
class Religacao : public Servico{ 
  public:
    Religacao(Endereco endereco,Cliente* _cliente, std::string tipoUC);
    std::string FinalizaServico() override;
    Religacao();
  
};

