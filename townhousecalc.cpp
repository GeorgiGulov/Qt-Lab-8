#include "townhousecalc.h"

TownhouseCalc::TownhouseCalc()
{

}

int TownhouseCalc::getCost(Estate *value)
{
    return (value->GetResidents() * 250 + value->GetArea() * 15) * value->GetMonths() * 1.3;
}


