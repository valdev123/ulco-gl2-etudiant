#pragma once

#include "Forme.hpp"

#include <iostream>
#include <memory>
#include <vector>

class Canevas {
    private:
        std::vector<std::unique_ptr<Forme>> _formes;

    public:
        void ajouterDisque(int rayon);
        void ajouterRectangle(int largeur, int hauteur);
        double aireTotale() const;
        const std::vector<Description> descriptions() const;
        void exportJSON(std::ostream & os, const std::string & what) const;
        void exportYAML(std::ostream & os, const std::string & what) const;

    private:
        void exportFormeJSON(std::ostream & os, const Forme * f) const;
        void exportFormeYAML(std::ostream & os, const Forme * f) const;

};

