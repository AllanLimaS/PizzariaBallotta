#ifndef MENU_H
#define MENU_H
#include "codefun.h"
#include <windows.h>
#include <iostream>
using namespace std;
#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"
#include "pizza.h"
#include "extras.h"
#include "pedido.h"
#include <conio.h>

int ADD_CLIENTE(int cliente_posi, Cliente *cliente){
    string name;
    string endereco;
    string dataNasc;
    int cpf;
    int codigo;
    int pontuacao;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA O NOME: ";
    cin>>name;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA O ENDERECO: ";
    cin>>endereco;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA A DATA DE NASC: ";
    cin>>dataNasc;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA CPF: ";
    cin>>cpf;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA COD: ";
    cin>>codigo;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA PONTUACAO: ";
    cin>>pontuacao;

    cliente[cliente_posi].constroi_cliente(name,endereco,dataNasc,cpf,codigo,pontuacao);
    cliente_posi++;
    return cliente_posi;

}

int ADD_FUNCIONARIO(int funcionario_posi, Funcionario *funcionario){
    string name;
    string endereco;
    string dataNasc;
    int cpf;
    int codigo;
    string funcao;
    float salario;


    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA O NOME: ";
    cin>>name;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA O ENDERECO: ";
    cin>>endereco;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA A DATA DE NASC: ";
    cin>>dataNasc;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA CPF: ";
    cin>>cpf;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA COD: ";
    cin>>codigo;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA FUNCAO: ";
    cin>>funcao;

    clrscr();
    gotoxy(30,8);
    cout<<"INSIRA SALARIO: ";
    cin>>salario;

    funcionario[funcionario_posi].constroi_funcionario(name,endereco,dataNasc,cpf,codigo,salario,funcao);
    funcionario_posi++;
    return funcionario_posi;

}

int ADD_PEDIDO(int pedido_posi,int posicao, Pedido *pedido, Cliente *cliente, Pizza *pizza, Extras *extra ){
    int sabor;
    int borda;
    int tamanho;
    int i = 0;
    int j = 0;
    int codigo;
    int bebida;
    int adicionais;
    int pagamento;
    int entrega;
    int qntPizzas;

    clrscr();
    cout<<"\nQUANTOS CLIENTES QUE PODEM COMER: "<< posicao <<endl;

    for (i=0;i<posicao;i++){
        cout<<"\n\n";
        cout<<"nome: "<< cliente[i].getName()<< endl << "codigo: " << cliente[i].getCodigo()<< endl;
    }

    cout<<"DIGITE O CODIGO DO PUTO QUE QUER COMER: ";
    cin>> codigo;

    for (i=0;i<posicao;i++){
        if (codigo == cliente[i].getCodigo()){
            cout<<"puto selecionado"<<endl;
            system("pause");

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA PAGAMENTO: ";
            gotoxy(30,10);
            cout<<"1 - Cartao";
            gotoxy(30,12);
            cout<<"2 - Dinheiro";
            gotoxy(30, 14);
            cout<<"Sua escolha: ";
            cin>>pagamento;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA ENTREGA: ";
            gotoxy(30,10);
            cout<<"1 - motoBOI";
            gotoxy(30,12);
            cout<<"2 - retirada no balcao";
            gotoxy(30, 14);
            cout<<"Sua escolha: ";
            cin>>entrega;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA ADICIONAIS";
            gotoxy(30, 10);
            cout<<"1 - Cebola";
            gotoxy(30, 11);
            cout<<"2 - Bacon";
            gotoxy(30, 12);
            cout<<"3 - Condimentos Extra";
            gotoxy(30, 13);
            cout<<"4 - Azeitonas";
            gotoxy(30, 14);
            cout<<"5 - Queijo";
            gotoxy(30, 16);
            cout<<"Sua escolha: ";
            cin>>adicionais;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA A BEBIDA";
            gotoxy(30, 10);
            cout<<"1 - Skol";
            gotoxy(30, 11);
            cout<<"2 - Coca Cola";
            gotoxy(30, 12);
            cout<<"3 - Cachaca";
            gotoxy(30, 13);
            cout<<"4 - Vodka";
            gotoxy(30, 14);
            cout<<"5 - Suquinho";
            gotoxy(30, 16);
            cout<<"Sua escolha: ";
            cin>>bebida;

            extra->constroi_extras(bebida,adicionais);

            pedido[pedido_posi].constroi_pedido(*cliente,*extra,pagamento,entrega,codigo);

            clrscr();
            gotoxy(30,10);
            cout<<"DIGITE A QUANTIDADE DE PIZZAS: ";
            cin>>qntPizzas;
            for(j=0;j<qntPizzas;j++){

                clrscr();
                gotoxy(30,8);
                cout<<"ESCOLHA O TAMANHO DA PIZZA: ";
                gotoxy(30,10);
                cout<<"1 - Broto";
                gotoxy(30, 12);
                cout<<"2 - Media";
                gotoxy(30,14);
                cout<<"3 - Grande";
                gotoxy(30, 16);
                cout<<"Sua escolha: ";
                cin>>tamanho;

                clrscr();
                gotoxy(30,8);
                cout<<"ESCOLHA A BORDA DA PIZZA: ";
                gotoxy(30, 10);
                cout<<"1 - Catupiry";
                gotoxy(30, 12);
                cout<<"2 - Cheddar";
                gotoxy(30,14);
                cout<<"3 - Chocolate";
                gotoxy(30, 16);
                cout <<"4 - Normal";
                gotoxy(30, 18);
                cout<<"Sua escolha: ";
                cin>>borda;

                clrscr();
                gotoxy(30,8);
                cout<<"ESCOLHA O SABOR DA PIZZA: ";
                gotoxy(30, 10);
                cout<<"1 - Calabresa";
                gotoxy(30, 11);
                cout<<"2 - Peito de peru";
                gotoxy(30, 12);
                cout<<"3 - Frango com catupiry";
                gotoxy(30, 13);
                cout<<"4 - Frango com batata doce";
                gotoxy(30,14);
                cout<<"5 - 4 Queijos";
                gotoxy(30, 15);
                cout<<"6 - Coracao";
                gotoxy(30, 16);
                cout<<"7 - Abacaxi";
                gotoxy(30, 17);
                cout<<"8 - Portuguesa";
                gotoxy(30, 18);
                cout<<"9 - Bacon";
                gotoxy(30, 19);
                cout<<"10 - Strogonof de carne";
                gotoxy(30, 21);
                cout<<"Sua escolha: ";
                cin>>sabor;

                pizza[j].constroi_pizza(sabor,borda,tamanho);
                pedido[pedido_posi].add_pizza(pizza[j]);
        }
            clrscr();
            pedido[pedido_posi].imprime_pedido();
        }
    }
    system("pause");
}

void VER_CLIENTES(Cliente *cliente,int posicao){
    int i = 0;

    clrscr();
    cout<<"\nCLIENTES CADASTRADOS: "<< posicao <<endl;

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        cliente[i].imprime_cliente();
    }
    system("pause");

}

void VER_FUNCIONARIOS(Funcionario *funcionario,int posicao){
    int i = 0;

    clrscr();
    cout<<"\nFUNCIONARIOS CADASTRADOS: "<< posicao <<endl;

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        funcionario[i].imprime_funcionario();
    }
    system("pause");

}

void MENU(Cliente *cliente, Pizza *pizza, Extras *extra, Pedido *pedido, Funcionario *funcionario){
    int pizza_posi = 0, cliente_posi = 0, pedido_posi = 0, funcionario_posi = 0;// guarda a posicao do vetor
    char ch;
    clrscr();
    system("mode con: cols=80 lines=40");

    while(true){
        clrscr();
        gotoxy(30,5);
        cout<<"PIZZARIA MERDA";
        gotoxy(30,8);
        cout<<"[0]ADD CLIENTE";
        if (cliente_posi >0){
            gotoxy(30,10);
            cout<<"[1]ADD PEDIDO";
        }
        gotoxy(30,12);
        cout<<"[2]VER CLIENTES";
        gotoxy(30, 14);
        cout<<"[3]ADCIONAR FUNCIONARIO";
        gotoxy(30, 16);
        cout<<"[4]VER FUNCIONARIOS";

        ch = getch();

        switch(ch){
        case '0':
            cliente_posi = ADD_CLIENTE(cliente_posi,cliente);
            break;
        case '2':
            VER_CLIENTES(cliente,cliente_posi);
            break;

        case '1':
            if (cliente_posi>0){
                pedido_posi = ADD_PEDIDO(pedido_posi,cliente_posi,pedido,cliente,pizza,extra);
                break;
            }
        case '3':
            funcionario_posi = ADD_FUNCIONARIO(funcionario_posi, funcionario);
            break;
        case '4':
            VER_FUNCIONARIOS(funcionario, funcionario_posi);
            break;
        case 27:
            exit(EXIT_SUCCESS);
        }


    }

}

#endif // MENU_H
