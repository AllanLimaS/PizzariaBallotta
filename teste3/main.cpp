#include "personagem.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene Tela_game;

    Personagem * balottin = new Personagem();
    balottin->setRect(400,400,50,50);
    balottin->setBrush(QBrush(6));

    Tela_game.addItem(balottin);

    balottin->setFlag(QGraphicsItem::ItemIsFocusable);
    balottin->setFocus();

    for(int i =50 ; i < 500 ; i=i +50){
        Tela_game.addLine(1,i,500,i,QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    for(int i = 50; i < 500 ; i = i + 50){
        Tela_game.addLine(i,1,i,500,QPen(2));
    }

    QGraphicsView view(&Tela_game);
    view.setFixedSize(700,700);
    view.show();

    return a.exec();

}
