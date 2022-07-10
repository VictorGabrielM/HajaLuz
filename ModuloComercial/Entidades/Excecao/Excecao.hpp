#pragma once

#include <iostream>
#include "../Sistema/Sistema.hpp"

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
    Excecao();
};
