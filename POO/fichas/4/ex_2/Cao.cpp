//
// Created by gabriel-costa on 10/29/26.
//

#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "Cao.h"


Cao::Cao(const std::string &nm, double ps, const std::string &dn) : Animal(nm, ps, dn, "Cao") {}

std::string Cao::come() {
   double peso = std::min(20.0, getPeso()*1.05);
   setPeso(peso);

   return "Biscoitos bons, obrigado! Au au\n";
}

std::string Cao::exercita() {
   int x_km = (rand() % 5) +1; // tem que ser entre 1 e 5

   std::ostringstream oss;
   oss << "Corri " << x_km << " km!\n";

   return oss.str();
}
