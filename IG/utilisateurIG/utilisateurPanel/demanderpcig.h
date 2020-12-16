#ifndef DEMANDERPCIG_H
#define DEMANDERPCIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Demanderpcig; }
QT_END_NAMESPACE

class Demanderpcig : public QWidget
{
    Q_OBJECT
public:

    Demanderpcig(QWidget *parent = nullptr,QString nom="",QString prenom="",QString adresse="",QString phone="",QString email="",QString pass="");
    ~Demanderpcig();
private slots:
    void on_Requete_clicked();

private:
    Ui::Demanderpcig *ui;
    QString nom;
    QString prenom;
    QString adresse;
    QString phone;
    QString email;
    QString pass;
};

#endif // DEMANDERPCIG_H
