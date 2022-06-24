#include "states.h"

States::States(QObject *parent) : QObject(parent)
{

}

// деструктор класса
States::~States()
{
    if(actualData){
        delete actualData;
        actualData = nullptr;
    }
    qDeleteAll(array);
    array.clear();
}


// добавление элемента в список
void States::add(Estate *value)
{
    this->array.append(value);
}

// проверка на заполненность списка
bool States::hasStates()
{
    if (this->array.size() != 0) { return true; }
    else { return false; }
}

// возврат указателя на последний элемент списка
Estate * States::getActualData()
{
    if (!array.isEmpty())
    {
        return this->array.last();
    }
    else
    {
        return nullptr;
    }
}

// помещение последнего элемента списка в переменную actualData, а затем его удаление из списка
void States::undo()
{
    if (!hasStates())
    {
        this->actualData = nullptr;
    }
    else
    {
        this->actualData = getActualData();             // присваиваем в указатель на последний элемент последний элемент списка
        this->array.removeAt(this->array.size()-1);     // удаляем этот элемент из списка
        emit notifyObservers();                         // вызываем сигнал и срабатывает метод update
    }
}

void States::notifyObservers() {

}


