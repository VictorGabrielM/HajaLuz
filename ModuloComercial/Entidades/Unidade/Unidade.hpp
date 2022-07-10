#ifndef UNIDADE_H
#define UNIDADE_H

#include "../Fatura/Fatura.hpp"
#include "../Localizacao/Endereco.hpp"
#include <map>
#include <set>

class UnidadeConsumidora {

  public:
    UnidadeConsumidora(std::string, Endereco);
    UnidadeConsumidora();
    void CadastrarFatura();
    std::string GetTipo();
    void SetTipo(std::string);
    Endereco GetEndereco();
    void SetEndereco(Endereco);
    bool GetStatus();
    void SetStatus(bool);
    bool GetRecebeEnergia();
    void SetRecebeEnergia(bool);
    float GetHorasUsadas();
    void SetHorasUsadas(float);

    float GetUltimaMedicao();
    void SetUltimaMedicao(float);
    float GetGastoMesAtual();
    void SetGastoMesAtual(float);
    float GetTaxaValor();
    void SetTaxaValor(float);
    std::vector<Fatura> getFaturas();//TO DO
    void setFaturas(std::vector<Fatura>);
    bool PagarFatura(std::string);
    bool Inadimplente();
    void AdicionarFatura(Fatura);
    std::vector<Fatura> ExibirFaturas();
    Fatura* GetPtrFatura(std::string _codBarras);
  protected:
    std::vector<Fatura> Faturas;

  private:
    std::string tipo;
    bool inadimplente = false;
    Endereco endereco;
    bool status = 0;
    bool recebeEnergia = 0;
    float horasUsadas = 0;
    float gastoMesAtual = 0; 
    float ultimaMedicao = 0;
    float taxaValor;
    std::string GerarCodBarras();

};

#endif
