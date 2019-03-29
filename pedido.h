#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
using namespace std;
#include "cliente.h"
#include "pizza.h"
#include "extras.h"


class Pedido
{

private:
    Cliente cliente;
    Pizza pizza[10];
    class Extras Extras;
    int pagamento, entrega,codigo;
    int qtnPizzas;//aqui add 1 cada vez q add uma pizza, pra saber a posicao no vetor

public:
    Pedido();
    void setPedido(Cliente cliente,class Extras extras,int pagamento,int entrega, int codigo);
    void add_pizza(Pizza pizza);
    void print_pedido();
};

#endif // PEDIDO_H
