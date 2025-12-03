#ifndef CLASSE_HPP
#define CLASSE_HPP

class Cellule {
public:
    explicit Cellule(bool etat = false);
    int spe;
    bool estVivante() const;
    void setEtat(bool etat);
    void changeState();

    void setVoisin(int index, Cellule* voisin);
    Cellule* getVoisin(int index) const;
    int compterVoisinsVivants() const;

private:
    bool vivante;
    Cellule* voisins[8];
};

#endif // CLASSE_HPP

