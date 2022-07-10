#pragma once

#include "../Servico.hpp"

//TORNA A UC ATIVA
class NovaLigacao : public Servico{
  public:
    NovaLigacao(Endereco endereco,Cliente *_cliente,std::string tipoUC);
    std::string FinalizaServico() override;
    NovaLigacao();
  
};
