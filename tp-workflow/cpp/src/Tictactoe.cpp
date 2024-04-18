#include "Tictactoe.hpp"
#include "exception"

Jeu::Jeu() {
    raz();
}

/*
bool Jeu::line_win() const {
    Cell first_c;
    // check si une ligne est gagnante
    for(int i = 0;i < 3;i++){
        first_c = getCell(i,0);
        int cpt(1);
        for(int j = 1; j < 3; j++){
            if(getCell(i,j) == first_c){
                cpt++;
            }
            else{
                break;
            }
        }
        if(cpt == 3){
            return true;
        }
    }
    return false;
}

bool Jeu::col_win() const {
    Cell first_c;
    // check si un colonne est gagnante
    for(int i = 0;i < 3;i++){
        first_c = getCell(0,i);
        int cpt(1);
        for(int j = 1; j < 3; j++){
            if(getCell(j,i) == first_c){
                cpt++;
            }
            else{
                break;
            }
        }
        if(cpt == 3){
            return true;
        }
    }
}

bool Jeu::diag_win() const {
    // check si une diagonale est gagnante
    Cell first_c = getCell(1,1);
    if(first_c == getCell(0,0) and first_c == getCell(2,2)){
        return true;
    }
    else if(first_c == getCell(0,2) and first_c == getCell(2,0)){
        return true;
    }
    return false; 
}


bool Jeu::win() const {
    return line_win() or col_win() or diag_win();
}

bool Jeu::is_full() const {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

        }
    }
    return true;
}
*/

Status Jeu::getStatus() const {
    /*
    if(win()){
        if(_player){
            return Status::RougeGagne;
        }
        else{
            return Status::VertGagne;
        }
    }
    */
    if(_player){
        return Status::VertJoue;
    }
    else{
        return Status::RougeJoue;
    }
}

Cell Jeu::getCell(int i, int j) const {
    return _plateau[i][j];
}

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

bool Jeu::isValidCase(int i, int j) const {
    return i >= 0 and i <= 2 and j >= 0 and j <= 2; 
}

bool Jeu::isEmptyCell(int i, int j) const {
    return getCell(i,j) == Cell::Vide;
}

bool Jeu::jouer(int i, int j) {
    if(!isValidCase(i,j)){
        return false;
    }
    if(isEmptyCell(i,j)){
        Status s = getStatus();
        if(s == Status::RougeJoue){
            _plateau[i][j] = Cell::Rouge;
        }
        else{
            _plateau[i][j] = Cell::Vert;
        }
        _player = !_player;
        return true;
    }
    return false;
}

void Jeu::raz() {
    _player = false;
    for(auto i = 0;i < 3;i++){
        for(auto j = 0; j < 3;j++){
            _plateau[i][j] = Cell::Vide;
        }
    }
}

