#ifndef INCRIPTIONIG_H
#define INCRIPTIONIG_H

#include <QWidget>

/**
 * @brief Inscriptionig qui présente l'interface graphique de la inscription
 * qui permet qu'on inscrire et soumettre tous mes informations
 * on peut choisir log in si on a déjà inscrit
 * @version 2
 * @author GE Yuxuan
 */
QT_BEGIN_NAMESPACE
namespace Ui { class Inscriptionig; }
QT_END_NAMESPACE

class Inscriptionig : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Inscriptionig:constructeur du inscription interface graphique
     * @param parent:Qwidget parent(nullptr)
     */
    Inscriptionig(QWidget *parent = nullptr);


    /**
     * destructeur du Inscriptionig
     */
    ~Inscriptionig();

    /**
     * @brief verifier:vrifier tous les informations sont bien règlés et bien complétés
     * @return true si tous les informations sont bien règlés et bien complétés.false sinon
     */
    bool verifier();

private slots:

    /**
     * @brief on_Inscrire_clicked:bouton :la fonction  correspond au bouton qui permet qu'on peut soumettre les informations
     */
    void on_Inscrire_clicked();

    /**
     * @brief on_Login_clicked:bouton:la fonction  correspond au qui permet qu'on peut aller au interface de la connexion
     */
    void on_Login_clicked();

private:
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::Inscriptionig *ui;

};
#endif // INCRIPTIONIG_H
