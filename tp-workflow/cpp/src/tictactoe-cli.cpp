#include "Tictactoe.hpp"
#include "iostream"

using namespace std;

int main() {

    cout << "TODO" << endl;

    Jeu jeu;

    std::cout << jeu << std::endl;

    jeu.jouer(1,1);
    jeu.jouer(0,1);
    jeu.jouer(0,2);
    jeu.jouer(0,7);
    jeu.jouer(2,2);

    std::cout << jeu;

    return 0;
}

