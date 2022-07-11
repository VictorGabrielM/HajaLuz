#ifndef PERMISSAO_H
#define PERMISSAO_H

#include <iostream>
#include <vector>
#include <string>

class Permissao{
  private:
    int ID;
  public:
    int getID();
    Permissao(int);  
    //Permissao();
};

class Permissoes{
  private:
    std::vector<Permissao> ArrayPermissoes;
    std::string usuario;
  public:
    bool Possui(int);
    bool AdicionarPermissao(int);
    bool RetirarPermissao(int);
    Permissoes(std::string);
    Permissoes();
    std::string GetUsuario();
    void SetUSusario(std::string);
  
};

/* ID 1 : Usuario padrão
   ID 2 : Cliente
   ID 3 : Funcionario 
   ID 4 : Eletricista
   ID 5 : Leiturista 
   ID 6 : Administrador 
   ID 7 : Sistema
*/

#endif