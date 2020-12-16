#ifndef FORMULAIRECYCLE_H
#define FORMULAIRECYCLE_H

#include <QWidget>

#include "../../../responsable.h"
#include "../../../pc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class formulaireCycle; }
QT_END_NAMESPACE

class formulaireCycle : public QWidget
{
    Q_OBJECT

public:
    formulaireCycle(QWidget *parent = nullptr, Responsable r = Responsable());
    ~formulaireCycle();

signals:
    void miseAJourTableCycle();

private slots:
    void on_pushButton_released();

private:
    Responsable responsable;
    Ui::formulaireCycle *ui;
};
#endif // FORMULAIRECYCLE_H