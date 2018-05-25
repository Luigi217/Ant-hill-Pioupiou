#ifndef ANTBASE_H
#define ANTBASE_H

#include "include.h"

class AntBase
{
public:
    AntBase();

    int getHp() const;
    void setHp(int value);

private:
    int hp;
    const int posX = BASEX;
    const int posY = BASEY;
};


#endif // ANTBASE_H
