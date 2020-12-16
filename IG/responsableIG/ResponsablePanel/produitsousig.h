#ifndef PRODUITSOUSIG_H
#define PRODUITSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProduitSousResponsable; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Produit Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class ProduitSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Produit sous Responsbale
     * @param Qwidget widget de QT
     */
    ProduitSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ProduitSousResponsable
     */
    ~ProduitSousResponsable();

    /**
     * @brief Mise a jour le contenu dans interface Producteur
     * @param QString id de produit
     * @param QString nom de produit
     * @param QString quantite de produit
     * @param QString prix de produit
     * @param QString adresse de produit
     * @param QString date de produit
     * @param QString nom de producteur de produit
     */
    void setData(const QString& id,const QString& nom,const QString& quantite,const QString& prix,const QString& adresse,const QString& date,const QString& nomProducteur);



private:
    /**
     * @brief ui de interface Produit
     */
    Ui::ProduitSousResponsable *ui;
};
#endif // WIDGET_H

