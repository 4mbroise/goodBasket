#ifndef ERREURSOUSRESPONSABLE_H
#define ERREURSOUSRESPONSABLE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ErreurSousResponsable; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Erreur Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class ErreurSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Erreur sous Responsbale
     * @param Qwidget widget de QT
     */
    ErreurSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ErreurSousResponsable
     */
    ~ErreurSousResponsable();

    /**
     * @brief Mise a jour le message dans interface Erreur
     * @param QString contenu de String
     */
    void setData(const QString& a);

private slots:
    /**
     * @brief button de confirmation
     */
    void on_Confirmer_clicked();

private:
    /**
     * @brief ui de interface Erreur
     */
    Ui::ErreurSousResponsable *ui;
};
#endif // WIDGET_H
