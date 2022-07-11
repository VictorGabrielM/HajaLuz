#ifndef FATURA_H
#define FATURA_H

#include "../Data/Data/Data.hpp"

class Fatura {
  private:
    std::string codBarras;
    float valor=0;
    bool paga=0;
    bool atrasada=0;
    float consumo=0;
    Data expedida=0;
    Data vencimento=0;
    void CalculaJuros(float, Data);
    void CalculaConsumo(float, float);
    void CalculaValor(float);
    Fatura ExibirFatura();
  public:
    int PagarFatura();
    std::string GetCodBarras();
    void SetCodBarras(std::string);
    float GetValor();
    void SetValor(float);
    bool GetPaga();
    void SetPaga(bool);
    bool GetAtrasada();
    void SetAtrasada(bool);
    float GetConsumo();
    void SetConsumo(float);
    Fatura(std::string, float, float, float);  
    Fatura(){};

};

#endif