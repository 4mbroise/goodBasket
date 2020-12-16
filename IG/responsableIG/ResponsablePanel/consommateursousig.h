#ifndef CONSOMMATEURSOUSIG_H
#define CONSOMMATEURSOUSIG_H

#include <QWidget>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ConsommateurSousResponsable; }
QT_END_NAMESPACE

/**
 * @brief InterfaceGraphique Consommateur Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class ConsommateurSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Consommateur sous Responsbale
     * @param Qwidget widget de QT
     */
    ConsommateurSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ConsommateurSousResponsable
     */
    ~ConsommateurSousResponsable();

    /**
     * @brief Mise a jour le contenu dans interface Consommateur
     * @param QString id de Consommateur
     */
    void setData(const QString& Consommateurid);


private slots:
    /**
     * @brief button de confirmation
     */
    void on_Confirmer_clicked();

private:
    /**
     * @brief ui de interface Consommateur
     */
    Ui::ConsommateurSousResponsable *ui;

    /**
     * @brief id de consommateur
     */
    int consommateurId;
};
#endif // WIDGET_H

