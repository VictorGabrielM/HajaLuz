#include "LogGravacao.hpp"
#include <iostream>

LogGravacao::LogGravacao(std::string _entidade_alterada, std::string _atributo, std::string _valor_original, std::string _valor_alterado, std::string _usuario, Data _data){

  this->entidade_alterada=_entidade_alterada;
  this->atributo=_atributo;
  this->valor_original=_valor_original;
  this->valor_alterado=_valor_alterado;
  this->usuario=_usuario;
  this->data=_data;
  
}


std::string LogGravacao::GetEntidade(){
  return this->entidade_alterada;
}


std::string LogGravacao::GetAtributo(){
  return this->atributo;
}


std::string LogGravacao::GetValorOriginal(){
  return this->valor_original;
}


std::string LogGravacao::GetValorAlterado(){
  return this->valor_alterado;
}

void LogGravacao::ExibirLog(){
  std::cout<< "Usuário " << this->GetUsuario() << " teve acesso a entidade "<< this->GetEntidade()<< " no horário ";
  this->GetData().getData();
  std::cout << " e alterou o atributo " << this->GetAtributo() << " de " << this->GetValorOriginal() << " para " << this->GetValorAlterado() << std::endl;
}