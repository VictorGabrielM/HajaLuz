#include "Log.hpp"


Log::Log(std::string _usuario, Data _data){
  
  this->usuario=_usuario;
  this->data=_data;
  
}

std::string Log::GetUsuario(){
  
  return this->usuario;
  
}

Data Log::GetData(){

  return this->data;
  
}

std::string Log::ExibirLog(){
  std::cout<< "Usuário " << this->GetUsuario() << " logado no horário " << this->GetData().getData()<<std::endl;
}