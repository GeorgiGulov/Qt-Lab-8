#include "estate.h"

Estate::Estate(QObject *parent) : QObject(parent)
{

}

// конструктор с параметрами
Estate::Estate(int ageN, int areaN, int residentsN, int monthsN, EstateType typeN, QString ownerN)
{
    owner = ownerN;
    age = ageN;
    area = areaN;
    residents = residentsN;
    months = monthsN;
    type = typeN;
}

// возвращаем имя
QString Estate::GetOwner() const
{
    return this->owner;
}

// возвращаем возраст
int Estate::GetAge() const
{
    return this->age;
}

// возвращаем площадь
int Estate::GetArea() const
{
    return this->area;
}

// возвращаем кол-во проживающих
int Estate::GetResidents() const
{
    return this->residents;
}

// возвращаем срок страхования
int Estate::GetMonths() const
{
    return this->months;
}

// возвращаем тип жилья
Estate::EstateType Estate::GetType() const
{
    return this->type;
}


