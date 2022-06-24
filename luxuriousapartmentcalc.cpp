#include "luxuriousapartmentcalc.h"

LuxuriousApartmentCalc::LuxuriousApartmentCalc()
{

}

int LuxuriousApartmentCalc::getCost(Estate *value)
{
    return (value->GetResidents() * 250 + value->GetArea() * 15) * value->GetMonths() * 1.2;
}


