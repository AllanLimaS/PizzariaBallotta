#include <iostream>

using namespace std;

#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"
#include "pizza.h"
#include "extras.h"
#include "pedido.h"
#include "menu.h"

int main(int argc, char *argv[])
{

    Cliente cliente[10];
    Pizza pizza[10];
    Extras Extra[10];
    Pedido pedido[10];
    Funcionario funcionario[10];

    MENU(cliente, pizza, Extra, pedido, funcionario);








    return 0;
}
