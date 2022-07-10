#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include "Unidade.hpp"
#include "../Fatura/Fatura.hpp"


std::set<std::string> allCodBarras;

std::map<std::string,Fatura> UnidadeConsumidora::ExibirFaturas(){
  return this->Faturas;
}

bool UnidadeConsumidora::PagarFatura(std::string _chave){
  return this->Faturas[_chave].PagarFatura();
}

void UnidadeConsumidora::CadastrarFatura(){
  if(this->GetRecebeEnergia()==1){
    std::string codBarras=this->GerarCodBarras();
    this->Faturas.emplace(codBarras,Fatura(codBarras,this->taxaValor, this->horasUsadas, this->ultimaMedicao));
  }
}

void UnidadeConsumidora::AdicionarFatura(Fatura _fatura){
  if(this->GetRecebeEnergia()==1){
    this->Faturas.emplace(_fatura.GetCodBarras(),_fatura);
  }
}

bool UnidadeConsumidora::Inadimplente(){
  for(auto itF=this->Faturas.begin(); itF!=this->Faturas.end(); itF++ ){
    if(itF->second.GetAtrasada()==1){
      return 1;
    }
    else{
      continue;
    }
  }
  return 0;
}

UnidadeConsumidora::UnidadeConsumidora(std::string _tipo, Endereco _endereco){
  SetEndereco(_endereco);
  SetTipo(_tipo);
  if(_tipo=="residencial"){
    SetTaxaValor(0.618050);
  }
  else if(_tipo=="comercial"){
    SetTaxaValor(0.765210);
  }
  else if(_tipo=="industrial"){
    SetTaxaValor(13.98);
  }
  else if(_tipo=="publica"){
    SetTaxaValor(0.339930);
  }
}

std::string UnidadeConsumidora::GerarCodBarras(){
  srand (time(NULL));
  std::string _codBarras;
  do{
    for(int i=0; i<10; i++){
      _codBarras += std::to_string((rand()%10));
    }
  }while(allCodBarras.count(_codBarras)!=0);
  allCodBarras.insert(_codBarras);
  return _codBarras;
}
std::string UnidadeConsumidora::GetTipo(){
  return this->tipo;
}

void UnidadeConsumidora::SetTipo(std::string _tipo){
  this->tipo=_tipo;
}

Endereco UnidadeConsumidora::GetEndereco(){
  return this->endereco;
}

void UnidadeConsumidora::SetEndereco(Endereco _endereco){
  this->endereco = _endereco;
}

bool UnidadeConsumidora::GetStatus(){
  return this->status;
}

void UnidadeConsumidora::SetStatus(bool _status){
  this->status=_status;
}

bool UnidadeConsumidora::GetRecebeEnergia(){
  return this->recebeEnergia;
}
void UnidadeConsumidora::SetRecebeEnergia(bool _recebeEnergia){
  this->recebeEnergia=_recebeEnergia;
}

float UnidadeConsumidora::GetHorasUsadas(){
  return this->horasUsadas;
}

void UnidadeConsumidora::SetHorasUsadas(float _horasUsadas){
  this->horasUsadas=_horasUsadas;
}

float UnidadeConsumidora::GetUltimaMedicao(){
  return this->ultimaMedicao;
}

void UnidadeConsumidora::SetUltimaMedicao(float valorRegistro){
  this->ultimaMedicao=valorRegistro;
}

float UnidadeConsumidora::GetGastoMesAtual(){
  return this->gastoMesAtual;
}

void UnidadeConsumidora::SetGastoMesAtual(float valorMesAtual){
  this->gastoMesAtual=valorMesAtual;
}

float UnidadeConsumidora::GetTaxaValor(){
  return this->taxaValor;
}

void UnidadeConsumidora::SetTaxaValor(float _taxaValor){
  this->ultimaMedicao=_taxaValor;
}

void UnidadeConsumidora::setFaturas(std::map<std::string,Fatura> _Faturas){
  this->Faturas = _Faturas;
}

std::vector<Fatura> UnidadeConsumidora::getFaturas(){
  return this->Faturas;
}
