#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <iostream>

enum class Status { Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue };

enum class Cell { Vide, Rouge, Vert };

// Moteur de jeu de tictactoe.
class Jeu {
    private:
        std::array<std::array<Cell, 3>, 3> _plateau;
        bool _player;

    public:
        // Constructeur à utiliser.
        Jeu();

        // Retourne le status du jeu courant (Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue).
        Status getStatus() const;

        /** \brief retourne l'état d'une case dans le jeu
         * 
         *  \param i indice ligne du plateau de jeu
         *  \param j indice colonne du plateau de jeu
        */
        Cell getCell(int i, int j) const;

        /*
        bool line_win() const;
        bool col_win() const;
        bool diag_win() const;
        bool win() const;
        bool is_full() const;
        */

        /** \brief Vérifie si une case est valide
         * 
         *  \param i ligne choisie
         *  \param j colonne choisie
         * 
         *  \details la case est valide si i et j sont entre [0,2]
        */
        bool isValidCase(int i, int j) const;

        /** \brief Vérifie si une case est libre
         * 
         *  \param i ligne choisie
         *  \param j colonne choisie
        */
        bool isEmptyCell(int i, int j) const;

        /** \brief Joue un coup pour le joueur courant.
         *
         * \param i ligne choisie (0, 1 ou 2)
         * \param j colonne choisie (0, 1 ou 2)
         * 
         * \details le coup est invalide, retourne false. Si le coup est valide,
         * joue le coup et retourne true.
        */
        bool jouer(int i, int j);

        /** \brief réinialise le jeu
         * 
        */
        void raz();
};

/** \brief retourne le plateau de jeu dans un flux
 * 
 *  \details on peut utiliser ce résultat pour l'afficher en console
 *  \param os le flux
 *  \param jeu le jeu
*/
std::ostream & operator<<(std::ostream & os, const Jeu & jeu);

#endif

