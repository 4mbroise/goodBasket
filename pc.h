#ifndef PC_H
#define PC_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include "producteur.h"

/**
 * @brief PC:point de collecte
 * chaque responsable geste un PC
 * PC contient
 * plusieur producteur
 * état présente que PC ouvert ou pas
 * adresse du PC
 *
 * @version 1
 * @author GE Yuxuan
 */
class PC{
    public:

    PC(std::string adressePC);

    ~PC();


    const QString& getAdressePC();

    const Producteur getProducteur(int idProducteur);

    void setAdresse(std::string adressePC);

    void ouvrirPC();

    void fermerPC();

    int nbProducteur();

    QHashIterator<int,Producteur> iterator();

    QHash<Produit,Producteur> getCatalogue();

    std::string toString();


    private:

    QString adresse;

    bool etat;

    QHash<int,Producteur> producteurs;

};

#endif // PC_H
