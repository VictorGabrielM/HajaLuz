#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "../Permissao/Permissao.hpp"

class Usuario{
  public:
    Permissoes PermUser;
    Usuario();
  protected:
    std::string nome;
    int status;
    std::string telefone;
    std::string cpfCnpj;


};

#endif
