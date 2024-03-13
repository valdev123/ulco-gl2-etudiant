#include "Canevas.hpp"

#include <cmath>
#include <numeric>

void Canevas::ajouterDisque(int rayon) {
    _formes.push_back(std::make_unique<Disque>(rayon));
}

void Canevas::ajouterRectangle(int largeur, int hauteur) {
    _formes.push_back(std::make_unique<Rectangle>(largeur, hauteur));
}

double Canevas::aireTotale() const {
    double res = 0.0;
    for (const auto & f : _formes)
        res += f.get()->aire();
    return res;
}

const std::vector<Description> Canevas::descriptions() const {
    std::vector<Description> descriptions;
    for (const auto & f : _formes){
        descriptions.push_back(f.get()->toDescription());
    }
    return descriptions;
}

void Canevas::exportFormeYAML(std::ostream & os, const Forme * f) const {

    auto disque = dynamic_cast<const Disque*>(f);
    if (disque) {
        os << "- name: \"Disque\"\n";
        os << "  rayon: \"" << disque->_rayon << "\"\n";;
        return;
    }

    auto rectangle = dynamic_cast<const Rectangle*>(f);
    if (rectangle) {
        auto desc = rectangle->toDescription();
        os << "- name: \"Rectangle\"\n";
        os << "  largeur: \"" << desc["largeur"] << "\"\n";;
        os << "  hauteur: \"" << desc["hauteur"] << "\"\n";;
        return;
    }

}

void Canevas::exportYAML(std::ostream & os, const std::string & what) const {
    if (what == "resume") {
        os << "- name: \"Canevas\"\n";
        os << "  aireTotale: \"" << aireTotale() << "\"\n";;
        return;
    }

    if (what == "descriptions") {
        for (const auto & f : _formes)
            exportFormeYAML(os, f.get());
        return;
    }
}

void Canevas::exportFormeJSON(std::ostream & os, const Forme * f) const {

    auto disque = dynamic_cast<const Disque*>(f);
    if (disque) {
        os << "  {\n";
        os << "    \"name\": \"Disque\",\n";
        os << "    \"rayon\": \"" << disque->_rayon << "\"\n";
        os << "  }";
        return;
    }

    auto rectangle = dynamic_cast<const Rectangle*>(f);
    if (rectangle) {
        os << "  {\n";
        os << "    \"name\": \"Rectangle\",\n";
        os << "    \"largeur\": \"" << rectangle->_largeur << "\",\n";
        os << "    \"hauteur\": \"" << rectangle->_hauteur << "\"\n";
        os << "  }";
        return;
    }

}

void Canevas::exportJSON(std::ostream & os, const std::string & what) const {
    if (what == "resume") {
        os << "[\n";
        os << "  {\n";
        os << "    \"name\": \"Canevas\",\n";
        os << "    \"aireTotale\": \"" << aireTotale() << "\"\n";;
        os << "  }\n";
        os << "]\n";
        return;
    }

    if (what == "descriptions") {
        os << "[\n";
        if (not _formes.empty()) {
            auto iter = _formes.begin();
            exportFormeJSON(os, iter->get());
            ++iter;
            for ( ; iter!=_formes.end(); ++iter) {
                os << ",\n";
                exportFormeJSON(os, iter->get());
            }
        }
        os << "\n]\n";
        return;
    }
}


