#include "../Sistema/Sistema.hpp"
#include <string>
#include "Leiturista.hpp"

Leiturista::Leiturista(std::string _nome, std::string _cpf, std::string _chapa, int _status, std::string _telefone){
  this->nome = _nome;
  this->cpfCnpj = _cpf;
  this->telefone = _telefone;
  this->status = _status;
  this->chapa = _chapa;
  this->capacitacao = "Campo";
  this->PermUser.AdicionarPermissao(5);
}