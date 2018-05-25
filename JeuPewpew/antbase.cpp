#include "antbase.h"

AntBase::AntBase()
{
    this->hp = 1000;
}

int AntBase::getHp() const
{
    return hp;
}

void AntBase::setHp(int value)
{
    hp = value;
}


