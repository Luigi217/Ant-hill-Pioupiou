#include "anttank.h"

AntTank::AntTank(QVector<QPoint> *p) : Ant()
{
    this->dps=4;
    this->hp=115;
    this->speedFactor=1;
    this->path=p;
}
