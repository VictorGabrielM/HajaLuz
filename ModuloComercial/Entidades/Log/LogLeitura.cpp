#include "LogLeitura.hpp"


LogLeitura::LogLeitura(std::string _entidade_acessada,std::string _atributo, std::string _usuario, Data _data){
  
  this->entidade_acessada=_entidade_acessada;
  this->atributo=_atributo;
  this->usuario=_usuario;
  this->data=_data;
  
}

std::string LogLeitura::GetEntidade(){
  return this->entidade_acessada;
}

std::string LogLeitura::GetAtributo(){
  return this->atributo;
}

void LogLeitura::ExibirLog(){
std::cout<< "Usuário " << this->GetUsuario() << " teve acesso a entidade "<< this->GetEntidade()<< ", na funcao "<< this->GetAtributo() << " no horário ";
  this->GetData().getData();
  std::cout << std::endl;
}