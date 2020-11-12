#ifndef PRODUIT_H
#define PRODUIT_H

#include <QImage>
#include <QString>
#include <Outils/idproduitgenerator.h>

class Produit
{
public:
    Produit(const int& q,const double& prix,const QString& nom,const QImage& image);
private:
    int id;
    int quantite;
    double  prix;
    QString nom;
    QImage image;
};

#endif // PRODUIT_H
