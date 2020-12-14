#ifndef LIVRAISONSOUSIG_H
#define LIVRAISONSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LivraisonSousResponsable; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Livraison Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class LivraisonSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Livraison sous Responsbale
     * @param Qwidget widget de QT
     */
    LivraisonSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe LivraisonSousResponsable
     */
    ~LivraisonSousResponsable();

    /**
     * @brief Mise a jour le contenu dans interface Livraison
     * @param QString id de livraison
     * @param QString nom de produit
     * @param QString quantite de produit
     * @param QString adresse de pc
     * @param QString apercu de erreur
     * @param QString prix de produit
     * @param QString id de consommateur
     */
    void setData(const QString& livraisonid,const QString& nom,const QString& quantite,const QString& adresse,const QString& erreur,const QString& prix,const QString& consommateurid);



private:
    /**
     * @brief ui de interface Livraison
     */
    Ui::LivraisonSousResponsable *ui;
};
#endif // WIDGET_H

