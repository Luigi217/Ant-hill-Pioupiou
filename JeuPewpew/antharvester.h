#ifndef ANTHARVESTER_H
#define ANTHARVESTER_H

#include "ant.h"
#include "include.h"

class AntHarvester : public Ant
{
public:
    AntHarvester(QVector<QPoint> *p);
};

#endif // ANTHARVESTER_H
