#ifndef LIVRAISONSOUSIG_H
#define LIVRAISONSOUSIG_H

#include <QWidget>
#include "../../../livraison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LivraisonSousConsommateur; }
QT_END_NAMESPACE

class LivraisonSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    LivraisonSousConsommateur(QWidget *parent = nullptr);
    ~LivraisonSousConsommateur();
    void setData(const QString& id,const QString& nom,const QString& idProduit,const QString& quantite,const QString& adressePC,const QString& dateLivraison);
    void setDataPrevue(const QString& id,const QString& nom,const QString& idProduit,const QString& quantite,const QString& adressePC,const QString& dateLivraison,const QString& dateAchat);
private slots:
    void on_Supprimer_clicked();

private:
    int idLivraison;
    Ui::LivraisonSousConsommateur *ui;
};

#endif // LIVRAISONSOUSIG_H
