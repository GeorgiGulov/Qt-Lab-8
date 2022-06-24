#ifndef BSTRACTCALC_H
#define BSTRACTCALC_H

#include "estate.h"

// абстрактный класс
class bstractCalc
{
public:
    virtual int getCost(Estate *value) = 0;
    virtual ~bstractCalc(){};
};


class ApartmentCalc : public bstractCalc
{
public:
    int getCost(Estate *value)
    {
        return (value->GetResidents() * 300 + value->GetArea() * 13) * value->GetMonths() * 1.20;
    }
};


class LuxuriousApartmentCalc : public bstractCalc
{
public:
    int getCost(Estate *value)
    {
        return (value->GetResidents() * 350 + value->GetArea() * 15) * value->GetMonths() * 1.50;
    }
};


class TownhouseCalc : public bstractCalc
{
public:
    int getCost(Estate *value)
    {
        return (value->GetResidents() * 400 + value->GetArea() * 18) * value->GetMonths() * 1.80;
    }
};


class CottageCalc : public bstractCalc
{
public:
    int getCost(Estate *value)
    {
        return (value->GetResidents() * 450 + value->GetArea() * 20) * value->GetMonths() * 2.0;
    }
};


#endif // BSTRACTCALC_H

