#ifndef PRODUITSOUSIG_H
#define PRODUITSOUSIG_H

#include <QWidget>
#include "cataloguesousig.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProduitsousCatalogue; }
QT_END_NAMESPACE
class CatalogueSousConsommateur;

class ProduitsousCatalogue : public QWidget
{
    Q_OBJECT

public:
     ProduitsousCatalogue(CatalogueSousConsommateur* parent = nullptr);
    ~ProduitsousCatalogue();
    void setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const int& idConsommateur,const QString& adressePC);
    void mettreAJour();


private slots:
    void on_AjouterAuPanier_clicked();

private:
    Ui::ProduitsousCatalogue *ui;
    int idConsommateur;
    QString adressePC;
    CatalogueSousConsommateur* parent;

};
#endif // PRODUITSOUSIG_H
