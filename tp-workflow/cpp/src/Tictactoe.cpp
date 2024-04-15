#include "Tictactoe.hpp"
#include "exception"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    // TODO
    return Status::RougeJoue;
}

/** \brief retourne la valeur de la cellule dans le jeu
 * 
 *  \param i indice ligne du plateau de jeu
 *  \param j indice colonne du plateau de jeu
*/
Cell Jeu::getCell(int i, int j) const {
    return _plateau[i][j];
}

/** \brief retourne le plateau de jeu dans un flux
 * 
 *  \details on peut utiliser ce résultat pour l'afficher en console
 *  \param os le flux
 *  \param jeu le jeu
*/
std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for(auto i = 0;i < 3; i++){
        for(auto j = 0; j < 3; j++){
            switch (jeu.getCell(i,j)){
                case Cell::Vide :
                    os << ".";
                    break;

                case Cell::Rouge :
                    os << "R";
                    break;

                case Cell::Vert :
                    os << "V";
                    break;

                default:
                    break;
            }
        }
        os << "\n";
    }
    return os;
}

bool Jeu::jouer(int i, int j) {
    // TODO
    return false;
}

/** \brief réinialise le jeu
 * 
*/
void Jeu::raz() {
    for(auto i = 0;i < 3;i++){
        for(auto j = 0; j < 3;j++){
            _plateau[i][j] = Cell::Vide;
        }
    }
}

