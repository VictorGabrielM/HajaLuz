#include <iostream>
#include <vector>
#include "Funcionario.hpp"
#include "../Sistema/Sistema.hpp"

std::vector<Servico> Funcionario::VerServicos(Permissoes _permissoes){
  return this->servicos.at(Sistema::GetDataHoje());
}

std::string Funcionario::ComecarProximoServico(Permissoes _permissoes){
  int _servicoEncontrado = 0;
  for(int i = 0; i < 8; i++){
    if(servicos.at(Sistema::GetDataHoje())[i].getCompleto() == false){
      this->servicoAtual = i;
      _servicoEncontrado = 1;
      return "Sucesso!";
    }
  }
  if(_servicoEncontrado == 0){
    return "Não há mais serviços para fazer hoje";
  }
}

double Funcionario::GetChapa(){
  return this->chapa;
}

std::string Funcionario::ConcluirServico(Data data, Permissoes _permissoes){
  servicos.at(data)[servicoAtual].FinalizaServico();
  std::string servicoEncontrado = ComecarProximoServico(this->PermUser);
  return servicoEncontrado;
}

std::string Funcionario::InserirServico(Data _data, Servico _servico, Permissoes _permissoes){
  if(servicos.at(_data).size() < 8){    
    servicos.at(_data).push_back(_servico);
    return "Successo!";
  }else{
    return "Esse dia já está lotado de serviços.";
  }
}

bool Funcionario::EstaDisponivel(Permissoes _permissoes){
  return this->disponiblidade;
}