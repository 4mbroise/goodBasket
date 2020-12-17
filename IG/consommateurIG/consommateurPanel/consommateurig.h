#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../../../consommateur.h"
#include "../../../utilisateur.h"
#include "../../../Outils/idgenerator.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Consommateurig; }
QT_END_NAMESPACE

class Consommateurig : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Consommateurig:constructeur du consommateur interface graphique
     * @param parent:Qwidget parent pointeur
     * @param c:consommateur avec id
     */
    Consommateurig(QWidget *parent = nullptr,Consommateur c=Consommateur(-1));

    /**
     * destructeur du consommateurig
     */
    ~Consommateurig();

    /**
     * @brief setLivraison:installer la liste de la livraison par rapport à donnée dans BDD
     * @param idConsommateur:id du Consommateur
     */
    void setLivraison(int idConsommateur);

    /**
     * @brief setLivraisonPrevue:installer la liste de la livraison prevue par rapport à donnée dans BDD
     * @param idConsommateur:id du Consommateur
     */
    void setLivraisonPrevue(int idConsommateur);

    /**
     * @brief setPC:installer liste pc par rapport à donnée dans BDD
     */
    void setPC();

    /**
     * @brief metterAJour:mettre à jour tout les Uis
     */
    void metterAJour();


private slots:
    /**
     * @brief on_ConsulterCatalogue_clicked:bouton signal si on clicke sur le bouton,la fonction va exécuter
     * pour consulter le catalogue du pc sélèctionné.
     */
    void on_ConsulterCatalogue_clicked();

    /**
     * @brief on_CommanderPanier_clicked:bouton signal si on clicke sur le bouton,la fonction va exécuter
     * pour commander tout les livraisons dans panier
     */
    void on_CommanderPanier_clicked();

    /**
     * @brief reshow: signal s'il reçoit le siganl, il va exécuter
     * pour reprendre l'interface graphique du consommateur cassé
     */
    void reshow();

private:

    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::Consommateurig *ui;

    /**
     * @brief idConsommateur:id du consommateur
     */
    int idConsommateur;

    /**
     * @brief consommateur:objet consommateur
     */
    Consommateur consommateur;


};


#endif // WIDGET_H
