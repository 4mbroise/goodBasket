#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Responsable
 * @version 1
 * @author CAI Yunfan
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class  Responsbale
     * @param Qwidget widget de QT
     */
    Widget(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe Responsable
     */
    ~Widget();

private slots:

    /**
     * @brief button de consulterReports
     */
    void on_ConsulterReports_clicked();

    /**
     * @brief button de payerProducteur
     */
    void on_PayerProducteur_clicked();

    void on_confirmer_clicked();

private:
    /**
     * @brief ui de interface responsable
     */
    Ui::Widget *ui;
};
#endif // WIDGET_H
