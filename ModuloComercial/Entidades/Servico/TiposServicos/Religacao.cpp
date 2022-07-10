#include "../../Sistema/Sistema.hpp"
#include <string>
#include "Religacao.hpp"

Religacao::Religacao(Endereco endereco,Cliente* _cliente,std::string tipoUC){
  this->endereco = endereco;
  this->cliente = _cliente;
  this->tipoUC = tipoUC;
}

std::string Religacao::FinalizaServico(){
  Sistema::AtivarUC(this->cliente->GetCpfCnpj(this->cliente->PermUser),this->endereco);
  //TEMOS QUE ALTERAR O STATUS DA UC NESTE PONTO
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  return "Religacao de UC";
}