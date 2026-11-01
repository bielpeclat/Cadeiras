//
// Created by bielpeclat on 10/30/26.
//

#ifndef POO_F4_EX2_CLINICA_H
#define POO_F4_EX2_CLINICA_H

#include "Animal.h"

class Clinica {
    static const int MAX_ANIMAIS = 200;
    Animal *animais[MAX_ANIMAIS];
    int total = 0;

    int procura(const std::string &codigo) const; // devolver indice do animal com codigo codigo

public:
    bool regista(Animal* a);
    bool remove(const std::string &codigo);
    [[nodiscard]] const Animal* getAnimal(const std::string &codigo) const;
    [[nodiscard]] std::string getDescricao(const std::string &codigo) const;
    [[nodiscard]] std::string getListagem() const;
    void alimentaTodos();
    void exercitaTodos();
};

#endif //POO_F4_EX2_CLINICA_H