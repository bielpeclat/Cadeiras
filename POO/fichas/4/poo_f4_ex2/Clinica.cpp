//
// Created by bielpeclat on 10/30/26.
//

#include <iostream>
#include <sstream>
#include "Clinica.h"

int Clinica::procura(const std::string &codigo) const {
    int i;

    for (i = 0; i < total; i++) {
        if (animais[i]->getCodigo() == codigo) {
            return i;
        }
    }

    return -1;

}

bool Clinica::regista(Animal* a) {
    if (a == nullptr) return false; // o ponteiro é nulo
    if (procura(a->getCodigo()) != -1) return false; // ela já existe
    if (total == MAX_ANIMAIS) return false; // não há espaço

    animais[total] = a;
    total++;
    return true;
}

bool Clinica::remove(const std::string &codigo) {
    int idx = procura(codigo);
    if (idx == -1) return false; // o codigo nao existe no array

    for (int i = idx; i < total - 1; i++) {
        animais[i] = animais[i+1];
    }
    total--;
    return true;
}

const Animal* Clinica::getAnimal(const std::string &codigo) const {
    int idx = procura(codigo);
    if (idx == -1) return nullptr;

    return animais[idx];
}

std::string Clinica::getDescricao(const std::string &codigo) const {
    int idx = procura(codigo);
    if (idx == -1) return "";

    return animais[idx]->getDescricao();
}

std::string Clinica::getListagem() const {
    if (total == 0) return "A clínica está vazia!\n";

    std::ostringstream oss;

    oss << "\n---INÍCIO LISTAGEM---\n";

    for (int i = 0; i < total; i++) {
        oss << animais[i]->getDescricao();
    }

    oss << "---FIM LISTAGEM---\n";

    return oss.str();
}

void Clinica::alimentaTodos() {

    for (int i = 0; i < total; i++) {
        std::cout << animais[i]->come();
    }
}

void Clinica::exercitaTodos() {
    if (total == 0) return;

    for (int i = 0; i < total; i++) {
        std::cout << animais[i]->exercita();
    }
}