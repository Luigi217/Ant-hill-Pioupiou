#include "antfighter.h"

AntFighter::AntFighter(QVector<QPoint> *p) : Ant()
{
    this->dps=10;
    this->hp=33;
    this->speedFactor=2;
    this->path=p;
}
