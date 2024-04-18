#include "Tictactoe.hpp"
#include "iostream"

using namespace std;

int main() {

    cout << "TODO" << endl;

    Jeu game;

    game.raz();
    while(game.getStatus() != Status::RougeGagne and game.getStatus() != Status::VertGagne){
        std::cout << game << std::endl;
        switch (game.getStatus())
        {
        case Status::RougeJoue:
            std::cout << "rouge joue" << std::endl;
            break;

        case Status::VertJoue:
            std::cout << "vert joue" << std::endl;
            break;
        
        case Status::Egalite:
            std::cout << "egalité" << std::endl;
            break;
        
        default:
            break;
        }
        int i;
        int j;
        std::cout << "entrer un coup (i j) : ";
        std::cin >> i >> j;
        game.jouer(i,j);
    }
    std::cout << game;
    

    if(game.getStatus() == Status::RougeGagne){
        std::cout << "rouge gagne" << std::endl;
    }
    if(game.getStatus() == Status::VertGagne){
        std::cout << "vert gagne" << std::endl;
    }
    if(game.getStatus() == Status::Egalite){
        std::cout << "égalité" << std::endl;
    }

    return 0;
}

