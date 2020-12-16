#ifndef FUSIONRESPONSABLEIG_H
#define FUSIONRESPONSABLEIG_H

#include <QWidget>
#include "../gestionOuverturePCIG/gestionouverturepcpanel.h"
#include "../ResponsablePanel/widget.h"
#include "../../../responsable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fusionResponsableIg; }
QT_END_NAMESPACE

class fusionResponsableIg : public QWidget
{
    Q_OBJECT

public:
    fusionResponsableIg(QWidget *parent = nullptr, Responsable r = Responsable());
    ~fusionResponsableIg();

private:
    Widget *responsablePanel;
    GestionOuverturePCPanel *gestionOuvertureWidget;
    Responsable responsable;
    Ui::fusionResponsableIg *ui;
};
#endif // FUSIONRESPONSABLEIG_H