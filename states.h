#ifndef STATES_H
#define STATES_H

#include <QObject>
#include "estate.h"


class States : public QObject
{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();                  // деструктор

    void undo();                // возврат к предыдущей записи
    bool hasStates();           // проверка на заполненность списка
    Estate *getActualData();    // возврат указателя на последний элемент списка
    void add(Estate *value);    // добавление элемента в список

    void notifyObservers();
private:
    QList<Estate *> array;      // создание списка
    Estate *actualData;         // указатель, который хранит последний элемент списка
};

#endif // STATES_H

