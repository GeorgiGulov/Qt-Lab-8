#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent)
{

}

// Получить стоимость страховки
int CalculationFacade::getCost(Estate *value)
{
    int cost; // стоимость страховки
    switch (value->GetType()) {

    case Estate::EstateType::ECONOM:
    {
        CalcFactory * ECONOM_factory = new ApartmnetFactory; // выделяем память под объект
        cost = ECONOM_factory->fabrica()->getCost(value);   // создание нужного объекта и расчёт стоимости
        delete ECONOM_factory; // чистим память
        break;
    }
    case Estate::EstateType::LUXURIOUS:
    {
        CalcFactory * LUXURIOUS_factory = new LuxuriousApartmentFactory;
        cost = LUXURIOUS_factory->fabrica()->getCost(value);
        delete LUXURIOUS_factory;
        break;
    }
    case Estate::EstateType::TOWN_HOUSE:
    {
        CalcFactory * TOWN_HOUSE_factory = new TownhouseFactory;
        cost = TOWN_HOUSE_factory->fabrica()->getCost(value);
        delete TOWN_HOUSE_factory;
        break;
    }
    case Estate::EstateType::COTTAGE:
    {
        CalcFactory * COTTAGE_factory = new CottageFactory;
        cost = COTTAGE_factory->fabrica()->getCost(value);
        delete COTTAGE_factory;
        break;
    }
    default:
        cost = -1;
        break;
    }
    return cost;
}



