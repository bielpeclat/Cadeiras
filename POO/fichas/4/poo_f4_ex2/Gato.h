//
// Created by gabriel-costa on 10/29/26.
//

#ifndef POO_F4_EX2_GATO_H
#define POO_F4_EX2_GATO_H

#include "Animal.h"

class Gato : public Animal {
public:
   Gato(const std::string &nm, double ps, const std::string &dn, const std::string &esp);

   std::string come() override;
   std::string exercita() override;
};


#endif //POO_F4_EX2_GATO_H