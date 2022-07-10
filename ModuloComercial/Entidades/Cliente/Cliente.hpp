#pragma once

#include "../Unidade/Unidade.hpp"
#include "../Sistema/Sistema.hpp"
#include "../Localizacao/Endereco.hpp"
#include "../Permissao/Permissao.hpp"
#include "../Usuario/Usuario.hpp"
#include <set>
#include <iostream>

class Cliente : public Usuario {
  private:
    Endereco endereco;
    bool isPf;  
    int qtdFaturasNaoPagas;
    std::vector<UnidadeConsumidora> ExibirUCs(Permissoes);
    bool Inadimplente(Permissoes);

  protected:
    std::vector<UnidadeConsumidora> UnidadesConsumidoras;

  public:
    Cliente(std::string _nome,int _status, std::string _telefone, std::string _cpfOuCnpj, bool _isPf, Endereco _endereco);
    Cliente();
    std::string GetNome(Permissoes);
    void SetNome(std::string, Permissoes);
    bool GetInadimplente(Permissoes);
    void SetInadimplente(bool, Permissoes);
    std::string GetCpfCnpj(Permissoes);
    void SetCpfCnpj(std::string, Permissoes);
    int GetStatus(Permissoes);
    void AdicionarFatura(Endereco, Permissoes);
    void SetStatus(int, Permissoes);
    std::string GetNumeroTel(Permissoes);
    void SetNumeroTel(std::string, Permissoes);
    std::vector<UnidadeConsumidora> getUnidadesConsumidoras(Permissoes);
    void setUnidadesConsumidoras(std::map<Endereco,UnidadeConsumidora>, Permissoes);
    void SetEndereco(Endereco, Permissoes);
    Endereco GetEndereco(Permissoes);
    void SetUltimaMedicao(Endereco, float, Permissoes);
    void SetGastoMesAtual(Endereco, float, Permissoes);
    void IncrementaQtdFaturasNPagas(Permissoes);
    void DecrementaQtdFaturasNPagas(Permissoes);
    int GetQtdFaturasNPagas(Permissoes);
    bool PossuiPermissao(int, Permissoes);
    bool AdicionaPermissao(int, Permissoes);
    bool RetiraPermissao(int, Permissoes);
    std::string PagarFatura(Endereco, std::string, Permissoes);
    std::string CadastrarUC(std::string _tipo,Endereco _endereco, Permissoes _permissoes);
    void DesativarUC(Endereco, Permissoes);
    void AtivarUC(Endereco, Permissoes);
};

