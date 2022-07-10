#include "Permissao.hpp"

Permissao::Permissao(int _ID){
  
  this->ID=_ID;
  
}

int Permissao::getID(){
  return this->ID;
}

Permissoes::Permissoes(std::string _usuario){

  this->usuario=_usuario;
  this->AdicionarPermissao(1);
  
  }

bool Permissoes::AdicionarPermissao(int _ID){
  if(!this->Possui(_ID)){
    Permissao it = Permissao(_ID);
    this->ArrayPermissoes.push_back(it);
    return 1;
  }
  else{
    return 0;
  }
}

bool Permissoes::RetirarPermissao(int 
_ID ){
  if(this->Possui(_ID)){
    Permissao it = Permissao(_ID);
    this->ArrayPermissoes.push_back(it);
    return 1;
  }
  else{
    return 0;
  }
}

bool Permissoes::Possui(int _ID){
  for(auto itP : ArrayPermissoes){
    if(itP.getID() == _ID ){
      return true;
    }
  }
  return false;
}

std::string Permissoes::GetUsuario(){
  
  return this->usuario;
  
}

void Permissoes::SetUSusario(std::string _usuario){
  
  this->usuario=_usuario;
  
}



/* ID 1 : Usuario padrão
   ID 2 : Cliente
   ID 3 : Funcionario 
   ID 4 : Eletricista
   ID 5 : Leiturista 
   ID 6 : Administrador 
   ID 7 : Sistema
*/