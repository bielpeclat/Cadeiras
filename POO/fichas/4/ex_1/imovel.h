//
// Created by gabriel-costa on 10/22/26.
//

#ifndef INC_4_IMOVEL_H
#define INC_4_IMOVEL_H
#include <string>

class imovel {
public:
   std::string obterCodigo() const noexcept { return codigo; }
   double obterArea() const noexcept { return area; }
   double obterPreco() const noexcept { return preco; }
   double obterAndar() const noexcept { return andar; }
   virtual std::string obterDescricao() const; // ver melhor o que o virtual faz

   void aumentarPreco();

   virtual ~imovel() = default;

protected:
   imovel(const std::string &prefixo, double preco, double area, int andar);
   virtual double getPercentagemAumento() const = 0;

private:
   std::string codigo;
   double preco, area;
   int andar;

   static int contador;
};


#endif //INC_4_IMOVEL_H