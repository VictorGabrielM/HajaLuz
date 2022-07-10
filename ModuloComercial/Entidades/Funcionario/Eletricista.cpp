#include "../Sistema/Sistema.hpp"
#include <string>
#include "Eletricista.hpp"

Eletricista::Eletricista(std::string _nome, std::string _cpf, double _chapa, int _status,std::string _telefone){
  this->nome = _nome;
  this->cpfCnpj = _cpf;
  this->telefone = _telefone;
  this->status = _status;
  this->chapa = _chapa;
  this->capacitacao = "Tecnico";
  this->PermUser.AdicionarPermissao(4);
}
