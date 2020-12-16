#ifndef SELECTIONIG_H
#define SELECTIONIG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Selectionig; }
QT_END_NAMESPACE

class Selectionig : public QWidget
{
    Q_OBJECT

public:
    Selectionig(QWidget *parent = nullptr,QString nom="",QString prenom="",QString adresse="",QString phone="",QString email="",QString pass="");
    ~Selectionig();
private slots:
    void on_Consommateur_clicked();
    void on_Producteur_clicked();
    void on_Responsable_clicked();

private:
    Ui::Selectionig *ui;
    QString nom;
    QString prenom;
    QString adresse;
    QString phone;
    QString email;
    QString pass;
};

#endif // SELECTIONIG_H
