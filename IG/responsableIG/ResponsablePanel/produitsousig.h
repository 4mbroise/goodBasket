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
    void setData(const QString& id,const QString& nom,const QString& quantite,const QString& adresse,const QString& date,const QString& nomProducteur);



private:
    Ui::ProduitSousResponsable *ui;
};
#endif // WIDGET_H

