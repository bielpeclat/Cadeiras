//
// Created by gabriel-costa on 10/22/26.
//

#include <sstream>
#include "../apartamento.h"

using namespace std;

apartamento::apartamento(double area, int andar, int assoalhadas)  :
   imovel("apartamento", 10*area, area, andar), assoalhadas(assoalhadas)
{
   if (assoalhadas < 0) throw "Numero de assoalhadas invalido";
}

std::string apartamento::obterDescricao() const {

   ostringstream oss;
   oss << "APARTAMENTO => " << imovel::obterDescricao()
       << "; Assoalhadas: " << assoalhadas;
   return oss.str();

}

double apartamento::getPercentagemAumento() const {
   return assoalhadas / 100.0;
}
