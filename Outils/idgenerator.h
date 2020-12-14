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

        /**
         * @brief fonction qui retourne un nouvel numero d'IdUtilisateur
         *
         * @return un nouvel IdUtilisateur
         */
        int getNewIdUtilisateur();
        /**
         * @brief fonction qui retourne un nouvel numero d'IdLivraison
         *
         * @return un nouvel IdLivraison
         */
        int getNewIdLivraison();


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
        * @brief le dernier numero d'Id Producteur généré
        *
        */
        int lastIdUtilisateur;
        /**
        * @brief le dernier numero d'Id Producteur généré
        *
        */
        int lastIdLivraison;

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
