#ifndef GESTIONOUVERTUREPCPANEL_H
#define GESTIONOUVERTUREPCPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QSqlQueryModel>

#include "../formulaireCycle/formulairecycle.h"
#include "../../../responsable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GestionOuverturePCPanel; }
QT_END_NAMESPACE

class GestionOuverturePCPanel : public QWidget
{
    Q_OBJECT

public:
    GestionOuverturePCPanel(QWidget *parent = nullptr, Responsable r = Responsable());
    ~GestionOuverturePCPanel();

private slots:
    void mettreAJourTable();

    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    QSqlQueryModel *model;
    formulaireCycle *formulaire;
    Responsable responsable;
    Ui::GestionOuverturePCPanel *ui;
};
#endif // GESTIONOUVERTUREPCPANEL_H
