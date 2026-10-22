//
// Created by gabriel-costa on 10/22/26.
//

#include "imobiliaria.h"
#include <sstream>

imobiliaria::imobiliaria() : numImoveis(0) {
}

bool imobiliaria::acrescentar(imovel *imovel) {
   if (numImoveis >= MAX_IMOVES || imovel == nullptr) {
      return false;
   }

   int indice = procurarIndiceImovel(imovel->obterCodigo());
   if (indice >= 0) {
      return false;
   }
   imoveis[numImoveis++] = imovel;
   return true;
}

bool imobiliaria::remover(const std::string &codigo) {
   int indice = procurarIndiceImovel(codigo);
   if (indice < 0) {
      return false;
   }
   for (int i = indice; i<numImoveis-1; i++)
      imoveis[i] = imoveis[i+1];
   numImoveis--;
   return true;
}

std::string imobiliaria::obterLista() const {
   std::ostringstream oss;
   oss << "Lista de Imoveis: \n";
   for (int i = 0; i < numImoveis; i++) {
      oss << imoveis[i]->obterDescricao() << std::endl;
   }
   return oss.str();
}

std::string imobiliaria::obterLista(int andar) const {
   std::ostringstream oss;
   oss << "Lista de Imoveis no andar: " << andar << "\n";
   for (int i = 0; i < numImoveis; i++) {
      if (imoveis[i]->obterAndar() == andar) {
         oss << imoveis[i]->obterDescricao() << std::endl;
      }
   }
   return oss.str();
}

std::string imobiliaria::obterDescricao(const std::string &codigo) const {
   if (codigo.empty()) return "";
   int indice = procurarIndiceImovel(codigo);
   if (indice < 0) {
      return "";
   }
   return imoveis[indice]->obterDescricao();
}

const imovel * imobiliaria::getImovel(const std::string &codigo) const {
   if (codigo.empty()) return nullptr;
   int indice = procurarIndiceImovel(codigo);
   if (indice < 0)
      return nullptr;
   return imoveis[indice];
}

void imobiliaria::aumentarPrecos() {
   for (int i = 0; i < numImoveis; i++) {
      imoveis[i]->aumentarPreco();
   }
}

int imobiliaria::procurarIndiceImovel (const std::string &codigo) const {
   for (int i = 0; i < numImoveis; i++) {
      if (imoveis[i]->obterCodigo() == codigo) {
         return i;
      }
   }
   return -1;
}
