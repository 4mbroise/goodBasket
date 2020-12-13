#ifndef LIVRAISONSOUSIG_H
#define LIVRAISONSOUSIG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LivraisonSousConsommateur; }
QT_END_NAMESPACE

class LivraisonSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    LivraisonSousConsommateur(QWidget *parent = nullptr);
    ~LivraisonSousConsommateur();
    void ajouterProduit(const QString& idProduit,const QString &idProducteur,const QString& quantite);

private slots:
    void on_Confirmer_clicked();

private:
    Ui::LivraisonSousConsommateur *ui;
};

#endif // LIVRAISONSOUSIG_H
