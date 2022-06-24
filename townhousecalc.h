#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include "estate.h"

class TownhouseCalc
{
public:
    TownhouseCalc();
    static int getCost(Estate *value); // возврат стоимости страховки
};

#endif // TOWNHOUSECALC_H


