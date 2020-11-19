#ifndef IDGENERATOR_H
#define IDGENERATOR_H

/**
 * @brief Singleton permettant de générer des IdProducteur et des IdProduit individuellement Unique, 
 * Chaque Id commence à 1
 * @version 1
 * @author Elliot Faugier
 */
class IdGenerator
{
    public:
        /**
         * @brief Permet d'obtenir l'instance unique de generatorId
         * 
         * @return l'instance unique de IdGenerator
         */
        static IdGenerator& Instance();
        
        /**
         * @brief fonction qui retourne un nouvel numero d'idProduit
         * 
         * @return un nouvel idProduit
         */
        int getNewIdProduit();
        
        /**
         * @brief fonction qui retourne un nouvel numero d'IdProducteur
         * 
         * @return un nouvel IdProducteur
         */
        int getNewIdProducteur();
    private:
        /**
        * @brief le dernier numero d'Id Produit généré
        * 
        */
        int lastIdProduit;

        /**
        * @brief le dernier numero d'Id Producteur généré
        * 
        */
        int lastIdProducteur;

        /**
        * @brief Constructeur par copie privé
        * 
        */
        IdGenerator (const IdGenerator&){}

        /**
        * @brief Instance unique de IdGenerator privé
        * 
        */
        static IdGenerator m_instance;
        
        /**
        * @brief Constructeur par défaut privé
        * 
        */
        IdGenerator();

        /**
        * @brief Destructeur privé
        * 
        */
        ~IdGenerator();

};

#endif // IDGENERATOR_H
