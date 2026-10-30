//
// Created by gabriel-costa on 10/22/26.
//

#ifndef INC_4_APARTAMENTO_H
#define INC_4_APARTAMENTO_H

#include "imovel.h"

class apartamento : public imovel { // ver o que aconteceria se nao tivesse o public
public:
   apartamento(double area, int andar, int assoalhadas);

   int obterAssoalhadas() const noexcept { return assoalhadas; }
   std::string obterDescricao() const override;

protected:
   double getPercentagemAumento() const;

private:
   int assoalhadas;
};


#endif //INC_4_APARTAMENTO_H