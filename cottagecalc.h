#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include "estate.h"

class CottageCalc
{
public:
    CottageCalc();
    static int getCost(Estate *value); // возврат стоимости страховки
};

#endif // COTTAGECALC_H


