//
// Created by gabriel-costa on 10/29/26.
//

#include <sstream>
#include "Animal.h"

int Animal::contador = 1000;

Animal::Animal(const std::string &n, double p, const std::string &dn, const std::string esp) : nome(n), peso(p), data_nascimento(dn), especie(esp) { codigo = std::to_string(contador++) + "-"; }

std::string Animal::getDescricao() const {
   std::ostringstream oss;
   oss << "Nome: " << nome
       << ", Peso: " << peso
       << ", Data nasc: " << data_nascimento
       << ", Código: " << codigo
       << especie
       << std::endl;

   return oss.str();
}
