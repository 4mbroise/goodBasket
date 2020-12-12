#ifndef ERREURSOUSRESPONSABLE_H
#define ERREURSOUSRESPONSABLE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ErreurSousResponsable; }
QT_END_NAMESPACE

class ErreurSousResponsable : public QWidget
{
    Q_OBJECT

public:
    ErreurSousResponsable(QWidget *parent = nullptr);
    ~ErreurSousResponsable();
    void setData(const QString& a);

private slots:
    void on_Confirmer_clicked();

private:
    Ui::ErreurSousResponsable *ui;
};
#endif // WIDGET_H
