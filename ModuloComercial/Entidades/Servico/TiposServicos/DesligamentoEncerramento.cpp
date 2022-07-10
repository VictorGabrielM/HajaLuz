#include "../../Sistema/Sistema.hpp"
#include <string>
#include "DesligamentoEncerramento.hpp"

DesligamentoEncerramento::DesligamentoEncerramento(Endereco endereco,Cliente* cliente,std::string tipoUC){
  this->endereco = endereco;
  this->cliente = cliente;
  this->tipoUC = tipoUC;
}

std::string DesligamentoEncerramento::FinalizaServico(){
  Sistema::DesativarUC(this->cliente->GetCpfCnpj(this->cliente->PermUser),this->endereco);
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  return "Desligamento por Encerramento";
}