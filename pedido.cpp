#include "pedido.h"
#include"cliente.h"
#include "pizza.h"
#include "extras.h"

Pedido::Pedido()
{

}

void Pedido :: add_pizza(Pizza pizza){
    this->pizza[this->qtnPizzas] = pizza;
    this->qtnPizzas = this->qtnPizzas + 1; // poem pizza no vetor de pizza e prepara pra proxima
}


void Pedido :: setPedido(Cliente cliente, class Extras extras, int pagamento, int entrega, int codigo){
    this->qtnPizzas = 0;    //funcao cria o pedido e diz q ainda n pediu pizza, só iniciou o pedido
    this->cliente = cliente;//dps disso a funcao addPizza coloca as pizza no vetor
    this->Extras = extras;
    this->pagamento = pagamento;
    this->entrega = entrega;
    this->codigo = codigo;
}

void Pedido :: print_pedido(){
    cout<<"CLIENTE: " << this->cliente.getName()<<endl;
    this->Extras.printExtras();
    this->pizza->printPizza();
    cout<<"PAGAMENTO: " << this->pagamento << endl << "ENTREGA: " << this->entrega << endl << "CODIGO: " << this->codigo<< endl;

}

