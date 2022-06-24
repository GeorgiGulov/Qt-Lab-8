#include "apartmentcalc.h"

ApartmentCalc::ApartmentCalc()
{

}

int ApartmentCalc::getCost(Estate *value)
{
    return (value->GetResidents() * 250 + value->GetArea() * 15) * value->GetMonths() * 1.1;
}


