#include "MSG.h"
#include <sstream>
#include <iostream>

int MSG::numero = 0;

std::string MSG::getDados() const {

    std::ostringstream buffer;
    buffer << "Letra: " << getLetra() << "\nNúmero: " << getNumero() << std::endl;

    return buffer.str();
}

MSG::MSG(char l) : letra(l) {

    numero++;
    num = numero;
    std::cout << getDados() << std::endl;
    
}

MSG::~MSG () {
    std::cout << "Finalizado...\n";
    std::cout << getDados() << std::endl;
    numero--;

}

void teste(MSG obj) {
    MSG aux = obj;
}