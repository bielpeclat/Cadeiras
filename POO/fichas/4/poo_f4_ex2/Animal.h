//
// Created by gabriel-costa on 10/29/26.
//

#ifndef POO_F4_EX2_ANIMAL_H
#define POO_F4_EX2_ANIMAL_H

#include <iostream>

class Animal {

public:
   static int contador;

   Animal(const std::string &n, double p, const std::string &dn, const std::string esp);

   std::string getDescricao() const;
   virtual std::string come() = 0;
   virtual std::string exercita() = 0;

   std::string nome;
   double peso;
   std::string data_nascimento;
   std::string codigo;
   std::string especie;

};

#endif //POO_F4_EX2_ANIMAL_H