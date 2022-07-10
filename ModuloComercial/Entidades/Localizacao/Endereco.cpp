#include <iostream>
#include "Endereco.hpp"

Endereco::Endereco(std::string _logradouro, int _numero, std::string _bairro, std::string _complemento, int _cep, std::string _cidade, std::string _estado){

  logradouro = _logradouro;
  numero = _numero;
  bairro = _bairro;
  complemento = _complemento;
  cep = _cep;
  cidade = _cidade;
  estado = _estado;   
}

Endereco::Endereco(){

  logradouro = "logradouro";
  numero = 1234;
  bairro = "bairro";
  complemento = "complemento";
  cep = 12345678;
  cidade = "cidade";
  estado = "estado";
}

std::string Endereco::GetLogradouro(){
  return this->logradouro;
}

void Endereco::SetLogradouro(std::string _logradouro){
  this->logradouro = _logradouro;
}

int Endereco::GetNumero(){
  return this->numero;
}

void Endereco::SetNumero(int _numero){
  this->logradouro = _numero;
}

std::string Endereco::GetBairro(){
  return this->bairro;
}

void Endereco::SetBairro(std::string _bairro){
  this->bairro = _bairro;
}