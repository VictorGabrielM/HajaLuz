#include "Permissao.hpp"

Permissao::Permissao(int _ID){
  
  this->ID=_ID;
  
}

Permissoes::Permissoes(std::string _usuario){

  this->usuario=_usuario;
  this->AdicionarPermissao(1);
  
  }

bool Permissoes::AdicionarPermissao(int _ID){
  if(!this->Possui(_ID)){
    Permissao it = Permissao(_ID);
    this->ArrayPermissoes.insert(it);
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
    this->ArrayPermissoes.erase(it);
    return 1;
  }
  else{
    return 0;
  }
}

bool Permissoes::Possui(int _ID){
  Permissao it = Permissao(_ID);
  if(this->ArrayPermissoes.count(it)!=0){
    return 1;
  }
  else{
    return 0;
  }
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