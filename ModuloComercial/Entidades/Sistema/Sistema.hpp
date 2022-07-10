#pragma once

#include "../Usuario/Usuario.hpp"
#include "../Cliente/Cliente.hpp"
#include "../Funcionario/Funcionario.hpp"
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include "../Data/Data/Data.hpp"
#include "../Data/ExecaoCustomizada/ExecaoCustomizada.hpp"
#include <iostream>
#include "../Servico/Servico.hpp"
#include "../Servico/TiposServicos/DesligamentoEncerramento.hpp"
#include "../Servico/TiposServicos/DesligamentoInadimplencia.hpp"
#include "../Servico/TiposServicos/NovaLigacao.hpp"
#include "../Servico/TiposServicos/Religacao.hpp"
#include "../Servico/TiposServicos/TrocaMedidor.hpp"
#include "../Servico/TiposServicos/Medicao.hpp"
#include "../Unidade/Unidade.hpp"
#include "../Funcionario/Eletricista.hpp"
#include "../Funcionario/Leiturista.hpp"
#include "../Excecao/Excecao.hpp"
#include "../Log/Log.hpp"
#include "../Log/LogAcessoNegado.hpp"
#include "../Log/LogGravacao.hpp"
#include "../Log/LogLeitura.hpp"

class Sistema
{
private:
  static std::vector<Cliente> Clientes;                // Key = CPF(string)
  static std::vector<Cliente> ClientesLogados;         // Key = CPF(string)
  static std::vector<Funcionario> Funcionarios;        // Key = chapa(double)
  static std::vector<Funcionario> FuncionariosLogados; // Key = chapa(double)
  static std::vector<Log> Logs;
  static std::vector<Excecao> Excecoes;
  static Permissoes PermSystem;

public:
  Sistema();
  std::vector<Cliente> ExibirInadimplentes();
  void CriarServicoManual(Endereco endereco, double chapaFuncionario, std::string cpf_cnpjCliente, int tipoServico, std::string tipoUC);
  void DesligamentoInadimplencia(Endereco endereco, std::string cpf_cnpjCliente); // Esse Servico é criado automaticamente quando o cliente atinge faturas x nao pagas
  void PagarFatura(std::string _cpf_cnpj, Endereco _endereco, std::string _codigobarras);
  void ConcluirServico(double chapa);
  void CadastrarCliente(std::string _nome, int _status, std::string _telefone, std::string _cpfCnpj, bool _isPf, std::string _logradouro, int _numero, std::string _bairro, std::string _complemento, int _cep, std::string _cidade, std::string _estado);
  // OBS: CADASTRAR,ATIVAR E DESATIVAR UC SO DEVEM SER USADOS NOS METODOS FINALIZAR SERVICO
  void CadastrarUC(std::string _cpf_cnpj, std::string _tipo, Endereco _endereco);
  void DesativarUC(std::string _cpf_cnpj, Endereco _endereco);
  void AtivarUC(std::string _cpf_cnpj, Endereco _endereco); // TO DO
  void DesativarCliente(std::string _cpf_cnpj);
  void AtivarCliente(std::string _cpf_cnpj);
  void ExcluirCliente(std::string _cpf_cnpj);
  Funcionario* GetPtrFuncionario(double chapaFuncionario);
  Cliente* GetPtrCliente(std::string cpf_cnpjCliente);
  std::vector<Fatura> ExibirFaturasNaoPagas(std::string _cpfCnpj);
  void RegistrarFuncionario(std::string _nome, std::string _cpf, std::string _chapa, int _funcao, int _status, std::string _telefone);
  int BuscaCliente(std::string cpf);
  int BuscaClienteLogado(std::string);
  int BuscaFuncionario(double);
  int BuscaFuncionarioLogado(double);
  bool ValidarCPF(std::string cpf);
  bool ValidarCNPJ(std::string cnpj);
  Data GetDataHoje();
  Data GetDataHora();
  void CriaPermissao();
  void LogarCliente(std::string);
  void LogarFuncionario(double);
  void DeslogarCliente(std::string);
  void DeslogarFuncionario(double);
  void AttLog(std::string, std::string, std::string, std::string, std::string, std::string);
  void GerarLog();
  void LancaExcecao(std::string, std::string, std::string);
};
