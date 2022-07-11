#pragma once

#include <iostream>
#include <string>
#include "../Data/Data/Data.hpp"
#include "../Permissao/Permissao.hpp"


class Log{
  
  protected:
    std::string usuario;
    Data data;

  public:

    std::string GetUsuario();
    Data GetData();
    Log(std::string, Data);
    std::string ExibirLog();
    Log(){};
  
};
