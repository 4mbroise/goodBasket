#ifndef INCRIPTIONIG_H
#define INCRIPTIONIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Incriptionig; }
QT_END_NAMESPACE

class Incriptionig : public QWidget
{
    Q_OBJECT

public:
    Incriptionig(QWidget *parent = nullptr);
    ~Incriptionig();

private:
    Ui::Incriptionig *ui;
};
#endif // INCRIPTIONIG_H
