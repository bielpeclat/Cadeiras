//
// Created by gabriel-costa on 10/22/26.
//

#include <sstream>
#include "../imovel.h"

using namespace std;

int imovel::contador = 0;

imovel::imovel(const std::string &prefixo, double preco, double area, int andar) :
   preco(preco), area(area), andar(andar) {

   if (area <= 0) throw "Area invalida";

   codigo = prefixo + to_string(++contador) ;
}

std::string imovel::obterDescricao() const {
   ostringstream oss;
   oss << "Codigo: " << codigo << "; "
       << "Preco: " << preco << "; "
       << "Area: " << area << "; "
       << "Andar: " << andar;

   return oss.str();
}

void imovel::aumentarPreco() {
   preco += preco * getPercentagemAumento();
}
