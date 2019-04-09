#include "pedido.h"
#include "cliente.h"
#include "pizza.h"
#include "extras.h"

Pedido::Pedido()
{
}

Pedido::~Pedido()
{
}

float Pedido::getPreco()
{
    return this->preco;
}

void Pedido::setPreco(float preco)
{
    this->preco = preco;
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

int Pedido :: getQtnExtras(){
    return this->qtnExtras;
}

void Pedido :: setQtnExtras(int qtnExtras){
    this->qtnExtras = qtnExtras;
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

void Pedido :: constroi_pedido(Cliente cliente, int pagamento, int entrega, int codigo, float preco){
    this->qtnPizzas = 0;                            //funcao cria o pedido e diz q ainda n pediu pizza, só iniciou o pedido
    this->cliente = cliente;                        //dps disso a funcao addPizza coloca as pizza no vetor
    this->pagamento = pagamento;
    this->entrega = entrega;
    this->codigo = codigo;
    this->preco = preco;
}

void Pedido :: addExtras(Extras extra){
    this->extras[this->qtnExtras] = extra;
    this->qtnExtras ++;
}

void Pedido :: imprime_pedido(){
    int i = 0;
    int j = 0;

     cout<<"CLIENTE: " << this->cliente.getName()<<endl;
     cout<<"\n";
    for(j=0 ;j <= this->qtnExtras ; j++){
        this->extras[j].imprime_extras();
        cout<<"\n";
    }

    if(pagamento == 1){

        cout<<"\nPAGAMENTO: Cartao" << endl;
    } else {
        cout<<"\nPAGAMENTO: Dinheiro" <<endl;
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

    }
    if(this->preco < 0){
        this->preco = 0;
    }

    cout<<"\nPRECO: " << this->preco <<" Reais "<< endl;
}
