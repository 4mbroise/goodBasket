#ifndef GESTIONNAIREIG_H
#define GESTIONNAIREIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionnaireIG; }
QT_END_NAMESPACE

/**
 * @brief InterfaceGraphique Gestionnaire
 * @version 1
 * @author CAI Yunfan
 */
class GestionnaireIG : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Gestionnaire
     * @param Qwidget widget de QT
     */
    GestionnaireIG(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe Gestionnaire
     */
    ~GestionnaireIG();

private slots:
    /**
     * @brief button de confirmation
     */
    void on_ConsulterReports_clicked();

    void on_ValiderPC_clicked();

private:
    /**
     * @brief ui de interface Gestionnaire
     */
    Ui::GestionnaireIG *ui;
};
#endif // GESTIONNAIREIG_H
