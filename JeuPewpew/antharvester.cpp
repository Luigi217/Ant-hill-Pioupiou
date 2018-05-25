#include "antharvester.h"

AntHarvester::AntHarvester(QVector<QPoint> *p) : Ant()
{
    this->dps=0;
    this->hp=1;
    this->speedFactor=3;
    this->path=p;
}
