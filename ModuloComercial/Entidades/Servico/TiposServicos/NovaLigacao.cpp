#include "../../Sistema/Sistema.hpp"
#include <string>
#include "NovaLigacao.hpp"

NovaLigacao::NovaLigacao(Endereco endereco,Cliente *_cliente,std::string tipoUC){
  this->endereco = endereco;
  this->cliente = _cliente;
  this->tipoUC = tipoUC;
  Sistema::CadastrarUC(this->cliente->GetCpfCnpj(this->cliente->PermUser),this->tipoUC,this->endereco);
}

std::string NovaLigacao::FinalizaServico(){
  Sistema::AtivarUC(this->cliente->GetCpfCnpj(this->cliente->PermUser),this->endereco);
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  return "Nova Ligacao de UC";
}