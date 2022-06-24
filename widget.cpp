#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnUndo->setEnabled(false); // ставим кнопку назад неактивной

    // соединяем сигналы со слотами
    connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
    connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

Widget::~Widget()  // деструктор виждета
{
    delete ui;
}

void Widget::update()
{
    auto value = info.getActualData(); // сохраняем последний элемент списка
    if(value != nullptr)
    {
        fillForm(value); // заполняем нашу форму согласно последнему запросу пользователя
    }
    ui->btnUndo->setEnabled(info.hasStates()); // обновляем состояние кнопки
    value = nullptr;
}


void Widget::btnCalcPressed()
{
    auto value = processForm();     // присваиваем value указатель на объект Estate
    showCost(value);                // выводит на экран стоимость аренды
    info.add(value);                // добавляем запись в список
    ui->btnUndo->setEnabled(true);  // активируем кнопу предыдущей записи

    // setting value to NULL
    value = nullptr;
}

void Widget::btnUndoPressed()
{
    info.undo();                    // вызывод метода для возврата предыдущих значений
    fillForm(info.getActualData()); // выводим на форму предыдущую запись

}

// получение всех дынных из формы
Estate *Widget::processForm()
{
    int age = ui->age->text().toInt();
    int area = ui->area->text().toInt();
    int resident = ui->residents->text().toInt();

    int months;
    switch (ui->period->currentIndex())
    {
    case 0:
        months = 6;
        break;
    case 1:
        months = 12;
        break;
    case 2:
        months = 18;
        break;
    }

    Estate::EstateType type;

    switch (ui->estateType->currentIndex())
    {
    case 0:
        type = Estate::EstateType::ECONOM;
        break;
    case 1:
        type = Estate::EstateType::LUXURIOUS;
        break;
    case 2:
        type = Estate::EstateType::TOWN_HOUSE;
        break;
    case 3:
        type = Estate::EstateType::COTTAGE;
        break;
    }

    QString owner = ui->owner->text();
    Estate *add = new Estate(age, area, resident, months, type, owner);
    return add;
}


// отчистка формы от текста и заполнение предыдущим рассчётом
void Widget::fillForm(Estate *value)
{
    if(value != nullptr) {
        int period;
        switch (value->GetMonths())
        {
        case 6:
            period = 0;
            break;
        case 12:
            period = 1;
            break;
        case 18:
            period = 2;
            break;
        }
        // отчищаем форму и заполняем значениями
        ui->owner->clear();
        ui->age->clear();
        ui->residents->clear();
        ui->cost->clear();
        ui->area->clear();

        ui->owner->setText(value->GetOwner());
        ui->age->setText(QString::number(value->GetAge()));
        ui->residents->setText(QString::number(value->GetResidents()));
        ui->area->setText(QString::number(value->GetArea()));
        ui->period->setCurrentIndex(period);
        ui->estateType->setCurrentIndex(value->GetType());

        showCost(value); // выводим цену на экран
    }
}


// присваение виджету cost цены страховки
void Widget::showCost(Estate *value)
{
    ui->cost->setText(QString::number(CalculationFacade::getCost(value)));
}
