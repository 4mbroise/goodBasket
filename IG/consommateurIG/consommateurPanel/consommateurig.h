#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../../../consommateur.h"
#include "../../../utilisateur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Consommateurig; }
QT_END_NAMESPACE

class Consommateurig : public QWidget
{
    Q_OBJECT

public:
    Consommateurig(QWidget *parent = nullptr);
    ~Consommateurig();
    void setLivraison(const QString & idConsommateur);
    void setLivraisonPrevue(const QString &idConsommateur);
    void setPC();
    void metterAJour();


private slots:
    void on_ConsulterCatalogue_clicked();
    void reshow();
private:
    Ui::Consommateurig *ui;

};


#endif // WIDGET_H
