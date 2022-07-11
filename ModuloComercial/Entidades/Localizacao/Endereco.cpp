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

std::string Endereco::GetComplemento(){
  return this->complemento;
}

void Endereco::SetComplemento(std::string _complemento){
  this->complemento = _complemento;
}

int Endereco::GetCep(){
  return this->cep;
}

void Endereco::SetCep(int _cep){
  this->cep = _cep;
}

std::string Endereco::GetCidade(){
  return this->cidade;
}

void Endereco::SetCidade(std::string _cidade){
  this->cidade = _cidade;
}

std::string Endereco::GetEstado(){
  return this->estado;
}

void Endereco::SetEstado(std::string _estado){
  this->estado = _estado;
}