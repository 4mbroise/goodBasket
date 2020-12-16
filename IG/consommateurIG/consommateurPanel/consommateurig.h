#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include "../../../consommateur.h"
#include "../../../utilisateur.h"
#include "../../../Outils/idgenerator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Consommateurig; }
QT_END_NAMESPACE

class Consommateurig : public QWidget
{
    Q_OBJECT

public:
    Consommateurig(QWidget *parent = nullptr,Consommateur c=Consommateur(-1));
    //Consommateurig(Consommateur *p);
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
    int idConsommateur;
    Consommateur consommateur;


};


#endif // WIDGET_H
