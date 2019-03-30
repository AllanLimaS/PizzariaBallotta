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

int ADD_PEDIDO(int pedido_posi,int posicao, Pedido *pedido, Cliente *cliente, Pizza *pizza,  Extras *extra ){
    int sabor;
    int borda;
    int tamanho;
    int i = 0;
    int codigo;
    string bebida;
    string adicionais;
    int pagamento;
    int qntPizzas;


    clrscr();
    cout<<"\nQUANTOS CLIENTES QUE PODEM COMER: "<< posicao <<endl;

    for (i=0;i<posicao;i++){
        cout<<"\n\n";
        cout<<"nome: "<< cliente[i].getName()<< endl << "codigo: " << cliente[i].getCodigo()<< endl;
    }

    cout<<"DIGITE O CODIGO DO PUTO QUE QUER COMER:  ";
    cin>> codigo;

    for (i=0;i<posicao;i++){
        if (codigo == cliente[i].getCodigo()){
            cout<<"puto selecionado"<<endl;
            system("pause");

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA pagamento(int): ";
            cin>>pagamento;


            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA ADICIONAIS(STRING): ";
            cin>>adicionais;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA A BEBIDA(STRING): ";
            cin>>bebida;

            extra->constroi_extras(bebida,adicionais);

            pedido[pedido_posi].constroi_pedido(*cliente,*extra,pagamento,1,codigo);
            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA O TAMANHO DA PIZZA: ";
            cin>>tamanho;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA A BORDA DA PIZZA: ";
            cin>>borda;

            clrscr();
            gotoxy(30,8);
            cout<<"ESCOLHA O SABOR DA PIZZA: ";
            cin>>sabor;

            pizza->constroi_pizza(sabor,borda,tamanho);
            pedido[pedido_posi].add_pizza(*pizza);
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

void MENU(Cliente *cliente, Pizza *pizza, Extras *extra, Pedido *pedido){
    int pizza_posi = 0, cliente_posi = 0, pedido_posi = 0;// guarda a posicao do vetor
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

        ch = getch();

        switch(ch){
        case '0':
            cliente_posi = ADD_CLIENTE(cliente_posi,cliente);
            break;
        case '2':
            VER_CLIENTES(cliente,cliente_posi);

        case '1':
            if (cliente_posi>0){
                pedido_posi = ADD_PEDIDO(pedido_posi,cliente_posi,pedido,cliente,pizza,extra);
                break;
            }
        case 27:
            exit(EXIT_SUCCESS);
        }


    }

}

#endif // MENU_H
