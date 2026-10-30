//
// Created by gabriel-costa on 10/29/26.
//

#include <sstream>
#include <cstdlib>
#include "Cao.h"

Cao::Cao(const std::string &nm, double ps, const std::string &dn, const std::string &esp) : Animal(nm, ps, dn, esp) {}

std::string Cao::come() {
   peso = std::min(20.0, peso*1.05);
   return "Biscoitos bons, obrigado! Au au\n";
}

std::string Cao::exercita() {
   int x_km = (rand() % 5 - 1) + 1;

   std::ostringstream oss;
   oss << "Corri " << x_km << " km!\n";

   return oss.str();
}
