#ifndef PRODUCTEURSOUSIG_H
#define PRODUCTEURSOUSIG_H

#include <QWidget>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProducteurSousResponsable; }
QT_END_NAMESPACE

/**
 * @brief InterfaceGraphique Producteur Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class ProducteurSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Producteur sous Responsbale
     * @param Qwidget widget de QT
     */
    ProducteurSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ProducteurSousResponsable
     */
    ~ProducteurSousResponsable();

    /**
     * @brief Mise a jour le contenu dans interface Producteur
     * @param QString contenu de String
     * @param QString id de producteur
     */
    void setData(const QString& a,const QString& id);


private slots:
    /**
     * @brief button de confirmation
     */
    void on_Confirmer_clicked();

private:
    /**
     * @brief ui de interface Producteur
     */
    Ui::ProducteurSousResponsable *ui;
};
#endif // WIDGET_H

