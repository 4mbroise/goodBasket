#ifndef PRODUIT_H
#define PRODUIT_H

#include <QtGui/QImage>
#include <QtCore/QString>

class Produit
{
public:
    Produit(int id, int q,double prix,std::string nom,std::string imagePath);
    ~Produit();
    QString const& getNom();
    QImage const& getImage();
    const int& getId();
    const int& getQuantite();
    const  double& getPrix();
    const std::string toString();
    void setPrix(double prix);
private:
    int id;
    int quantite;
    double  prix;
    QString nom;
    QImage image;
};

#endif // PRODUIT_H
