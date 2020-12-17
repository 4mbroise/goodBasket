#ifndef CONNECTERIG_H
#define CONNECTERIG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Connecterig; }
QT_END_NAMESPACE

/**
 * @brief connexion à le site comme producteur,responsable et consommateur
 * qui permet qu'on inscrire et soumettre tous mes informations
 * on peut choisir pendant producteur,responsable et consommateur
 * @version 2
 * @author GE Yuxuan
 * @author CAI Yunfan
 */
class Connecterig : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Connecterig:constructeur du connecter interface graphique
     * @param parent:Qwidget parent(nullptr)
     */
    Connecterig(QWidget *parent = nullptr);

    /**
     * destructeur du Connecterig
     */
    ~Connecterig();
private slots:
    /**
     * @brief Login:verifier tous les informations sont bien règlés et bien complétés puis connecter
     */
    void on_Login_clicked();

    /**
     * @brief Inscrire: passer a la page Inscrire
     */
    void on_Inscrire_clicked();
private:
    /**
     * @brief ui:ui contient tous les layouts et outils
     */
    Ui::Connecterig *ui;
};

#endif // CONNECTERIG_H
