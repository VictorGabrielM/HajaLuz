#include "../../Sistema/Sistema.hpp"
#include "../../Sistema/Sistema.hpp"
#include "../../Cliente/Cliente.hpp"
#include <string>
#include "Medicao.hpp"

//no próximo módulo seria interessante zerar a contagem da UC

Medicao::Medicao(Endereco _endereco, Cliente *_cliente,std::string _tipoUC){
  this->endereco = _endereco;
  this->cliente = _cliente;
  this->tipoUC = _tipoUC;
}

std::string Medicao::RegistraConsumo(Endereco _endereco,Cliente &_cliente, float _valorRegistro){
  _cliente.SetUltimaMedicao(_endereco, _valorRegistro, this->cliente->PermUser);
  _cliente.SetGastoMesAtual(_endereco, _valorRegistro, this->cliente->PermUser);
  _cliente.AdicionarFatura(_endereco, this->cliente->PermUser);
}

std::string Medicao::FinalizaServico(){
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  this->cliente->IncrementaQtdFaturasNPagas(this->cliente->PermUser);
  /*if(cliente->GetQtdFaturasNPagas(this->cliente->PermUser) >= 4 ){
    //Sistema::DesligamentoInadimplencia(this->endereco,this->cliente->GetCpfCnpj(this->cliente->PermUser));
  }
  */
  return "Medição no local";
}
