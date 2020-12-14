#ifndef CATALOGUESOUSIG_H
#define CATALOGUESOUSIG_H

#include <QWidget>
#

QT_BEGIN_NAMESPACE
namespace Ui { class CatalogueSousConsommateur; }
QT_END_NAMESPACE

class CatalogueSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    CatalogueSousConsommateur(QWidget *parent = nullptr);
    ~CatalogueSousConsommateur();
    void setData(const QString& id,const QString& nom,const QString& quantite,const QString& adresse,const QString& date,const QString& nomProducteur);

private slots:
    void on_Confirmer_clicked();

private:
    Ui::CatalogueSousConsommateur *ui;
};

#endif // CATALOGUESOUSIG_H
