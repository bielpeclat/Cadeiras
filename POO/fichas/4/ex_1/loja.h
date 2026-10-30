//
// Created by gabriel-costa on 10/22/26.
//

#ifndef INC_4_LOJA_H
#define INC_4_LOJA_H

#include <sstream>
#include "imovel.h"

using namespace std;

class loja : public imovel {
public:
   loja(double area);

   std::string obterDescricao() const override;

protected:
   double getPercentagemAumento() const;
private:
};


#endif //INC_4_LOJA_H