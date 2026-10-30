//
// Created by gabriel-costa on 10/29/26.
//

#ifndef POO_F4_EX2_CAO_H
#define POO_F4_EX2_CAO_H

#include "Animal.h"

class Cao : public Animal {
public:
   Cao(const std::string &nm, double ps, const std::string &dn, const std::string &esp);

   std::string come() override;
   std::string exercita() override;
};

#endif //POO_F4_EX2_CAO_H