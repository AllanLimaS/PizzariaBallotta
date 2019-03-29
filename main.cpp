#include <QCoreApplication>
#include <iostream>

using namespace std;

#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"
#include "pizza.h"
#include "extras.h"
#include "pedido.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cliente c1;
    Pizza pizza1;
    Extras E1;
    Pedido pe1;

    c1.constroi_cliente("Jailson", "acre", "24 11 666", 42112, 666666, 2);
    pizza1.criaPizza(1,2,2);
    E1.criaExtras("Porra", "cebola");

    pe1.setPedido(c1,E1,2,2,421);
    pe1.add_pizza(pizza1);

    pe1.print_pedido();


    return a.exec();
}
