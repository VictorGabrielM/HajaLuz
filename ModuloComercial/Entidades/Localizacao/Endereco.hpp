#ifndef ENDERECO_H
#define ENDERECO_H

#include "Localizacao.hpp"

class Endereco : public LocalizacaoGeografica {

  private:

    std::string logradouro;
    int numero;
    std::string bairro;
    std::string complemento;
    int cep;
    std::string cidade;
    std::string estado;

  public:

    Endereco(std::string, int, std::string, std::string, int, std::string, std::string);
    Endereco();

    std::string GetLogradouro();
    void SetLogradouro(std::string);
    int GetNumero();
    void SetNumero(int);
    std::string GetBairro();
    void SetBairro(std::string);
    std::string GetComplemento();
    void SetComplemento(std::string);
    int GetCep();
    void SetCep(int);
    std::string GetCidade();
    void SetCidade(std::string);
    std::string GetEstado();
    void SetEstado(std::string);
};

#endif