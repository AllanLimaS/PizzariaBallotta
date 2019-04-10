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

int ADD_CLIENTE(int cliente_posi, Cliente *cliente){    //VOID DE CRIAÇÃO DE CLIENTE
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

    codigo = cliente_posi; // CODIGO DO CLIENTE É O MESMO DA POSIÇÃO DO VETOR
    pontuacao = 0;



    cliente[cliente_posi].constroi_cliente(name,endereco,dataNasc,cpf,codigo,pontuacao);
    cliente_posi++;         //AUMENTA UMA POSICAO NO VETOR PARA O PROXIMO CLIENTE
    return cliente_posi;    //RETORNA A POSICAO DO VETOR

}

int ADD_FUNCIONARIO(int funcionario_posi, Funcionario *funcionario){ // CRIAÇÃO DE FUNCIONARIO
    string name;
    string endereco;
    string dataNasc;
    string cpf;
    int codigo;
    int funcao = 0;
    float salario = 0.0;

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
    funcionario_posi++;         //AUMENTA APOSICAO NO VETOR
    return funcionario_posi;    //RETORNA A POSICAO

}

int ADD_PEDIDO(int pedido_posi,int posicao, Pedido *pedido, Cliente *cliente, Pizza *pizza){ // ADICIONAR PEDIDOS

    int sabor = 0;
    int borda = 0;
    int tamanho = 0;
    int i = 0;
    int j = 0;
    int cond = 0; // Condição caso o usuario  colocque um valori invalido
    int codigo = 0;
    int bebida = 0;
    int adicionais = 0;
    int pagamento = 0;
    int entrega = 0;
    int qntPizzas = 0;
    Extras extra_temp;
    bool fazerExtras;
    char ch;
    float preco = 0; // Preço do pedido
    int excluido = 0; // CASO TENHA SIDO TIRADO

    clrscr();
    cout<<"\nQUANTOS CLIENTES QUE PODEM COMER: "<< posicao <<endl;

    while(excluido == 0){ // while para ver se o cliente selecionado existe
        clrscr();
        for (i=0;i<posicao;i++){
            if(cliente[i].get_ativo() == TRUE){ // caso o cliente existe printa
                cout<<"\n\n";
                cout<<"Nome: "<< cliente[i].getName()<< endl << "Codigo: " << cliente[i].getCodigo()<< endl;
            }
        }
        gotoxy(30,8);
        cout<<"DIGITE O CODIGO DO CLIENTE: ";   // ESCOLHA DO CLIENTE
        cin>> codigo;

        for (i=0;i<posicao;i++){
            if (codigo == cliente[i].getCodigo()){  // COMPARAÇÃO PARA VER SE EXISTE
                if (cliente[i].get_ativo() == FALSE){ // caso ele tenha sido retido cliente n existe
                    clrscr();
                    gotoxy(30,10);
                    cout<< "CLIENTE N EXISTE";
                    Sleep(1000);
                }else {
                    excluido = 1; // caso ele exista sai do while
                }
            }
        }
    }


    for (i=0;i<posicao;i++){
        if (codigo == cliente[i].getCodigo()){  // COMPARAÇÃO PARA VER SE EXISTE
            clrscr();
            gotoxy(30,10);
            cout<<"CLIENTE SELECIONADO"<<endl;
            gotoxy(30, 15);
            cout<<"Nome: "<< cliente[i].getName();
            gotoxy(30, 16);
            cout<<"Codigo: " << cliente[i].getCodigo();
            int pontucao = cliente[i].getPontuacao() + 10;
            cliente[i].setPontuacao(pontucao);

            Sleep(1000);

            while(cond == 0){ // PAGAMENTO
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
                    cout << "INVALIDO";
                    Sleep(1000);
                } else {
                    cond = 1;
                }
            }

            cond = 0; // REDEFINE COND PARA OS WHILE FICAR BUNITO

            while(cond == 0){ // ENTREGA
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
                    cout << "INVALIDO";
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

                while(cond == 0){ // EXTRAS
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
                        cout << "INVALIDO";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (adicionais) { // PREÇO ADICIONAIS
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

                while(cond == 0){ // EXTRAS 2
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
                        cout << "INVALIDO";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (bebida) { // PREÇO BEBIDAS
                case 0:
                    preco = preco;
                    break;

                case 1:
                    preco = preco + 4.50;
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
            cout<<"DIGITE A QUANTIDADE DE PIZZAS: "; // QUANTIDADE DE PIZZAS
            cin>>qntPizzas;
            for(j=0;j<qntPizzas;j++){

                while(cond == 0){ // TAMANHO
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
                        cout << "INVALIDO";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                switch (tamanho) { // PREÇO DE CADA TAMANHO

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

                while(cond == 0){ // BORDA
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
                        cout << "INVALIDO";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                if(borda != 4){ // IF POIS BORDA SIMPLES N TEM PREÇO
                    preco = preco + 7.50;
                }

                cond = 0;

                while(cond == 0){ // SABOR DAS PIZZA
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
                        gotoxy(30, 20);
                        cout << "INVALIDO";
                        Sleep(1000);
                    } else {
                        cond = 1;
                    }
                }

                cond = 0;
                pizza[j].constroi_pizza(sabor,borda,tamanho); // CONSTROI A PIZZA
                pedido[pedido_posi].add_pizza(pizza[j]); // ADD PIZZA CONSTRUIDA AO VETOR
            }

            clrscr();
            if (cliente[i].getPontuacao() == 100){ // CASO A PONTUAÇÃO DO CLIENTE SEJA 100 ELE GANHA DESCONTO DE 30
                preco = preco - 30;

                cliente[i].setPontuacao(0);
                for(; i<60; i++){
                    int rnd, rnd2, rnd3;
                    rnd = rand()%80;
                    rnd2 = rand()%40;
                    rnd3 = rand()%15;
                    textcolor(rnd3, 0);
                    gotoxy(rnd, rnd2);
                    cout<<"PROMOCAO";
                    Sleep(20);
                }
                textcolor(2, 0);
                clrscr();
            }
            pedido[pedido_posi].setPreco(preco); // SET DE PREÇO
            pedido[pedido_posi].imprime_pedido(); // IMPRIME O PEDIDO
        }
    }
    pedido_posi++;
    system("pause");

    return pedido_posi;
}

int ADD_CLIENTES_PADROES(int cliente_posi, Cliente *cliente){ // CLIENTES PARA FINS DE TESTE
    cliente[cliente_posi].constroi_cliente("Allan a lima","Mario","19/06/2000","122.975.909-38",0,0);
    cliente_posi++;
    cliente[cliente_posi].constroi_cliente("GuxXxtavo","BruxXxque","13/13/13","777.777.777-77",1,0);
    cliente_posi++;
    cliente[cliente_posi].constroi_cliente("Koguto","bC","200AC","987.654.321-00",2,80);
    cliente_posi++;

    clrscr();
    gotoxy(30,8);
    cout<<"CLIENTES ADICIONADOS COM SUCESSO"<<endl<<endl;
    Sleep(1500);

    return cliente_posi;

}

void VER_CLIENTES(Cliente *cliente,int posicao){ // VER CLIENTES
    int i = 0;
    int ativos = 0;

    clrscr();
    for(i =0; i < posicao ; i++){
        if(cliente[i].get_ativo() == true){ // FOR PARA TIRAR OS CLIENTES QUE FORAM RETIRADOS
            ativos++;
        }
    }

    cout<<"\nCLIENTES CADASTRADOS: "<< posicao <<endl; // TDS OS CLIENTES ADICIONADOS
    cout<<"\nCLIENTES ATIVOS: "<< ativos<<endl; // CLIENTES ATIVOS

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        cliente[i].imprime_cliente(); // IMPRIME CLIENTES
    }
    system("pause");
}

void VER_PEDIDOS(int pedido_posi,Pedido *pedido){ // VER PEDIDOS
    int i = 0;

    boolean sair = FALSE;
    clrscr();
    cout<<"PEDIDOS FEITOS: "<<pedido_posi<<endl;

    while(sair==FALSE){
        clrscr();
        cout<<endl<<"--------------------------PEDIDO "<<i + 1<<"--------------------------"<<endl;
        pedido[i].imprime_pedido();
        cout<<endl<<"--------------------------PEDIDO "<<i + 1<<"--------------------------"<<endl;
        cout<<"[a]PEDIDO ANTERIOR"<<endl<<"[d]PROXIMO PEDIDO"<<endl<<"[esc]SAIR"<<endl;

        switch(getch()){ // SWITCH PARA TROCA DE PEDIDOS

        case 'a':
            if (i==0){
                cout<<endl<<"NAO HA PEDIDOS ANTERIORES";
                Sleep(1000);
            }else{
                i--;
            }
            break;

        case 'd':
            if(i==pedido_posi-1){
                cout<<endl<<"NAO A PEDIDO DEPOIS DESSE";
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

void VER_FUNCIONARIOS(Funcionario *funcionario,int posicao){ // VER FUNCIONARIOS
    int i = 0, falsos = 0;

    clrscr();
    cout<<"\nFUNCIONARIOS CADASTRADOS: "<< posicao <<endl;
    for(i=0;i < posicao;i++){
        if(funcionario[i].get_ativo() == false){ // FUNCIONARIOS RETIRADOS
            falsos++;
        }
    }
    cout<<"\n\nDEMITIDOS: " << falsos << "\n\n";

    for(i=0;i < posicao;i++){
        cout<<"\n\n";
        funcionario[i].imprime_funcionario(); // IMPRIME FUNCIONARIOS
    }
    system("pause");
}

void REMOVE_CLIENTE(Cliente *cliente, int quantidade){ // REMOVER CLIENTES
    clrscr();
    cout<<"\nCLIENTES"<<endl;
    int codigo, i;

    for (i=0;i<quantidade;i++){ // IMPRIME CLIENTES
        cout<<"\n";
        if(cliente[i].get_ativo() == true){
            cout<<"Nome: "<< cliente[i].getName()<< endl << "CODIGO: " << cliente[i].getCodigo()<< endl;
        }
    }

    gotoxy(40,10);
    cout<<"SELECIONE O CODIGO: "; // SELEÇÃO DO CLIENTE QUE DESEJA APAGAR
    cin>>codigo;

    cliente[codigo].set_ativo(false); // RETIRA O ATIVO DO CLIENTE
}

void REMOVE_FUNCIONARIO(Funcionario *funcionarios, int quantidade){ // REMOVE FUNCIONARIOS
    clrscr();
    cout<<"\nFUNCIONARIOS: "<<endl;
    int codigo, i;


    for (i=0;i<quantidade;i++){
        cout<<"\n";
        if(funcionarios[i].get_ativo() == true){    // PRINTA O NUMERO DO FUNCIONARIO
            cout<< "NUMERO: " << i<< endl;
            funcionarios[i].imprime_funcionario();
        }
    }

    gotoxy(40,10);
    cout<<"SELECIONE O NUMERO: "; // SELEÇÃO DO FUNCIONARIO PARA APAGAR
    cin>>codigo;

    funcionarios[codigo].set_ativo(false); // RETIRA O ATIVO DO FUNCIONARIO

}

void MENU(Cliente *cliente, Pizza *pizza, Extras *extra, Pedido *pedido, Funcionario *funcionario){

    int cliente_posi = 0, pedido_posi = 0, funcionario_posi = 0;// guarda a posicao do vetor

    int ativos = 0; // VARIAVEIS UTILIZADAS PARA VER SE TEM CLIENTE
    int i = 0;      //

    boolean sair = FALSE;

    clrscr();
    system("mode con: cols=80 lines=40");   //DEFINE O TAMANHO DA JANELA
    textcolor(2, 0);

    while(sair == FALSE){ // PRINT DO INICIO DO MENU
        clrscr();

        gotoxy(30,5);
        textcolor(10,0);cout<<"PI";textcolor(15,0);cout<<"ZZ";textcolor(12,0);cout<<"AR";textcolor(10,0);cout<<"IA";textcolor(15,0);cout<<" BA";textcolor(12,0);cout<<"LL";textcolor(10,0);cout<<"OT";textcolor(15,0);cout<<"A'";textcolor(12,0);cout<<"S";

        //cout<<"PIZZARIA BALLOTA'S";

        gotoxy(30,8);
        textcolor(2,0);
        cout<<"[0]ADD CLIENTE";
        gotoxy(30,10);
        textcolor(7,0);
        cout<<"[1]ADD PEDIDO";
        gotoxy(30,12);
        textcolor(4,0);
        cout<<"[2]VER CLIENTES";
        gotoxy(30, 14);
        textcolor(2,0);
        cout<<"[3]ADCIONAR FUNCIONARIO";
        gotoxy(30, 16);
        textcolor(7,0);
        cout<<"[4]VER FUNCIONARIOS";
        gotoxy(30, 18);
        textcolor(4,0);
        cout<<"[5]VER PEDIDOS";
        gotoxy(30,20);
        textcolor(2,0);
        cout<<"[6]REMOVE CLIENTE";
        gotoxy(30,22);
        textcolor(7,0);
        cout<<"[7]REMOVE FUNCIONARIO";
        gotoxy(30,24);
        textcolor(4,0);
        cout<<"[8]ADICIONA CLIENTES PADROES(PARA TESTES)";

        textcolor(7,0);

        switch(getch()){
        case '0':
            cliente_posi = ADD_CLIENTE(cliente_posi,cliente); // CHAMADA DO ADD CLIENTE
            break;

        case '1':
            for(i = 0; i < cliente_posi ; i++){
                if(cliente[i].get_ativo() == true){ // VERIFICA SE EXISTE CLIENTE ATIVO
                    ativos++;
                }
            }
            if (cliente_posi > 0 && ativos > 0){
                pedido_posi = ADD_PEDIDO(pedido_posi,cliente_posi,pedido,cliente,pizza); // VERIFICA SE A CLIENTE E ATIVOS CASO SIM CHMA ADD PEDIDO
            }else{
                clrscr();
                gotoxy(30,8);
                cout<<"PRIMEIRO CADASTRA UM CLIENTE NEH"; // CASO N HAJA CLIENTE PARA FAZER PEDIDO
                Sleep(1250);
            }
            break;

        case '2':
            VER_CLIENTES(cliente,cliente_posi); // CHAMADA DE VER CLIENTE
            break;

        case '3':
            funcionario_posi = ADD_FUNCIONARIO(funcionario_posi, funcionario); // ADD FUNCIONARIOS
            break;

        case '4':
            VER_FUNCIONARIOS(funcionario, funcionario_posi); // VER FUNCIONARIOS
            break;

        case '5':
            if (pedido_posi>0){
                VER_PEDIDOS(pedido_posi,pedido); // VER PEDIDOS
            }else{
                clrscr();
                gotoxy(30,8);
                cout<<"PRIMEIRO FAZ UM PEDIDO NEH"; // CASO N HAJA PEDIDOS
                Sleep(1250);
            }
            break;

        case '6':
            REMOVE_CLIENTE(cliente,cliente_posi); // REMOVE CLIENTE
            break;

        case '7':
            REMOVE_FUNCIONARIO(funcionario,funcionario_posi); // REMOVE FUNCIONARIO
            break;

        case '8':
            if(cliente_posi == 0){
                cliente_posi = ADD_CLIENTES_PADROES(cliente_posi,cliente); // ADICIONA CLIENTES PARA TESTE
            }else{
                clrscr();
                gotoxy(25, 20);
                cout<<"VC JA ADICIONOU UM CLIENTE"; // CASO JA TENHA CLIENTES
                Sleep(1000);
              }
            break;

        case 27:
            sair = TRUE; // SAIDA
            break;
        }
    }
}
#endif // MENU_H
