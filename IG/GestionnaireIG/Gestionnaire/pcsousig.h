#ifndef PCSOUSGESTIONNAIRE_H
#define PCSOUSGESTIONNAIRE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PcSousGestionnaire; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique PC Sous Gestionnaire
 * @version 1
 * @author CAI Yunfan
 */
class PcSousGestionnaire : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class PC sous Gestionnaire
     * @param Qwidget widget de QT
     */
    PcSousGestionnaire(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe PcSousGestionnaire
     */
    ~PcSousGestionnaire();

    /**
     * @brief Mise a jour le contenu dans interface PC
     * @param QString id de pc
     * @param QString nom
     * @param QString adresse
     */
    void setData(const QString& idPC,const QString& nom,const QString& adresse);

private slots:
    /**
     * @brief button de confirmation
     */
    void on_Confirmer_clicked();

    /**
     * @brief button de suppression
     */
    void on_Supprimer_clicked();

private:
    /**
     * @brief ui de interface Pc
     */
    Ui::PcSousGestionnaire *ui;

    /**
     * @brief id de interface Pc
     */
    int idPC;
};
#endif // WIDGET_H
