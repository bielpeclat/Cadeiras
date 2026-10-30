#include <iostream>
#include "imovel.h"
#include "apartamento.h"
#include "loja.h"
#include "imobiliaria.h"

using namespace std;

int main() {
   cout << "Hello, World!" << endl;
   // imovel i1;
   apartamento a1(90, 3, 3);
   loja l1(45);

   cout << a1.obterDescricao() << endl;
   cout << l1.obterDescricao() << endl;

   a1.aumentarPreco();
   l1.aumentarPreco();

   imovel * pi1 = &a1;
   imovel * pi2 = &l1;
   // apartamento * pa1 = &i1; -> erro

   cout << pi1->obterDescricao() << endl;
   cout << pi2->obterDescricao() << endl;

   imobiliaria imob;
   cout << boolalpha <<imob.acrescentar(a1) << endl;
   cout << imob.acrescentar(pi1) << endl;
   cout << imob.acrescentar(&l1) << endl;

   cout << imob.obterLista() << endl;
   cout << imob.obterLista(0) << endl;
   imob.remover("apartamento1");
   imob.aumentarPrecos();
   cout << imob.obterLista() << endl;

   const imovel * z = imob.getImovel("loja2");
   // nao é possivel usar aumentarPreco() pq não é const!!!

   // precisamos impedir a criacao de imoveis isolados.

   return 0;
}