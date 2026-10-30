//
// Created by gabriel-costa on 10/29/26.
//
#include <cstdlib>
#include <sstream>
#include "Animal.h"
#include "Gato.h"

Gato::Gato(const std::string &nm, double ps, const std::string &dn, const std::string &esp) : Animal(nm, ps, dn, esp) {}

std::string Gato::come() {
   return "O que?! Patê mais uma vez?...\n";
}

std::string Gato::exercita() {

   int n_jarras = rand() % 4; // 0-3
   int m_pessoas = rand() % 5; // 0-4

   std::ostringstream oss;
   oss << "Derrubei " << n_jarras << " jarras e arranhei " << m_pessoas << " pessoas!\n";

   peso = std::max(2.5, peso*0.9);

   return oss.str();
}
