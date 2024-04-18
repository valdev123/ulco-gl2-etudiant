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

TEST_CASE("affichage de la grille vide"){
    Jeu game;
    std::stringstream ss;
    ss << game;
    std::string res = "...\n...\n...\n";
    REQUIRE(ss.str() == res);
}

TEST_CASE("get status v1"){
    Jeu game;
    REQUIRE(game.getStatus() == Status::RougeJoue);
    
}

TEST_CASE("get status v2"){
    Jeu game;
    game.jouer(1,1); // coup valide donc on change le joueur courant
    REQUIRE(game.getStatus() == Status::VertJoue);
}

TEST_CASE("get status v3"){
    Jeu game;
    game.jouer(1,1); // coup valide donc on change le joueur courant
    game.jouer(1,1); // coup non valide donc on ne change pas le joueur courant
    REQUIRE(game.getStatus() == Status::VertJoue);
}

TEST_CASE("jouer position inivalide"){
    Jeu game;
    bool res = game.jouer(-1,-1);
    REQUIRE(!res);
}

TEST_CASE("jouer position vide"){
    Jeu game;
    bool res = game.jouer(1,1);
    std::stringstream ss;
    ss << game;
    std::string res_plateau = "...\n.R.\n...\n";
    REQUIRE(res);
    REQUIRE(ss.str() == res_plateau);
}

TEST_CASE("jouer position non vide"){
    Jeu game;
    game.jouer(1,1);
    bool res = game.jouer(1,1);
    std::stringstream ss;
    ss << game;
    std::string res_plateau = "...\n.R.\n...\n";
    REQUIRE(!res);
    REQUIRE(ss.str() == res_plateau);
}


