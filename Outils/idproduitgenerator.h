#ifndef IDPRODUITGENERATOR_H
#define IDPRODUITGENERATOR_H


class IdProduitGenerator
{
public:
    static IdProduitGenerator& Instance();
    int getNewIdProduit();
private:
    int lastIdProduit;
    IdProduitGenerator& operator= (const IdProduitGenerator&){}
    IdProduitGenerator (const IdProduitGenerator&){}

    static IdProduitGenerator m_instance;
    IdProduitGenerator();
    ~IdProduitGenerator();

};

#endif // IDPRODUITGENERATOR_H
