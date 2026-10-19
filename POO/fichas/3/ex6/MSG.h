#ifndef MSG_H
#define MSG_H
#include <string>

class MSG {

    char letra;
    int num;
    
public:

    static int numero;

    MSG(char l = 'x');

    ~MSG();
    
    std::string getDados() const;
    char getLetra() const { return letra; }
    int getNumero() const { return num; }
    
};

void teste(MSG obj);

#endif