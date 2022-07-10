#include "Cliente.hpp"
#include <iostream>
#include <map>


Cliente::Cliente(std::string _nome, int _status, std::string _telefone, std::string _cpfCnpj, bool _isPf, Endereco _endereco){
  this->isPf = _isPf;
  this->nome = _nome;
  this->status = _status;
  this->telefone = _telefone;
  this->cpfCnpj = _cpfCnpj;
  this->endereco = _endereco;
  this->PermUser.AdicionarPermissao(2);
  this->PermUser.SetUSusario(_nome+_cpfCnpj);
}

std::string Cliente::CadastrarUC(std::string _tipo,Endereco _endereco, Permissoes _permissoes){
  if(this->isPf){
    if(_tipo=="residencial"){
      UnidadesConsumidoras.emplace(_endereco, new UnidadeConsumidora(_tipo, _endereco));
    }
    else{
      return "Cliente sem acesso a este tipo de cadastro";
    }
  }
  else if(!this->isPf){
    if(_tipo=="comercial" || _tipo=="publica" || _tipo=="industrial"){
      UnidadesConsumidoras.emplace(_endereco,new UnidadeConsumidora(_tipo, _endereco));
    }
    else{
      return "Cliente sem acesso a este tipo de cadastro";
    }
  } 
}
bool Cliente::GetInadimplente(Permissoes _permissoes){
  for(auto itUC=this->UnidadesConsumidoras.begin(); itUC!=this->UnidadesConsumidoras.end(); itUC++ ){
    if(itUC->second.Inadimplente()==1){
      return 1;
    }
    else{
      continue;
    }
  }
  return 0;
}

void Cliente::DesativarUC(Endereco _chave, Permissoes _permissoes){
  this->UnidadesConsumidoras[_chave].SetStatus(0);
}

void Cliente::AtivarUC(Endereco _chave, Permissoes _permissoes){
  this->UnidadesConsumidoras[_chave].SetStatus(1);
}

std::map<Endereco,UnidadeConsumidora> Cliente::ExibirUCs(Permissoes _permissoes){
  return this->UnidadesConsumidoras;
}

void Cliente::AdicionarFatura(Endereco _endereco, Permissoes _permissoes){
  this->qtdFaturasNaoPagas++;
  //Futuramente criar servico
  UnidadesConsumidoras[_endereco].CadastrarFatura();
}

std::string Cliente::PagarFatura(Endereco _endereco, std::string _codBarras, Permissoes _permissoes){
  if(this->UnidadesConsumidoras[_endereco].PagarFatura(_codBarras)){
    this->qtdFaturasNaoPagas--;
    return "Fatura paga com sucesso";
  }
  else{
    return "Não foi possível efetuar o pagamento";
  }
}

std::string Cliente::GetNome(Permissoes _permissoes){
  return this->nome;
}

void Cliente::SetNome(std::string _nome, Permissoes _permissoes){
  this->nome = _nome;
}

std::string Cliente::GetCpfCnpj(Permissoes _permissoes){
  return this->cpfCnpj;
}

void Cliente::SetCpfCnpj(std::string _cpfOuCnpj, Permissoes _permissoes){
  this->cpfCnpj = _cpfOuCnpj;
}

int Cliente::GetStatus(Permissoes _permissoes){
  return this->status;
}

void Cliente::SetStatus(int _status, Permissoes _permissoes){
  this->status = _status;
}

std::vector<UnidadeConsumidora> Cliente::getUnidadesConsumidoras(Permissoes _permissoes){
  return this->UnidadesConsumidoras;
}

void Cliente::SetEndereco(Endereco _endereco, Permissoes _permissoes){

  this->endereco.SetLogradouro(_endereco.GetLogradouro());
  this->endereco.SetNumero(_endereco.GetNumero());
  this->endereco.SetBairro(_endereco.GetBairro());
  this->endereco.SetComplemento(_endereco.GetComplemento());
  this->endereco.SetCep(_endereco.GetCep());
  this->endereco.SetCidade(_endereco.GetCidade());
  this->endereco.SetEstado(_endereco.GetEstado());
}

Endereco Cliente::GetEndereco(Permissoes _permissoes){
  return this->endereco;
}

void Cliente::SetGastoMesAtual(Endereco _endereco, float _valorRegistro, Permissoes _permissoes){
  this->UnidadesConsumidoras[_endereco].SetGastoMesAtual(_valorRegistro - this->UnidadesConsumidoras[_endereco].GetUltimaMedicao());
}

void Cliente::SetUltimaMedicao(Endereco _endereco, float _valorRegistro, Permissoes _permissoes){
  this->UnidadesConsumidoras[_endereco].SetUltimaMedicao(_valorRegistro);
}

void Cliente::IncrementaQtdFaturasNPagas(Permissoes _permissoes){
  this->qtdFaturasNaoPagas ++;
}

void Cliente::setUnidadesConsumidoras(std::map<Endereco,UnidadeConsumidora> _UnidadesConsumidoras, Permissoes _permissoes){
  this->UnidadesConsumidoras = _UnidadesConsumidoras;
}

bool Cliente::PossuiPermissao(int _ID, Permissoes _permissoes){
  this->PermUser.Possui(_ID);
}

bool Cliente::AdicionaPermissao(int _ID, Permissoes _permissoes){
  this->PermUser.AdicionarPermissao(_ID);
}

bool Cliente::RetiraPermissao(int _ID, Permissoes _permissoes){
  this->PermUser.RetirarPermissao(_ID);
}