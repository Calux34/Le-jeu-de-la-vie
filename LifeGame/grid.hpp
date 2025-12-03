#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <memory>
#include "classe.hpp"

struct Grid {
    int rows;
    int cols;
    std::vector<std::unique_ptr<Cellule>> cells;

    Cellule* at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return nullptr;
        return cells[r * cols + c].get();
    }

    // 🔧 Ajout des méthodes utilitaires
    void clear();       // remet toutes les cellules à "mortes"
    void randomize();
    void placeBlock(int row, int col, Grid& g);
    void placeBlinker(int row, int col, Grid& g);
    void placeGlider(int row, int col, Grid& g);
    void placeFactory(int row, int col, Grid& g);    // attribue aléatoirement vivante/morte
};

Grid createGrid(int rows, int cols, bool wrap);
void evolve(Grid& g, bool wrap);

#endif // GRID_HPP
