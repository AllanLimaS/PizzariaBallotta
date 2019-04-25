#include "personagem.h"
#include <QKeyEvent>

void Personagem::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if(x() == -350){
            setPos(x(),y());
        }else{
            setPos(x()-50,y());
        }
    }

    else if (event->key() == Qt::Key_Right){
        if(x() == 0){
            setPos(x(),y());
        }else{
            setPos(x()+50,y());
        }
    }

    else if (event->key() == Qt::Key_Up){
        if(y() == -350){
            setPos(x(),y());
        }else{
            setPos(x(),y()-50);
        }
    }

    else if (event->key() == Qt::Key_Down){
        if(y() == 0){
            setPos(x(),y());
        }else{
            setPos(x(),y()+50);
        }
    }
}
