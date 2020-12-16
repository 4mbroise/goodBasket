#ifndef ERREURSOUSGESTIONNAIRE_H
#define ERREURSOUSGESTIONNAIRE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ErreurSousGestionnaire; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Erreur Sous Gestionnaire
 * @version 1
 * @author CAI Yunfan
 */
class ErreurSousGestionnaire : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Erreur sous Gestionnaire
     * @param Qwidget widget de QT
     */
    ErreurSousGestionnaire(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ErreurSousGestionnaire
     */
    ~ErreurSousGestionnaire();

    /**
     * @brief Mise a jour le contenu dans interface Erreur
     * tous les produits
     * @param QString contenu de String
     */
    void setData(const QString& apercu);

private slots:
    /**
     * @brief button de confirmation
     */
    void on_Confirmer_clicked();

private:
    /**
     * @brief ui de interface Erreur
     */
    Ui::ErreurSousGestionnaire *ui;
};
#endif // WIDGET_H
