#ifndef CONNECTERIG_H
#define CONNECTERIG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Connecterig; }
QT_END_NAMESPACE

class Connecterig : public QWidget
{
    Q_OBJECT

public:
    Connecterig(QWidget *parent = nullptr);
    ~Connecterig();
private slots:
    void on_Login_clicked();
    void on_Inscrire_clicked();
private:
    Ui::Connecterig *ui;
};

#endif // CONNECTERIG_H
