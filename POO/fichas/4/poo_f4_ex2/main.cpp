#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Animal.h"
#include "Gato.h"
#include "Cao.h"

using namespace std;

int main() {
   cout << "Programa iniciado!\n" << std::endl;

   srand(time(0));

   Gato g1("Garfield", 11, "25/02/1980", "Gato");
   cout << g1.getDescricao();
   cout << g1.come();
   cout << g1.exercita();

   cout << endl;

   Cao c1("Scooby", 7, "11/06/1999", "Cao");
   cout << c1.getDescricao();
   cout << c1.come();
   cout << c1.exercita();
   cout << c1.getDescricao();

   return 0;
}