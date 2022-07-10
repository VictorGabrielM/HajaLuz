#pragma once

#include "Excecao.hpp"

class PermissaoNegada : public Excecao{

  private:

    int id_permissao_user;
    int id_permissao_acess;
    std::string entidade_acessada;
    std::string funcao_acessada;

  public:

    int GetPermissaoUser();
    int GetPermissaoAcesso();
    std::string GetEntidade();
    std::string GetFuncao();
    void GerarLog();
    PermissaoNegada(int,int,std::string,std::string);
    PermissaoNegada();

};
