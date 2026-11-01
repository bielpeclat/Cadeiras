#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Animal.h"
#include "Gato.h"
#include "Cao.h"
#include "Clinica.h"

using namespace std;

int main() {
   cout << "Programa iniciado!\n" << std::endl;

   srand(time(0));

   Gato g1("Garfield", 11, "25/02/1980");
   cout << g1.getDescricao();
   cout << g1.come();
   cout << g1.exercita();
   cout << g1.getDescricao();

   cout << endl;

   Cao c1("Scooby", 7, "11/06/1999");
   cout << c1.getDescricao();
   cout << c1.come();
   cout << c1.exercita();
   cout << c1.getDescricao();

   cout << "\nJá definimos os animais, vamos declarar a clinica!\n\n";

   Clinica clinica;
   clinica.regista(&g1);
   clinica.regista(&c1);

   cout << clinica.getListagem();
   clinica.alimentaTodos();
   clinica.exercitaTodos();
   cout << clinica.getListagem();

   const Animal* a = clinica.getAnimal("1000-Gato");
   if (a != nullptr) {
      cout << a->getPeso() << endl;
   }

   clinica.remove("1000-Gato");
   cout << clinica.getListagem();

   return 0;
}