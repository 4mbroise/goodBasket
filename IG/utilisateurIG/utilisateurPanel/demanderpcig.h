#ifndef DEMANDERPCIG_H
#define DEMANDERPCIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Demanderpcig; }
QT_END_NAMESPACE

/**
 * @brief class pour demander un point de collect
 * @version 2
 * @author GE Yuxuan
 */
class Demanderpcig : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Demanderpcig:constructeur du connecter demander un point de collect
     * @param parent:Qwidget parent(nullptr)
     * @param nom
     * @param prenom
     * @param adresse
     * @param phone
     * @param email
     * @param pass
     */
    Demanderpcig(QWidget *parent = nullptr,QString nom="",QString prenom="",QString adresse="",QString phone="",QString email="",QString pass="");

    /**
     * destructeur du Demanderpcig
     */
    ~Demanderpcig();
private slots:
    /**
     * @brief Requete:faire la demande
     */
    void on_Requete_clicked();

private:
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::Demanderpcig *ui;

    /**
     * @brief nom
     */
    QString nom;
    /**
     * @brief prenom
     */
    QString prenom;
    /**
     * @brief adresse
     */
    QString adresse;
    /**
     * @brief telephone
     */
    QString phone;
    /**
     * @brief email
     */
    QString email;
    /**
     * @brief mot de passe
     */
    QString pass;
};

#endif // DEMANDERPCIG_H
