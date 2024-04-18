#include "Tictactoe.hpp"
#include "exception"

Jeu::Jeu() {
    raz();
    _status = Status::RougeJoue;
}

bool Jeu::lineWin() const {
    // check si une ligne est gagnante
    if(getCell(0,0) == getCell(0,1) and getCell(0,0) == getCell(0,2)){
        if (getCell(0,0) != Cell::Vide){
            return true;
        }
    }

    if(getCell(1,0) == getCell(1,1) and getCell(1,0) == getCell(1,2)){
        if (getCell(1,0) != Cell::Vide){
            return true;
        }
    }

    if(getCell(2,0) == getCell(2,1) and getCell(2,0) == getCell(2,2)){
        if (getCell(2,0) != Cell::Vide){
            return true;
        }
    }
    return false;
}

bool Jeu::colWin() const {
    // check si un colonne est gagnante
    if(getCell(0,0) == getCell(1,0) and getCell(0,0) == getCell(2,0)){
        if (getCell(0,0) != Cell::Vide){
            return true;
        }
    }

    if(getCell(0,1) == getCell(1,1) and getCell(0,1) == getCell(2,1)){
        if (getCell(0,1) != Cell::Vide){
            return true;
        }
    }

    if(getCell(0,2) == getCell(1,2) and getCell(0,2) == getCell(2,2)){
        if (getCell(0,2) != Cell::Vide){
            return true;
        }
    }
    return false;
}

bool Jeu::diagWin() const {
    // check si une diagonale est gagnante
    Cell first_c = getCell(1,1);
    if (first_c != Cell::Vide){
        if(first_c == getCell(0,0) and first_c == getCell(2,2)){
            return true;
        }
        else if(first_c == getCell(0,2) and first_c == getCell(2,0)){
            return true;
        }
    }
    return false; 
}


bool Jeu::win() const {
    return lineWin() or colWin() or diagWin();
}


bool Jeu::isFull() const {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(getCell(i,j) == Cell::Vide){
                return false;
            }
        }
    }
    return true;
}


Status Jeu::getStatus() const {
    return _status;
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
        if(_status == Status::RougeJoue){
            _plateau[i][j] = Cell::Rouge;
            if(win()){
                _status = Status::RougeGagne;
            }
            else{
                if(isFull()){
                    _status = Status::Egalite;
                }
                else {
                    _status = Status::VertJoue;
                }
            }
        }
        else if (_status == Status::VertJoue){
            _plateau[i][j] = Cell::Vert;
            if(win()){
                _status = Status::VertGagne;
            }
            else{
                if(isFull()){
                    _status = Status::Egalite;
                }
                else {
                    _status = Status::RougeJoue;
                }
            }
        }
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

