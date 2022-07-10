#include "../../Sistema/Sistema.hpp"
#include <string>
#include "TrocaMedidor.hpp"

//no próximo mólulo seria interessante zerar a contagem da UC

TrocaMedidor::TrocaMedidor(Endereco endereco,Cliente *_cliente,std::string tipoUC){
  this->endereco = endereco;
  this->cliente = _cliente;
  this->tipoUC = tipoUC;
}

std::string TrocaMedidor::FinalizaServico(){
  this->completo = true;
  this->dataConclusao = this->dataConclusao.dateNow();
  return "Troca de Medidor";
}

