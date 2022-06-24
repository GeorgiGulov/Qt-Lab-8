#ifndef CALCFACTORY_H
#define CALCFACTORY_H

#include <estate.h>
#include <bstractcalc.h>

// абстрактный класс
class CalcFactory
{
public:
    virtual bstractCalc * fabrica() = 0;    // метод для выделения памяти под объекты
    virtual ~CalcFactory() { };             // деструктор базового класса
};



// выделяем память под разные виды жилья переопределяя метод fabrica()
class ApartmnetFactory : public CalcFactory {

public:
    bstractCalc * fabrica()
    {
        return new ApartmentCalc;
    }
};


class CottageFactory: public CalcFactory
{
public:
    bstractCalc * fabrica()
    {
        return new CottageCalc;
    }
};


class LuxuriousApartmentFactory: public CalcFactory
{
public:
    bstractCalc * fabrica()
    {
        return new LuxuriousApartmentCalc;
    }
};


class TownhouseFactory: public CalcFactory
{
public:
    bstractCalc * fabrica()
    {
        return new TownhouseCalc;
    }
};


#endif // CALCFACTORY_H

