#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <states.h>
#include <estate.h>
#include <calculationfacade.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void update(); // слот при срабатывании сигнала notifyObservers
private slots:
    // слоты при срабатывании сигнала pressed()
    void btnCalcPressed();
    void btnUndoPressed();
private:
    Estate *processForm(); // обработка значений формы
    void fillForm(Estate *value); // заполнение формы предыдущим рассчётом
    void showCost(Estate *value); // заполняем виджет QLabel cost
private:
    Ui::Widget *ui; // виджеты формы
    States info; // объект класса для хранения предыдущих запросов
};
#endif // WIDGET_H


