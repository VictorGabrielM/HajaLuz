#include "Excecao.hpp"




Excecao::Excecao(std::string _tipo, std::string _descricao, std::string _usuario_logado){
  this->tipo=_tipo;
  this->descricao=_descricao;
  this->usuario_logado=_usuario_logado;
  this->dataEHora = this->dataEHora.dateNow();
}