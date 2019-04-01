#include "pedido.h"
#include"cliente.h"
#include "pizza.h"
#include "extras.h"



Pedido::Pedido()
{

}

int Pedido::getPagamento()
{
    return pagamento;
}
void Pedido::setPagamento(int pagamento)
{
    this->pagamento = pagamento;
}

int Pedido::getEntrega()
{
    return this->entrega;
}
void Pedido::setEntrega(int entrega)
{
    this->entrega = entrega;
}

int Pedido::getCodigo()
{
    return this->codigo;
}
void Pedido::setCodigo(int codigo)
{
    this->codigo = codigo;
}

int Pedido::getQtnPizzas()
{
    return this->qtnPizzas;
}
void Pedido::setQtnPizzas(int qtnPizzas)
{
    this->qtnPizzas = qtnPizzas;
}

void Pedido :: add_pizza(Pizza pizza){
    this->pizza[this->qtnPizzas] = pizza;
    this->qtnPizzas = this->qtnPizzas + 1;          // poem pizza no vetor de pizza e prepara pra proxima
}

void Pedido :: constroi_pedido(Cliente cliente, class Extras extras, int pagamento, int entrega, int codigo){
    this->qtnPizzas = 0;                            //funcao cria o pedido e diz q ainda n pediu pizza, só iniciou o pedido
    this->cliente = cliente;                        //dps disso a funcao addPizza coloca as pizza no vetor
    this->Extras = extras;
    this->pagamento = pagamento;
    this->entrega = entrega;
    this->codigo = codigo;
}

void Pedido :: imprime_pedido(){
    int i = 0;
    int ch;

    cout<<"CLIENTE: " << this->cliente.getName()<<endl;
    this->Extras.imprime_extras();

    if(pagamento == 1){
        cout<<"\n";
        cout<<"PAGAMENTO: Cartao" <<endl;
    } else {
        cout<<"PAGAMENTO: Dinheiro" <<endl;
    }
    if(entrega == 1){
        cout<<"ENTREGA: MOTOBOI" <<endl;
    } else {
        cout<<"ENTREGA: RETIRADA NO LOCAL" <<endl;
    }
    cout<<"CODIGO DO CLIENTE: " << this->codigo<< endl;

    for(i=0;i<qtnPizzas;i++){
        //gotoxy(25, 20);
        cout<<endl<<"PIZZA NUMERO:"<<i+1<<endl;
        this->pizza[i].imprime_pizza();
        system("pause");

    }

}

