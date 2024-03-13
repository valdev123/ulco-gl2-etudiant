#include "Forme.hpp"

#include <cmath>
#include <numeric>

Disque::Disque(double rayon) :
    _rayon(rayon)
{}

double Disque::aire() const {
    return _rayon * 2 * M_PI;;
}

const Description Disque::toDescription() const {
    Description description;
    description["name"] = "Disque";
    description["rayon"] = std::to_string(_rayon);
    return description;
}

Rectangle::Rectangle(double largeur, double hauteur) :
    _largeur(largeur), _hauteur(hauteur)
{}

double Rectangle::aire() const {
    return _largeur * _hauteur;
}

const Description Rectangle::toDescription() const {
    Description description;
    description["name"] = "Rectangle";
    description["largeur"] = std::to_string(_largeur);
    description["hauteur"] = std::to_string(_hauteur);
    return description;
}
