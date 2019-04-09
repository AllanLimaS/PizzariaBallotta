
#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"
#include "pizza.h"
#include "extras.h"
#include "pedido.h"
#include "menu.h"


int main()
{

    Cliente cliente[100];
    Pizza pizza[100];
    Extras extra[100];
    Pedido pedido[100];
    Funcionario funcionario[100];


    MENU(cliente, pizza, extra, pedido, funcionario);

    return 0;
}
