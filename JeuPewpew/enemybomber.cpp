#include "enemybomber.h"

EnemyBomber::EnemyBomber(QPoint *p, QVector<QPoint> *pa)
{
    this->dps = 0;
    this->damageToBase = 60;
    this->hp = 80;
    this->setPosition(p);
    this->speedFactor = 1;
    this->setPath(pa);
}
