#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IdGenerator
{
    public:
        static IdGenerator& Instance();
        int getNewIdProduit();
        int getNewIdProducteur();
    private:
        int lastIdProduit;
        int lastIdProducteur;
        IdGenerator (const IdGenerator&){}

        static IdGenerator m_instance;
        IdGenerator();
        ~IdGenerator();

};

#endif // IDGENERATOR_H
