//
// Created by gabriel-costa on 10/22/26.
//

#include "loja.h"
#include <sstream>
#include <string>

loja::loja (double area) : imovel("loja", 15*area, area, 0) {
}

std::string loja::obterDescricao() const {
   ostringstream oss;
   oss << "LOJA => " << imovel::obterDescricao();
   return oss.str();
}

double loja::getPercentagemAumento() const {
   return 0.01;
}
