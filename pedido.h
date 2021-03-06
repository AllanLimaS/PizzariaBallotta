#ifndef PEDIDO_H
#define PEDIDO_H
#include <windows.h>
#include <iostream>
#include "cliente.h"
#include "pizza.h"
#include "extras.h"

using namespace std;

class Pedido
{
private:
    Cliente cliente;
    Pizza pizza[100];
    Extras extras[100];
    int pagamento;
    int entrega;
    int codigo;
    int qtnPizzas;                  //aqui add 1 cada vez q add uma pizza, pra saber a posicao no vetor
    int qtnExtras;
    float preco;

public:
    Pedido();
    ~Pedido();
    void constroi_pedido(Cliente cliente,int pagamento,int entrega, int codigo, float preco);
    void add_pizza(Pizza pizza);
    void imprime_pedido();

    int getPagamento();
    void setPagamento(int pagamento);
    int getEntrega();
    void setEntrega(int entrega);
    int getCodigo();
    void setCodigo(int codigo);
    int getQtnPizzas();
    void setQtnPizzas(int qtnPizzas);
    void addExtras(Extras extra);
    void setQtnExtras(int qtnExtras);
    int getQtnExtras();
    float getPreco() ;
    void setPreco(float value);
};

#endif // PEDIDO_H
