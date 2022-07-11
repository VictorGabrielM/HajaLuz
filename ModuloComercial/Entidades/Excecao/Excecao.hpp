#ifndef EXCECAO_H
#define EXCECAO_H

#include <iostream>
#include "../Data/Data/Data.hpp"

class Excecao{
  private:

    std::string tipo, descricao, usuario_logado;
    Data dataEHora;
  
  public: 

    Excecao(std::string, std::string, std::string);
    std::string GetTipo();
    std::string GetDescricao();
    std::string GetUsuario();
    void Exibir();
    Excecao(){};
};

#endif