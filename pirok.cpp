#include <QKeyEvent>
#include "pirok.h"

void pirok::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){     
        setPos(x()-50,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+50,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-50);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+50);
    }
    else if (event->key() == Qt::Key_Space){
        setPos(x(),y()-100);

    }
}
