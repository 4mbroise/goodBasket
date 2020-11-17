#ifndef IDPRODUITGENERATOR_H
#define IDPRODUITGENERATOR_H


class IdProduitGenerator
{
    public:
        static IdProduitGenerator& Instance();
        int getNewIdProduit();
        int getNewIdProducteur();
    private:
        int lastIdProduit;
        int lastIdProducteur;
        IdProduitGenerator (const IdProduitGenerator&){}

        static IdProduitGenerator m_instance;
        IdProduitGenerator();
        ~IdProduitGenerator();

};

#endif // IDPRODUITGENERATOR_H
