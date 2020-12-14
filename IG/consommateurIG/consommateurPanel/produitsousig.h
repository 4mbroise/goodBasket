#ifndef PRODUITSOUSIG_H
#define PRODUITSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProduitsousCatalogue; }
QT_END_NAMESPACE

class ProduitsousCatalogue : public QWidget
{
    Q_OBJECT

public:
    explicit ProduitsousCatalogue(QWidget *parent = nullptr);
    ~ProduitsousCatalogue();
    void setData(const QString& id,const QString& nom,const QString& prix,const QString& quantite,const QString &idProducteur,const QString& idConsommateur,const QString& adressePC);

private slots:
    void on_AjouterAuPanier_clicked();

private:
    Ui::ProduitsousCatalogue *ui;
    QString idConsommateur;
    QString adressePC;
    QWidget parent;
};
#endif // PRODUITSOUSIG_H
