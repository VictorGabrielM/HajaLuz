#include "PermissaoNegada.hpp"

PermissaoNegada::PermissaoNegada(int _id_permissao_user, int _id_permissao_acess, std::string _entidade_acessada, std::string _funcao_acessada){

  this->id_permissao_user=_id_permissao_user;
  this->id_permissao_acess=_id_permissao_acess;
  this->entidade_acessada=_entidade_acessada;
  this->funcao_acessada=_funcao_acessada;
  
}


int PermissaoNegada::GetPermissaoUser(){
  return this->id_permissao_user;
}


int PermissaoNegada::GetPermissaoAcesso(){
  return this->id_permissao_acess;
}


std::string PermissaoNegada::GetEntidade(){
  return this->entidade_acessada;
}


std::string PermissaoNegada::GetFuncao(){
  return this->funcao_acessada;
}


void PermissaoNegada::GerarLog(){
  Sistema::AttLog("LogAcessoNegado",this->GetUsuario(), this->GetFuncao(), this->GetEntidade(), "","");
}