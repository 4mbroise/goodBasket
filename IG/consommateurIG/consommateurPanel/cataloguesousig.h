#ifndef CATALOGUESOUSIG_H
#define CATALOGUESOUSIG_H

#include <QWidget>
#include <produitsousig.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CatalogueSousConsommateur; }
QT_END_NAMESPACE

class CatalogueSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogueSousConsommateur(QWidget *parent = nullptr,QString adressPC="null",int idConsommateur=-1);
    ~CatalogueSousConsommateur();
    void setData();
    Ui::CatalogueSousConsommateur& getUI();
    void mettreAJour();
private slots:
    void on_Retourner_clicked();
signals:
    void sendsignal();

private:
    Ui::CatalogueSousConsommateur *ui;
    QString adressePC;
    int idConsommateur;
};

#endif // CATALOGUESOUSIG_H
