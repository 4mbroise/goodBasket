#ifndef PRODUCTEURSOUSIG_H
#define PRODUCTEURSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProducteurSousResponsable; }
QT_END_NAMESPACE

class ProducteurSousResponsable : public QWidget
{
    Q_OBJECT

public:
    ProducteurSousResponsable(QWidget *parent = nullptr);
    ~ProducteurSousResponsable();
    void setData(const QString& a);


private:
    Ui::ProducteurSousResponsable *ui;
};
#endif // WIDGET_H

