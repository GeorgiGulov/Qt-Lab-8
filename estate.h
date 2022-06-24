#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject
{
    Q_OBJECT
public:
    enum EstateType
    {
        ECONOM, // эконом
        LUXURIOUS, // элитная
        TOWN_HOUSE, // таун-хаус
        COTTAGE // коттедж
    };

    explicit Estate(QObject *parent = nullptr);
    Estate (int age, int area, int resident, int months, EstateType type, QString owner);
    EstateType GetType() const; // возвращаем тип жилья
    QString GetOwner() const; // возвращаем имя страховщика
    int GetResidents() const; // возвращаем число проживающих
    int GetAge() const; // возвращаем возраст
    int GetArea() const; // возврващаем площадь квартиры
    int GetMonths() const; // возвращаем кол-во месяцев страховки
private:
    int age; // возраст
    int area; // площадь
    int residents; // кол-во проживающих
    int months; // срок страхования
    EstateType type; // тип жилья
    QString owner; // имя
};

#endif // ESTATE_H


