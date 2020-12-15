#ifndef PRODUCTEURITEMSOUSIG_H
#define PRODUCTEURITEMSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProducteurItemSousResponsable; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique ProducteurItem Sous Responsable
 * @version 1
 * @author CAI Yunfan
 */
class ProducteurItemSousResponsable : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class ProducteurItem sous Responsbale
     * @param Qwidget widget de QT
     */
    ProducteurItemSousResponsable(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ProducteurItemSousResponsable
     */
    ~ProducteurItemSousResponsable();

    /**
     * @brief Mise a jour le contenu dans interface ProducteurItem
     * @param QString id de producteur
     * @param QString nom de producteur
     * @param QString telephone de producteur
     * @param QString adresse de producteur
     * @param QString accord de producteur
     */
    void setData(const QString& id,const QString& nom,const QString& tele,const QString& adresse,const QString& accord);



private:
    /**
     * @brief ui de interface ProducteurItem
     */
    Ui::ProducteurItemSousResponsable *ui;
};
#endif // WIDGET_H

