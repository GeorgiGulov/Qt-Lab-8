#include "cottagecalc.h"

CottageCalc::CottageCalc()
{

}

int CottageCalc::getCost(Estate *value)
{
    return (value->GetResidents() * 250 + value->GetArea() * 15) * value->GetMonths() * 1.4;

}
