#ifndef SELECTIONIG_H
#define SELECTIONIG_H

#include <QWidget>

/**
 * @brief Selectionig qui présente l'interface graphique de la selection
 * qui nous permet de choisir un métier pour effectuer différentes opérations dans goodbasket.
 *  Si nous choisissons des consommateurs et des producteurs,nous avons dans l'interface de connexion.
 *  Si nous choisissons le responsable, nous avons dans l'interface de la demande du PC pour demander un PC.
 *  Après cela, nous devons passer pour devenir responsable
 *  Il stocke toutes les informations que nous avons remplies auparavant
 * @version 2
 * @author GE Yuxuan
 */
QT_BEGIN_NAMESPACE
namespace Ui { class Selectionig; }
QT_END_NAMESPACE

class Selectionig : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Selectionig:constructeur du selection interface graphique
     * @param parent:parent du selectionig (nullptr)
     * @param nom:nom du utilisateur
     * @param prenom:prenom du utilisateur
     * @param adresse:adresse du utilisateur
     * @param phone:numéro du phone du utilisateur
     * @param email:adresse mail du utilisateur
     * @param pass:mot de passe du utilisateur
     */
    Selectionig(QWidget *parent = nullptr,QString nom="",QString prenom="",QString adresse="",QString phone="",QString email="",QString pass="");

    /**
     * destructeur du Selectionig
     */
    ~Selectionig();
private slots:
    /**
     * @brief on_Consommateur_clicked:le bouton correspond au bouton qui permet qu'on devient à consommateur et enregistrer tous les informations et ensuite on arrive la interface graphique de la connexion
     */
    void on_Consommateur_clicked();

    /**
     * @brief on_Consommateur_clicked:le bouton correspond au bouton qui permet qu'on devient à Producteur et enregistrer tous les informations et ensuite on arrive la interface graphique de la connexion
     */
    void on_Producteur_clicked();

    /**
     * @brief on_Consommateur_clicked:le bouton correspond au bouton qui permet qu'on devient à Responsable et enregistrer tous les informations et ensuite on arrive la interface graphique de la demande du pc
     */
    void on_Responsable_clicked();

private:
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::Selectionig *ui;

    /**
     * @brief nom:nom du utilisateur enregistré
     */
    QString nom;

    /**
     * @brief prenom:prenom du utilisateur enregistré
     */
    QString prenom;

    /**
     * @brief adresse:adresse du utilisateur enregistré
     */
    QString adresse;

    /**
     * @brief phone:numéro du phone du utilisateur enregistré
     */
    QString phone;

    /**
     * @brief email:adresse mail du utilisateur enregistré
     */
    QString email;

    /**
     * @brief pass:mot de passe du utilisateur enregistré
     */
    QString pass;
};

#endif // SELECTIONIG_H
