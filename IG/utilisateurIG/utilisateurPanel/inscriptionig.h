#ifndef INCRIPTIONIG_H
#define INCRIPTIONIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Inscriptionig; }
QT_END_NAMESPACE

class Inscriptionig : public QWidget
{
    Q_OBJECT

public:
    Inscriptionig(QWidget *parent = nullptr);
    ~Inscriptionig();

private:
    Ui::Inscriptionig *ui;
};
#endif // INCRIPTIONIG_H
