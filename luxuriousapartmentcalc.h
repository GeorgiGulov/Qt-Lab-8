#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include "estate.h"

class LuxuriousApartmentCalc
{
public:
    LuxuriousApartmentCalc();
    static int getCost(Estate *value); // возврат стоимости страховки
};

#endif // LUXURIOUSAPARTMENTCALC_H


