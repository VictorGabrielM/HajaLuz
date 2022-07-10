#include "../../Sistema/Sistema.hpp"
#include <string>
#include "DesligamentoInadimplencia.hpp"

DesligamentoInadimplencia::DesligamentoInadimplencia(Endereco endereco, Cliente *_cliente,std::string tipoUC){
  this->endereco = endereco;
  this->cliente = _cliente;
  this->tipoUC = tipoUC;
}

std::string DesligamentoInadimplencia::FinalizaServico(){
  Sistema::DesativarUC(this->cliente->GetCpfCnpj(this->cliente->PermUser),this->endereco);
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  return "Desligamento por Inadimplencia";
}