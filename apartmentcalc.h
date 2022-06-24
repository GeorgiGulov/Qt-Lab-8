#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include "estate.h"

class ApartmentCalc
{
public:
    ApartmentCalc();
    static int getCost(Estate *value); // возврат стоимости страховки
};

#endif // APARTMENTCALC_H


