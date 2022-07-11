#include <iostream>
#include "Fatura.hpp"


Fatura::Fatura(std::string _codBarras, float _taxaValor, float _horasUsadas, float _ultimaMedicao){
  //Data
  double aux=2592000;
  this->SetCodBarras(_codBarras);
  this->CalculaConsumo(_horasUsadas,_ultimaMedicao);
  this->CalculaValor(_taxaValor);
  this->expedida=expedida.dateNow();
  this->expedida.dateToTicks();
  this->vencimento.setTicks(aux+expedida.getTicks());
  this->vencimento.ticksToDate();
    
}   



void Fatura::CalculaJuros(float taxa, Data dataAtual){
  int dias = dataAtual.diffData(this->vencimento);
  if(dias>0)
    this->SetValor(this->valor * (taxa + 1) * dias);
}

int Fatura::PagarFatura(){
  bool _return;
  this->GetPaga() == 1 ? _return=0 : _return=1;
  this->SetPaga(1);
  return _return;
}

Fatura Fatura::ExibirFatura(){
  return *this;
}

void Fatura::CalculaConsumo(float horasUsadas, float ultimaMedicao ){
  this->SetConsumo(ultimaMedicao/horasUsadas);
}

void Fatura::CalculaValor(float taxaValor){
  this->SetValor(taxaValor*this->GetConsumo());
}

std::string Fatura::GetCodBarras(){
  return this->GetCodBarras();
}

void Fatura::SetCodBarras(std::string _codBarras){
  this->codBarras =_codBarras;
}

float Fatura::GetValor(){
  return this->valor;
}

void Fatura::SetValor(float _valor){
  this->valor=_valor;	
}

bool Fatura::GetPaga(){
  return this->paga;
}

void Fatura::SetPaga(bool _status){
  this->paga=_status;
}

bool Fatura::GetAtrasada(){
  return this->atrasada;
}

void Fatura::SetAtrasada(bool _atrasada){
  this->atrasada=_atrasada;
}

float Fatura::GetConsumo(){
  return this->consumo;
}

void Fatura::SetConsumo(float _consumo){
  this->consumo=_consumo;
}