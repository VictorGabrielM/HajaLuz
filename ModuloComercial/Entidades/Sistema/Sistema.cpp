#include "Sistema.hpp"





std::vector<Cliente> Sistema::ExibirInadimplentes(){

}


bool ValidarCPF(std::string cpf){
  //Retorno: [1] - Se for válido | [0] - Se for inválido
    int i, j, digito1 = 0, digito2 = 0;
    if(cpf.length() != 11){
        return 0;
      }
    else if((cpf.compare("00000000000") == 0) || (cpf.compare("11111111111") == 0) || (cpf.compare("22222222222") == 0) ||
            (cpf.compare("33333333333") == 0) || (cpf.compare("44444444444") == 0) || (cpf.compare("55555555555") == 0) ||
            (cpf.compare("66666666666") == 0) || (cpf.compare("77777777777") == 0) || (cpf.compare("88888888888") == 0) ||
            (cpf.compare("99999999999") == 0)){
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
      }
    else
    {
      ///digito 1---------------------------------------------------
      for(i = 0, j = 10; i < cpf.length()-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
        digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2){
          digito1 = 0;
        }
        else {
          digito1 = 11 - digito1;
        }
        if((cpf[9]-48) != digito1){
          return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        }
        else
        ///digito 2--------------------------------------------------
        {
          for(i = 0, j = 11; i < cpf.length()-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
            digito2 += (cpf[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2)
              digito2 = 0;
            else
              digito2 = 11 - digito2;
            if((cpf[10]-48) != digito2)
              return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}
  
bool ValidarCNPJ(std::string cnpj) {

  //Retorno: [1] - Se for válido | [0] - Se for inválido
    int i, j, digito1 = 0, digito2 = 0;
    if(cnpj.length() != 14)
        return 0;
    else if((cnpj.compare("00000000000000") == 0) || (cnpj.compare("11111111111111") == 0) || (cnpj.compare("22222222222222") == 0) ||
            (cnpj.compare("33333333333333") == 0) || (cnpj.compare("44444444444444") == 0) || (cnpj.compare("55555555555555") == 0) ||
            (cnpj.compare("66666666666666") == 0) || (cnpj.compare("77777777777777") == 0) || (cnpj.compare("88888888888888") == 0) ||
            (cnpj.compare("99999999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 11, j = 2; i >= cnpj.length()-10; i--, j++) 
            digito1 += (cnpj[i]-48) * j;
        for(i = 0, j = 5; i < cnpj.length()-10; i++, j--) 
            digito1 += (cnpj[i]-48) * j;
      
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cnpj[12]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CNPJ é inválido
        else
        ///digito 2--------------------------------------------------
        {
          for(i = 12, j = 2; i >= cnpj.length()-9; i--, j++) 
            digito2 += (cnpj[i]-48) * j;
          for(i = 0, j = 6; i < cnpj.length()-9; i++, j--) 
            digito2 += (cnpj[i]-48) * j;
          
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cnpj[13]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CNPJ é inválido
        }
    }
    return 1;
  
}

Funcionario* Sistema::GetPtrFuncionario(double chapaFuncionario){
  Funcionario* F;
  int i = 0;
  for(auto itF : Funcionarios){
    if(itF.GetChapa() == chapaFuncionario ){
      F = &Funcionarios[i];
    }
    i++;
  }
  return F;
}

Cliente* Sistema::GetPtrCliente(std::string cpf_cnpjCliente){
  Cliente* C;
  int i = 0;
  for(auto itC : Clientes){
    if(itC.GetCpfCnpj(itC.PermUser)== cpf_cnpjCliente ){
      C = &Clientes[i];
    }
    i++;
  }
  return C;
}

void Sistema::CriarServicoManual(Endereco endereco, double chapaFuncionario, std::string cpf_cnpjCliente, int tipoServico, std::string tipoUC = "nao usado"){
  switch(tipoServico){
    case 0:{//Desligamento por Encerramento
      DesligamentoEncerramento d1(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), d1, PermSystem);
      break;
    }
    case 1:{//Desligamento por Inadimplencia
      class DesligamentoInadimplencia d2(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), d2, PermSystem);
      break;
    }  
    case 2:{//Nova Ligacao
      NovaLigacao nl(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), nl, PermSystem);
      break;
    }  
    case 3:{//Religacao
      Religacao de(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), de, PermSystem);
      break;
    }
    case 4:{//Troca Medidor
      TrocaMedidor tm(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), tm, PermSystem);
      break;
    }
    case 5:{//Medicao
      Medicao m(endereco,GetPtrCliente(cpf_cnpjCliente),tipoUC);
      Funcionario* F = GetPtrFuncionario(chapaFuncionario);
      F->InserirServico(GetDataHoje(), m, PermSystem);
      break;
    }
    
    break;
  }
}

void Sistema::CadastrarCliente(std::string _nome,int _status, std::string _telefone, std::string _cpfCnpj,bool _isPf,std::string _logradouro, int _numero, std::string _bairro, std::string _complemento, int _cep, std::string _cidade, std::string _estado){
  if(_isPf && Sistema::ValidarCPF(_cpfCnpj)){
    Endereco ef(_logradouro,_numero,_bairro,_complemento,_cep,_cidade,_estado);
    Cliente c(_nome,_status,_telefone,_cpfCnpj,_isPf,ef);  
    Clientes.push_back(c);
  }else if(!_isPf &&   Sistema::ValidarCNPJ(_cpfCnpj)){
    Endereco ej(_logradouro,_numero,_bairro,_complemento,_cep,_cidade,_estado);
    Cliente c1(_nome,_status,_telefone,_cpfCnpj,_isPf,ej);
    Clientes.push_back(c1);
  }  
}

void Sistema::CadastrarUC(std::string _cpf_cnpj, std::string _tipo, Endereco _endereco){
  Cliente* c = GetPtrCliente(_cpf_cnpj);
  c->CadastrarUC(_tipo,_endereco,c->PermUser);
}

void Sistema::DesativarUC(std::string _cpf_cnpj, Endereco _endereco){
  Cliente* c = GetPtrCliente(_cpf_cnpj);
  c->DesativarUC(_endereco,c->PermUser);
}

void Sistema::AtivarUC(std::string _cpf_cnpj, Endereco _endereco){
  Cliente* c = GetPtrCliente(_cpf_cnpj);
  c->AtivarUC(_endereco,c->PermUser);
}

void Sistema::DesativarCliente(std::string _cpf_cnpj){
  Cliente* c = GetPtrCliente(_cpf_cnpj);
  c->SetStatus(0, PermSystem);
}

void Sistema::AtivarCliente(std::string _cpf_cnpj){
  Cliente* c = GetPtrCliente(_cpf_cnpj);
  c->SetStatus(1,c->PermUser);
}

void Sistema::ExcluirCliente(std::string _cpf_cnpj){
  std::vector<Cliente>::iterator itC = Clientes.begin();
  for(;itC != Clientes.end();itC++){
    if(itC->GetCpfCnpj(itC->PermUser) == _cpf_cnpj){
      Clientes.erase(itC);
    }
  }
}

void Sistema::RegistrarFuncionario(std::string _nome, std::string _cpf, std::string _chapa, int _funcao,int _status, std::string _telefone){
  if(Sistema::ValidarCPF(_cpf) && _funcao == 0){              //Funcoes indices: 0 -> Eletricista 
    Eletricista e(_nome,_cpf,_chapa,_status,_telefone);                       // 1 -> Leiturista    
    Funcionarios.push_back(e);
  }else if(Sistema::ValidarCPF(_cpf) && _funcao == 1){
    Leiturista l(_nome,_cpf,_chapa,_status,_telefone);
    Funcionarios.push_back(l);
  }
}

std::vector<Fatura> Sistema::ExibirFaturasNaoPagas(std::string _cpfCnpj){
  std::list<Fatura> f;
  std::vector<Cliente>::iterator itC = Clientes.begin();
  std::vector<UnidadeConsumidora>::iterator itUC = Clientes.begin()->getUnidadesConsumidoras(PermSystem).begin();
  std::vector<Fatura>::iterator itF = Clientes.begin()->getUnidadesConsumidoras(PermSystem).begin()->getFaturas().begin();
  std::vector<Fatura> faturas;
  for(;itC != Clientes.end();itC++){
    if(itC->GetCpfCnpj(itC->PermUser) != _cpfCnpj) continue;
    itUC = itC->getUnidadesConsumidoras(PermSystem).begin();
    for(;itUC != itC->getUnidadesConsumidoras(PermSystem).end();itUC++){
      itF = itUC->getFaturas().begin();
      for(;itF!=itUC->getFaturas().end();itF++){
        if(!itF->GetPaga()) continue;
        faturas.push_back(*itF);
      }
    }
  }
  return faturas;
}

void Sistema::ConcluirServico(double chapa){
  Funcionario* F = GetPtrFuncionario(chapa);
  F->ConcluirServico(GetDataHoje(),F->PermUser);
}

/*
void Sistema::DesligamentoInadimplencia(Endereco endereco, std::string cpf_cnpjCliente){
  std::map<double,Funcionario>::
  
}*/

void Sistema::PagarFatura(std::string _cpf_cnpj, Endereco _endereco, std::string _codigobarras){
  Cliente* C = GetPtrCliente(_cpf_cnpj);
  C->PagarFatura(_endereco,_codigobarras,C->PermUser);
} //PAREI AQUI, FALTA IMPLEMENTAR A PAGAR FATURA DE CLIENTE, LEMBRAR SE DE PONTEIROS.

Data Sistema::GetDataHoje(){
  Data hoje=Data();
  hoje=hoje.dateNow();
  hoje.setHora(0);
  hoje.setMin(0);
  hoje.setSeg(0);
  hoje.setTicks(0);
  return hoje;
}

Data Sistema::GetDataHora(){
  Data hoje=Data();
  hoje=hoje.dateNow();
  return hoje;
  
}

void Sistema::CriaPermissao(){
  PermSystem.AdicionarPermissao(7);
}

void Sistema::AttLog(std::string _tipo, std::string _usuario, std::string _atributo, std::string _entidade, std::string _valor_original, std::string _valor_alterado){

  if(_tipo=="Log"){
    
    Logs.emplace_back(Log(_usuario, Sistema::GetDataHora()));
    
  }
  else if(_tipo=="LogLeitura"){
    
    Logs.emplace_back(LogLeitura(_entidade, _atributo, _usuario, Sistema::GetDataHora()));
      
  }
  else if(_tipo=="LogGravacao"){
    
    Logs.emplace_back(LogGravacao(_entidade, _atributo, _valor_original, _valor_alterado, _usuario, Sistema::GetDataHora()));
        
  }
  else if(_tipo=="LogAcessoNegado"){
    
    Logs.emplace_back(LogAcessoNegado(_entidade, _atributo, _usuario, Sistema::GetDataHora()));
        
  }
  
}


void Sistema::GerarLog(){
  for(auto itLog = Logs.begin() ; itLog != Logs.end(); itLog++){
    itLog->ExibirLog();
  }
}


int Sistema::BuscaCliente(std::string _CPF){
  int i = 0;

  for(auto itC : Clientes){
    if(itC.GetCpfCnpj(itC.PermUser) == _CPF){
      i++;
      break;
    }
  }

  return i;
}
  
  
int Sistema::BuscaClienteLogado(std::string _CPF){
  int i = 0;
  
  for(auto itC : ClientesLogados){
    if(itC.GetCpfCnpj(itC.PermUser) == _CPF){
      i++;
      break;
    }
  }
  
  return i;
}


int Sistema::BuscaFuncionario(double _chapa){

  int i = 0;
  
  for(auto itF : Funcionarios){
    if(itF.GetChapa() == _chapa){
      i++;
      break;
    }
  }
  
  return i;
}

  
int Sistema::BuscaFuncionarioLogado(double _chapa){
  int i = 0;
  
  for(auto itF : FuncionariosLogados){
    if(itF.GetChapa() == _chapa){
      i++;
      break;
    }
  }
  
  return i;
  
}
  
  
void Sistema::LogarCliente(std::string _CPF){
  
  if( BuscaCliente(_CPF) > 0 ){

    if( BuscaClienteLogado(_CPF) > 0 ){
  
      LancaExcecao("Erro de login","Usuario requisitado já está logado","CPF :"+_CPF);
      
    }
    else{
      
      ClientesLogados.push_back(*GetPtrCliente(_CPF));
      
    }
    
  }
  else{
    
    LancaExcecao("Erro de cadastro","Usuario requisitado não está cadastrado","CPF :"+_CPF);
    
  }
  
}

  
void Sistema::LogarFuncionario(double _chapa){

  if( BuscaFuncionario(_chapa) > 0 ){

    if( BuscaFuncionarioLogado(_chapa) > 0 ){
  
      LancaExcecao("Erro de login","Funcionario requisitado já está logado","Chapa: "+to_string(_chapa));
      
    }
    else{
      
      FuncionariosLogados.push_back(*GetPtrFuncionario(_chapa));
      
    }
    
  }
  else{
    
    LancaExcecao("Erro de cadastro","Funcionario requisitado não está cadastrado","Chapa:"+to_string(_chapa));
    
  }
  
}

  
void Sistema::DeslogarCliente(std::string _CPF){
  std::vector<Cliente>::iterator itC = ClientesLogados.begin();
  if( BuscaCliente(_CPF) > 0 ){

    if( BuscaClienteLogado(_CPF) <= 0 ){
  
      LancaExcecao("Erro de logoff","Usuario requisitado não está logado","CPF :"+_CPF);
      
    }
    else{
      
      for(;itC != ClientesLogados.end();itC++){
        if(itC->GetCpfCnpj(itC->PermUser) == _CPF){
          ClientesLogados.erase(itC);
          break;
        }
      }
      
    }
    
  }
  else{
    
    LancaExcecao("Erro de logoff","Usuario requisitado não está cadastrado","CPF :"+_CPF);
    
  }
  
}

  
void Sistema::DeslogarFuncionario(double _chapa){
  std::vector<Funcionario>::iterator itF = FuncionariosLogados.begin();
  if( BuscaFuncionario(_chapa) > 0 ){

    if( BuscaFuncionarioLogado(_chapa) <= 0 ){
  
      LancaExcecao("Erro de logoff","Funcionario requisitado não está logado","Chapa :"+to_string(_chapa));
      
    }
    else{
      
      for(;itF != FuncionariosLogados.end();itF++){
        if(itF->GetChapa() == _chapa){
          FuncionariosLogados.erase(itF);
          break;
        }
      }
      
    }
    
  }
  else{
    
    LancaExcecao("Erro de logoff","Funcionario requisitado não está cadastrado","Chapa :"+to_string(_chapa));
    
  }
  
}

void Sistema::LancaExcecao(std::string _tipo, std::string _descricao, std::string _usuario_logado){

  Excecoes.push_back(Excecao(_tipo,_descricao,_usuario_logado));
  
}