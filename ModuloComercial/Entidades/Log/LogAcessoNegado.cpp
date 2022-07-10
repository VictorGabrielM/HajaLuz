#include "LogAcessoNegado.hpp"
#include <iostream>

LogAcessoNegado::LogAcessoNegado(std::string _entidade_acessada,std::string _funcao_acessada, std::string _usuario, Data _data){

  this->entidade_acessada=_entidade_acessada;
  this->funcao_acessada=_entidade_acessada;
  this->usuario=_usuario;
  this->data=_data;
  
}


std::string LogAcessoNegado::GetEntidade(){
  return this->entidade_acessada;
}


std::string LogAcessoNegado::GetFuncao(){
  return this->funcao_acessada;
}

void LogAcessoNegado::ExibirLog(){
  std::cout<< "Usuário " << this->GetUsuario() << " teve acesso negado a entidade "<< this->GetEntidade()<< ", na funcao "<< this->GetFuncao() << " no horário ";
  this->GetData().getData(); 
  std::cout << std::endl;
}