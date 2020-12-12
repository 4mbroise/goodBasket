#ifndef PRODUITSOUSIG_H
#define PRODUITSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProduitSousResponsable; }
QT_END_NAMESPACE

class ProduitSousResponsable : public QWidget
{
    Q_OBJECT

public:
    ProduitSousResponsable(QWidget *parent = nullptr);
    ~ProduitSousResponsable();
    void setData(const QString& a,const QString& id);


private slots:
    void on_Confirmer_clicked();

private:
    Ui::ProduitSousResponsable *ui;
};
#endif // WIDGET_H

