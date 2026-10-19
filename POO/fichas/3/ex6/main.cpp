#include <iostream>
#include "MSG.h"

int main () {

    MSG a('a');
    MSG b;

    MSG& c = b; // utilização da referência

    MSG d = b;

    // MSG meuArray[2];

    // MSG meuArray[2] = {MSG('y'), MSG('z')};
    MSG meuArray[2] = {'e','f'};

    teste(b);

    std::cout << "Encerrar...\n\n";
    std::cin.get();
    
    return 0;
}

// teste