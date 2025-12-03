#include "classe.hpp"
#include <iostream>

Cellule::Cellule(bool etat) {
    spe = (std::rand() % 1000 == 0) ? 1 : -1;
    vivante = etat;
    for (int i = 0; i < 8; ++i) {
        voisins[i] = nullptr;
    }
}

bool Cellule::estVivante() const {
    if (spe == 1)
        return true;
    else
        return vivante;
}

void Cellule::setEtat(bool etat) {
    vivante = etat;
}

void Cellule::changeState() {
    if (spe == -1)
        vivante = !vivante;
    else
        vivante = true;
}

void Cellule::setVoisin(int index, Cellule* voisin) {
    if (index >= 0 && index < 8) {
        voisins[index] = voisin;
    }
}

Cellule* Cellule::getVoisin(int index) const {
    if (index >= 0 && index < 8) {
        return voisins[index];
    }
    return nullptr;
}

int Cellule::compterVoisinsVivants() const {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (voisins[i] && voisins[i]->estVivante()) {
            ++count;
        }
    }
    return count;
}
