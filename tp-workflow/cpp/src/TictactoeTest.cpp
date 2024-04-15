#include "Tictactoe.hpp"
#include <sstream>
#include <catch2/catch.hpp>
#include "Tictactoe.hpp"

TEST_CASE("getCell"){
    Jeu j;
    REQUIRE(j.getCell(0,0) == Cell::Vide);
}


TEST_CASE("raz"){
    Jeu game;
    game.raz();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            REQUIRE(game.getCell(i,j) == Cell::Vide);
        }
    }
}

TEST_CASE("affichage de la grille"){
    Jeu game;
    std::stringstream ss;
    ss << game;
    std::string res = "...\n...\n...\n";
    REQUIRE(ss.str() == res);
}

TEST_CASE("get status v1"){
    Jeu game;
    game.getStatus();
}


