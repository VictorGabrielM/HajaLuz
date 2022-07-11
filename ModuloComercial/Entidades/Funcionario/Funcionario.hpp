#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "../Servico/Servico.hpp"
#include "../Cliente/Cliente.hpp"
#include "../Data/Data/Data.hpp"
#include "../Usuario/Usuario.hpp"


class Funcionario: public Usuario{
  protected:
    int servicoAtual;
    double chapa;
    bool disponiblidade = true;
    std::map<Data, std::vector<Servico>> servicos;
    int nivelTreinamento;
    std::string capacitacao;
  public:
    Funcionario(){};
    double GetChapa();
    std::vector<Servico> VerServicos(Permissoes);
    std::string InserirServico(Data, Servico, Permissoes);
    std::string ComecarProximoServico(Permissoes);
    std::string ConcluirServico(Data, Permissoes);
    bool EstaDisponivel(Permissoes);
};

#endif