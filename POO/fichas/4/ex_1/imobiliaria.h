//
// Created by gabriel-costa on 10/22/26.
//

#ifndef INC_4_IMOBILIARIA_H
#define INC_4_IMOBILIARIA_H

#include "imovel.h"

class imobiliaria {
public:
   imobiliaria();

   bool acrescentar(imovel * imovel);
   bool acrescentar(imovel &imovel) { return acrescentar(&imovel); }
   bool remover(const std::string &codigo);
   std::string obterLista() const;
   std::string obterLista(int andar) const;
   std::string obterDescricao(const std::string &codigo) const;

   const imovel *getImovel(const std::string &codigo) const;

   void aumentarPrecos();
private:
   static const int MAX_IMOVES = 100;
   imovel *imoveis[MAX_IMOVES];
   int numImoveis;

   int procurarIndiceImovel(const std::string &codigo) const;
};


#endif //INC_4_IMOBILIARIA_H