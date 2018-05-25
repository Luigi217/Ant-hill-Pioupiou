#ifndef ANTFIGHTER_H
#define ANTFIGHTER_H

#include "ant.h"
#include "include.h"

class AntFighter : public Ant
{
public:
    AntFighter(QVector<QPoint> *p);
};

#endif // ANTFIGHTER_H
