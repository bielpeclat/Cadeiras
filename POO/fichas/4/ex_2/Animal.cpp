//
// Created by gabriel-costa on 10/29/26.
//

#include <sstream>
#include "Animal.h"

int Animal::contador = 1000;

Animal::Animal(const std::string &n, double p, const std::string &dn, const std::string esp) : nome(n), peso(p), data_nascimento(dn), especie(esp) {
    codigo = std::to_string(contador++) + "-" + especie;
    if (peso <= 0) peso = 1;
}

std::string Animal::getNome() const {
    return nome;
}

std::string Animal::getDataNasc() const {
    return data_nascimento;
}

std::string Animal::getEspecie() const {
    return especie;
}

double Animal::getPeso() const {
    return peso;
}

void Animal::setPeso(double p) {
    if (p <= 0) {
        peso = 1;
        return;
    }
    peso = p;
}

std::string Animal::getCodigo() const {
    return codigo;
}

std::string Animal::getDescricao() const {
   std::ostringstream oss;
   oss << "Nome: " << nome
       << ", Peso: " << peso
       << ", Data nasc: " << data_nascimento
       << ", Código: " << codigo
       << std::endl;

   return oss.str();
}
