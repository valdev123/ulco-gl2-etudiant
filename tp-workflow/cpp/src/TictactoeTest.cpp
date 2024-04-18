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
    REQUIRE(game.getStatus() == Status::RougeJoue);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            REQUIRE(game.getCell(i,j) == Cell::Vide);
        }
    }
    game.jouer(0,1);
    game.raz();
    REQUIRE(game.getStatus() == Status::RougeJoue);
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

TEST_CASE("ligne win"){
    Jeu game;
    game.jouer(0,0);
    game.jouer(1,0);
    game.jouer(0,1);
    game.jouer(1,1);
    game.jouer(0,2);
    REQUIRE(game.lineWin());
    game.raz();
    game.jouer(1,0);
    game.jouer(0,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(1,2);
    REQUIRE(game.lineWin());
    game.raz();
    game.jouer(2,0);
    game.jouer(1,0);
    game.jouer(2,1);
    game.jouer(1,1);
    game.jouer(2,2);
    REQUIRE(game.lineWin());
    game.raz();
    game.jouer(2,0);
    game.jouer(1,0);
    game.jouer(2,1);
    game.jouer(1,1);
    game.jouer(1,2);
    std::cout << game;
    REQUIRE(!game.lineWin());
}

TEST_CASE("col win"){
    Jeu game;
    game.jouer(0,0);
    game.jouer(1,1);
    game.jouer(1,0);
    game.jouer(1,2);
    game.jouer(2,0);
    REQUIRE(game.colWin());
    game.raz();
    game.jouer(0,1);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(1,2);
    game.jouer(2,1);
    REQUIRE(game.colWin());
    game.raz();
    game.jouer(0,2);
    game.jouer(1,1);
    game.jouer(1,2);
    game.jouer(1,0);
    game.jouer(2,2);
    REQUIRE(game.colWin());
    game.raz();
    game.jouer(0,2);
    game.jouer(1,1);
    game.jouer(1,2);
    game.jouer(1,0);
    game.jouer(2,0);
    REQUIRE(!game.colWin());
}


TEST_CASE("diag win"){
    Jeu game;
    game.raz();
    game.jouer(0,0);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(2,2);
    REQUIRE(game.diagWin());
    game.raz();
    game.jouer(0,2);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(2,0);
    REQUIRE(game.diagWin());
    game.raz();
    game.jouer(0,2);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(2,1);
    REQUIRE(!game.diagWin());
}

TEST_CASE("win"){
    Jeu game;
    game.raz();
    game.jouer(0,0);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(2,2);
    REQUIRE(game.win());
    game.raz();
    game.jouer(0,0);
    game.jouer(1,0);
    game.jouer(1,1);
    game.jouer(0,1);
    game.jouer(2,1);
    REQUIRE(!game.win());
}

