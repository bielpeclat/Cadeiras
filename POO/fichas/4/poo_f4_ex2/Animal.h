//
// Created by gabriel-costa on 10/29/26.
//

#ifndef POO_F4_EX2_ANIMAL_H
#define POO_F4_EX2_ANIMAL_H

#include <iostream>
#include <string>

class Animal {

public:
   std::string getNome() const;
   std::string getDataNasc() const;
   double getPeso() const;
   std::string getEspecie() const;
   std::string getCodigo() const;
   std::string getDescricao() const;

   virtual std::string come() = 0;
   virtual std::string exercita() = 0;

private:
   static int contador;

   std::string nome;
   double peso;
   std::string data_nascimento;
   std::string codigo;
   std::string especie;

protected:
   Animal(const std::string &n, double p, const std::string &dn, const std::string esp);
   void setPeso(double peso);
};

#endif //POO_F4_EX2_ANIMAL_H