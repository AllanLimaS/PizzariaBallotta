#ifndef MENU_H
#define MENU_H
#include <windows.h>
#include <iostream>
#include "codefun.h"
#include <conio.h>

using namespace std;

#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"
#include "pizza.h"
#include "extras.h"
#include "pedido.h"

int ADD_CLIENTE(int cliente_posi, Cliente *cliente){
    string name;
    string endereco;
    string dataNasc;
    string cpf;
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

    codigo = cliente_posi + 1;

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
    string cpf;
    int codigo;
    int funcao;
    float salario;

    int cond = 0; // VARIAVEL DE CONTROLE DE WHILE


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

    codigo = funcionario_posi + 1;

    while(cond == 0){
    clrscr();
    gotoxy(30,8);
    cout<<"FUNCAO";
    gotoxy(30, 10);
    cout<<"0 - Atendente";
    gotoxy(30, 11);
    cout<<"1 - Pizzaiolo";
    gotoxy(30, 12);
    cout<<"2 - Motoboi";
    gotoxy(30, 13);
    cout<<"3 - Gerente";
    gotoxy(30, 15);
    cout<<"Sua escolha: ";
    cin>>funcao;

    if(funcao <0 or funcao > 3){
    clrscr();
    gotoxy(30, 20);
    cout<<"INVALIDO";
    Sleep(1000);
    }else{
    cond = 1;
    }
}

switch(funcao){

case 00:
salario = 1050.00;
break;
case 01:
salario = 1850.50;
break;
case 02:
salario = 1000.40;
break;
case 03:
salario = 2573.87;
break;
}


funcionario[funcionario_posi].constroi_funcionario(name,endereco,dataNasc,cpf,codigo,salario,funcao);
funcionario_posi++;
return funcionario_posi;

}

int ADD_PEDIDO(int pedido_posi,int posicao, Pedido *pedido, Cliente *cliente, Pizza *pizza, Extras *extra ){
    int sabor = 0;
    int borda = 0;
    int tamanho = 0;
    int i = 0;
    int j = 0;
    int cond = 0; // USUARIO IDIOTA
    int codigo = 0;
    int bebida = 0;
    int adicionais = 0;
    int pagamento = 0;
    int entrega = 0;
    int qntPizzas = 0;
    int posiExtras = 0;
    Extras extra_temp;
    bool fazerExtras;
    char ch;
    float preco = 0.00; // preço do pedido


    clrscr();
    cout<<"\nQUANTOS CLIENTES QUE PODEM COMER: "<< posicao <<endl;

    for (i=0;i<posicao;i++){
        cout<<"\n\n";
        cout<<"Nome: "<< cliente[i].getName()<< endl << "Codigo: " << cliente[i].getCodigo()<< endl;
    }
    gotoxy(30,8);
    cout<<"DIGITE O CODIGO DO PUTO QUE QUER COMER: ";
    cin>> codigo;

    for (i=0;i<posicao;i++){
        if (codigo == cliente[i].getCodigo()){
            clrscr();
            gotoxy(30,10);
            cout<<"PUTO SELECIONADO"<<endl;
            gotoxy(30, 15);
            cout<<"Nome: "<< cliente[i].getName();
            gotoxy(30, 16);
            cout<<"Codigo: " << cliente[i].getCodigo();

            Sleep(1000);

            while(cond == 0){
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
                if(pagamento != 1 && pagamento != 2){
                    clrscr();
                    gotoxy(25, 40);
                    cout << "O BURRO DO KRL SABE LER N";
                    Sleep(1000);
                } else {
                    cond = 1;
                }
            }

            cond = 0; // REDEFINE COND PARA OS WHILE FICAR BUNITO

            while(cond == 0){
                clrscr();
                gotoxy(30,8);
                cout<<"ESCOLHA ENTREGA: ";
                gotoxy(30,10);
                cout<<"1 - Motoboy (TAXA DE ENTREGA 10.00)";
                gotoxy(30,12);
                cout<<"2 - retirada no balcao";
                gotoxy(30, 14);
                cout<<"Sua escolha: ";
                cin>>entrega;
                if(entrega != 1 && entrega != 2){
                    clrscr();
                    gotoxy(25, 20);
                    cout << "O BURRO DO KRL SABE LER N";
                    Sleep(1000);
                } else {
                    cond = 1;
                }
            }

            if(entrega == 1){           //PREÇO DA ENTREGA
                preco = preco + 10.00;
            }

            cond = 0; // REDEFINE COND PARA OS WHILE FICAR BUNITO
            pedido[pedido_posi].constroi_pedido(cliente[i],pagamento,entrega,codigo, preco);

            fazerExtras = TRUE;
            pedido->setQtnExtras(0);
            while(fazerExtras == TRUE){

                while(cond == 0){
                    clrscr();
                    gotoxy(30,8);
                    cout<<"ESCOLHA ADICIONAIS";
                    gotoxy(30, 10);
                    cout<<"0 - Nada";
                    gotoxy(30, 11);
                    cout<<"1 - Cebola (2.00)";
                    gotoxy(30, 12);
                    cout<<"2 - Bacon(3.00)";
                    gotoxy(30, 13);
                    cout<<"3 - Condimentos Extra";
                    gotoxy(30, 14);
                    cout<<"4 - Azeitonas(2.00)";
                    gotoxy(30, 15);
                    cout<<"5 - Queijo(3.00)";
                    gotoxy(30, 17);
                    cout<<"Sua escolha: ";
                    cin>>adicionais;
                    if(adicionais <0 or adicionais >5){
                        clrscr();
                        gotoxy(25, 20);
                        cout << "O BURRO DO KRL SABE LER N";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (adicionais) {
                case 0:
                    preco= preco;
                    break;
                case 1:
                    preco= preco + 2.00;
                    break;
                case 2:
                    preco = preco + 3.00;
                    break;
                case 3:
                    preco = preco;
                    break;
                case 4:
                    preco = preco + 2.00;
                    break;
                case 5:
                    preco = preco + 3.00;
                    break;

                }

                cond = 0;

                while(cond == 0){
                    clrscr();
                    gotoxy(30,8);
                    cout<<"ESCOLHA A BEBIDA";
                    gotoxy(30, 10);
                    cout<<"0 - Nada";
                    gotoxy(30, 11);
                    cout<<"1 - Skol (4.50)";
                    gotoxy(30, 12);
                    cout<<"2 - Coca Cola 2l (10.00)";
                    gotoxy(30, 13);
                    cout<<"3 - Cachaca (12.50)";
                    gotoxy(30, 14);
                    cout<<"4 - Vodka (20.00)";
                    gotoxy(30, 15);
                    cout<<"5 - Suquinho (8.50)";
                    gotoxy(30, 17);
                    cout<<"Sua escolha: ";
                    cin>>bebida;
                    if(bebida <0 or bebida >5){
                        clrscr();
                        gotoxy(25, 20);
                        cout << "O BURRO DO KRL SABE LER N";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (bebida) {
                case 0:
                    preco= preco;
                    break;
                case 1:
                    preco= preco + 4.50;
                    break;
                case 2:
                    preco = preco + 10.00;
                    break;
                case 3:
                    preco = preco + 12.50;
                    break;
                case 4:
                    preco = preco + 20.00;
                    break;
                case 5:
                    preco = preco + 8.50;
                    break;

                }

                cond = 0;
                extra_temp.setBebida(0);
                extra_temp.setAdicionais(0);

                extra_temp.constroi_extras(bebida,adicionais);
                pedido[pedido_posi].addExtras(extra_temp);

                clrscr();
                cout<<pedido[pedido_posi].getQtnExtras()<<endl<<pedido_posi;
                gotoxy(20, 13);
                cout<<"ADICIONAR MAIS EXTRAS?  [y]sim  [n]nao";
                ch = 00;
                ch = getch();
                switch (ch) {
                case 'y':

                    break;
                case 'n':
                    fazerExtras = FALSE;
                    break;
                }


            }


            clrscr();
            gotoxy(25,10);
            cout<<"DIGITE A QUANTIDADE DE PIZZAS: ";
            cin>>qntPizzas;
            for(j=0;j<qntPizzas;j++){

                while(cond == 0){
                    clrscr();
                    gotoxy(30,8);
                    cout<<"ESCOLHA O TAMANHO DA PIZZA: ";
                    gotoxy(30,10);
                    cout<<"1 - Broto (25.00)";
                    gotoxy(30, 12);
                    cout<<"2 - Media (35.00)";
                    gotoxy(30,14);
                    cout<<"3 - Grande (45.00)";
                    gotoxy(30, 16);
                    cout<<"Sua escolha: ";
                    cin>>tamanho;
                    if(tamanho < 1 or tamanho > 3){
                        clrscr();
                        gotoxy(25, 20);
                        cout << "O BURRO DO KRL SABE LER N";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (tamanho) {

                case 1:
                    preco= preco + 25.00;
                    break;
                case 2:
                    preco = preco + 35.00;
                    break;
                case 3:
                    preco = preco + 45.00;
                    break;


                }

                cond = 0;

                while(cond == 0){
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
                    cout<<"Com borda 7.50 de acrescimo";
                    gotoxy(30, 20);
                    cout<<"Sua escolha: ";
                    cin>>borda;
                    if(borda < 1 or borda > 4){
                        clrscr();
                        gotoxy(25, 20);
                        cout << "O BURRO DO KRL SABE LER N";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                if(borda != 4){
                    preco = preco + 7.50;
                }

                cond = 0;

                while(cond == 0){
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
                    if(sabor < 1 or sabor > 10){
                        clrscr();
                        gotoxy(25, 20);
                        cout << "O BURRO DO KRL SABE LER N";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                cond = 0;
                pizza[j].constroi_pizza(sabor,borda,tamanho);
                pedido[pedido_posi].add_pizza(pizza[j]);
        }
            clrscr();
            pedido[pedido_posi].setPreco(preco);
            pedido[pedido_posi].imprime_pedido();
        }
    }
    pedido_posi++;
    system("pause");
    return pedido_posi;
}

int ADD_CLIENTES_PADROES(int cliente_posi, Cliente *cliente){
    cliente[cliente_posi].constroi_cliente("Allan a lima","Mario","19/06/2000","122.975.909-38",1,2424);
    cliente_posi++;
    cliente[cliente_posi].constroi_cliente("GuxXxtavo","BruxXxque","nasceu ontem inocente","777.777.777-77",2,6969);
    cliente_posi++;
    cliente[cliente_posi].constroi_cliente("Koguto","bC","200AC","987.654.321-00",3,0);
    cliente_posi++;

    clrscr();
    gotoxy(30,8);
    cout<<"COTOCOS ADICIONADOS COM SUCESSO"<<endl<<endl;
    Sleep(1500);

    return cliente_posi;

}

void VER_CLIENTES(Cliente *cliente,int posicao){
    int i = 0;
    int ativos = 0;

    clrscr();

    for(i =0; i < posicao ; i++){
        if(cliente[i].get_ativo() == true){
            ativos++;
        }
    }


    cout<<"\nCLIENTES CADASTRADOS: "<< posicao <<endl;
    cout<<"\nCLIENTES ATIVOS: "<< ativos<<endl;

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        cliente[i].imprime_cliente();
    }
    system("pause");

}

void VER_PEDIDOS(int pedido_posi,Pedido *pedido){
    int i = 0;

    boolean sair = FALSE;
    clrscr();
    cout<<"PEDIDOS FEITOS: "<<pedido_posi<<endl;

    while(sair==FALSE){
        clrscr();
        cout<<endl<<"--------------------------PEDIDO "<<i + 1<<"--------------------------"<<endl;
        pedido[i].imprime_pedido();
        cout<<endl<<"--------------------------PEDIDO "<<i + 1<<"--------------------------"<<endl;
        cout<<"[a]pedido anterior"<<endl<<"[d] proximo pedido"<<endl<<"[esc] para sai"<<endl;

        switch(getch()){

        case 'a':
            if (i==0){
                cout<<endl<<"nao ha pedido anterior a este";
                Sleep(1000);
            }else{
                i--;
            }
            break;

        case 'd':
            if(i==pedido_posi-1){
                cout<<endl<<"nao ha pedido apos este";
                Sleep(1000);
            }else{
                i++;
            }
            break;

        case 27:
            sair = TRUE;
            break;

        default:
            break;
        }
    }
}

void VER_FUNCIONARIOS(Funcionario *funcionario,int posicao){
    int i = 0, falsos = 0;

    clrscr();
    cout<<"\nFUNCIONARIOS CADASTRADOS: "<< posicao <<endl;
    for(i=0;i < posicao;i++){
        if(funcionario[i].get_ativo() == false){
            falsos++;
        }
    }
    cout<<"\n\nDEMITIDOS: " << falsos << "\n\n";

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        funcionario[i].imprime_funcionario();
    }

    system("pause");

}

void remove_cliente(Cliente *cliente, int quantidade){
    clrscr();
    cout<<"\nCLIENTES"<<endl;
    int codigo, i;


    for (i=0;i<quantidade;i++){
        cout<<"\n";
        if(cliente[i].get_ativo() == true){
            cout<<"Nome: "<< cliente[i].getName()<< endl << "NUMERO: " << i<< endl;
        }
    }

    gotoxy(40,10);
    cout<<"SELECIONE O NUMERO: ";
    cin>>codigo;

    cliente[codigo].set_ativo(false);

}

void remove_funcionario(Funcionario *funcionarios, int quantidade){
    clrscr();
    cout<<"\nFUNCIONARIOS: "<<endl;
    int codigo, i;


    for (i=0;i<quantidade;i++){
        cout<<"\n";
        if(funcionarios[i].get_ativo() == true){
            cout<< "NUMERO: " << i<< endl;
            funcionarios[i].imprime_funcionario();
        }
    }

    gotoxy(40,10);
    cout<<"SELECIONE O NUMERO: ";
    cin>>codigo;

    funcionarios[codigo].set_ativo(false);

}



void MENU(Cliente *cliente, Pizza *pizza, Extras *extra, Pedido *pedido, Funcionario *funcionario){
    int pizza_posi = 0, cliente_posi = 0, pedido_posi = 0, funcionario_posi = 0;// guarda a posicao do vetor
    boolean sair = FALSE;
    clrscr();
    system("mode con: cols=80 lines=40");

    while(sair == FALSE){
        clrscr();
        gotoxy(30,5);
        cout<<"PIZZARIA MERDA";
        gotoxy(30,8);
        cout<<"[0]ADD CLIENTE";
        gotoxy(30,10);
        cout<<"[1]ADD PEDIDO";
        gotoxy(30,12);
        cout<<"[2]VER CLIENTES";
        gotoxy(30, 14);
        cout<<"[3]ADCIONAR FUNCIONARIO";
        gotoxy(30, 16);
        cout<<"[4]VER FUNCIONARIOS";
        gotoxy(30, 18);
        cout<<"[5]ADICIONA CLIENTES PADROES(PARA TESTES)";
        gotoxy(30,20);
        cout<<"[6]VER PEDIDOS";
        gotoxy(30,22);
        cout<<"[7]REMOVE CLIENTE";
        gotoxy(30,24);
        cout<<"[8]REMOVE FUNCIONARIO";

        switch(getch()){
        case '0':
            cliente_posi = ADD_CLIENTE(cliente_posi,cliente);
            break;

        case '2':
            VER_CLIENTES(cliente,cliente_posi);
            break;

        case '1':
            if (cliente_posi>0){
                pedido_posi = ADD_PEDIDO(pedido_posi,cliente_posi,pedido,cliente,pizza,extra);
            }else{
                clrscr();
                gotoxy(30,8);
                cout<<"PRIMEIRO CADASTRA UM CLIENTE NEH";
                Sleep(1250);
            }
            break;

        case '3':
            funcionario_posi = ADD_FUNCIONARIO(funcionario_posi, funcionario);
            break;

        case '4':
            VER_FUNCIONARIOS(funcionario, funcionario_posi);
            break;

        case '5':
            if(cliente_posi == 0){
                cliente_posi = ADD_CLIENTES_PADROES(cliente_posi,cliente);
            }else{
                clrscr();
                gotoxy(25, 20);
                cout<<"VC JA ADICIONOU OS PUTOS";
                Sleep(1000);
              }
            break;

        case '6':
            if (pedido_posi>0){
                VER_PEDIDOS(pedido_posi,pedido);
            }else{
                clrscr();
                gotoxy(30,8);
                cout<<"PRIMEIRO FAZ UM PEDIDO NEH";
                Sleep(1250);
            }
            break;
        case '7':
            remove_cliente(cliente,cliente_posi);
            break;
        case '8':
            remove_funcionario(funcionario,funcionario_posi);
            break;
        case 27:
            sair = TRUE;
            break;
        }


    }

}

#endif // MENU_H
