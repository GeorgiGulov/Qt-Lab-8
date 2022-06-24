#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>
#include <estate.h>
#include <CalcFactory.h>

class CalculationFacade : public QObject
{
    Q_OBJECT
public:
    explicit CalculationFacade(QObject *parent = nullptr); // базовый конструктор qt

    static int getCost(Estate *value); // возврат стоимости страховки
};

#endif // CALCULATIONFACADE_H



