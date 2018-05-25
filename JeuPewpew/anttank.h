#ifndef ANTTANK_H
#define ANTTANK_H

#include "ant.h"
#include "include.h"

class AntTank : public Ant
{
public:
    AntTank(QVector<QPoint> *p);
};

#endif // ANTTANK_H
