#include "timerupdateview.h"

timerUpdateView::timerUpdateView(QObject *parent, int x)
    :QThread(parent)
{
    this->fps = x;
    this->running = true;
}

void timerUpdateView::run(){
    this->exec();
}

void timerUpdateView::exec(){
    while(running){
        emit signalUpdate();
        this->msleep(1000/this->fps);
    }
}

void timerUpdateView::setRunning(bool value)
{
    running = value;
}
