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

    string nome, endereco,dataNasc;
    int cpf,codigo,pontuacao;

    cout<<"digite seu nome   ";
    cin>>nome;
    cout<<"digite seu ender   ";
    cin>>endereco;
    cout<<"digite seu data   ";
    cin>>dataNasc;
    cout<<"digite seu cpf   ";
    cin>>cpf;
    cout<<"digite seu codigoe   ";
    cin>>codigo;
    cout<<"digite seu potn   ";
    cin>>pontuacao;

    c1.constroi_cliente(nome,endereco,dataNasc,cpf,codigo,pontuacao);
    c1.imprime_cliente();


    /*
    c1.constroi_cliente("Jailson", "acre", "24 11 666", 42112, 666666, 2);
    pizza1.constroi_pizza(1,2,2);
    E1.constroi_extras("", "cebola");

    pe1.constroi_pedido(c1,E1,2,2,421);
    pe1.add_pizza(pizza1);

    pe1.imprime_pedido();
*/
    return a.exec();
}
