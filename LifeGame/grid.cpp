#include <random>
#include "grid.hpp"

// offsets pour les 8 voisins
static const int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
static const int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

Grid createGrid(int rows, int cols, bool wrap) {
    Grid g;
    g.rows = rows;
    g.cols = cols;
    g.cells.reserve(rows * cols);

    for (int i = 0; i < rows * cols; ++i)
        g.cells.push_back(std::make_unique<Cellule>(false));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Cellule* cur = g.at(r, c);
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (wrap) {
                    nr = (nr + rows) % rows;
                    nc = (nc + cols) % cols;
                    cur->setVoisin(k, g.at(nr, nc));
                } else {
                    cur->setVoisin(k, g.at(nr, nc));
                }
            }
        }
    }

    return g;
}
void evolve(Grid& g, bool wrap) {
    std::vector<bool> next(g.rows * g.cols);

    for (int r = 0; r < g.rows; r++) {
        for (int c = 0; c < g.cols; c++) {
            Cellule* cell = g.at(r, c);
            int n = cell->compterVoisinsVivants();
            bool alive = cell->estVivante();

            if (alive && (n == 2 || n == 3)) next[r*g.cols+c] = true;
            else if (!alive && n == 3)       next[r*g.cols+c] = true;
            else                             next[r*g.cols+c] = false;
        }
    }

    for (int i = 0; i < g.rows * g.cols; i++)
        g.cells[i]->setEtat(next[i]);
}

// 🔧 Nouvelle méthode : remet toutes les cellules à mortes
void Grid::clear() {
    for (auto& cell : cells) {
        if (cell) cell->setEtat(false);
    }
}

// 🔧 Nouvelle méthode : attribue aléatoirement vivante/morte
void Grid::randomize() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    for (auto& cell : cells) {
        if (cell) cell->setEtat(dist(gen) == 1);
    }
}

void Grid::placeBlock(int r, int c, Grid& grid) {
    if (Cellule* cell = grid.at(r, c)) {
        cell->setEtat(true);
        grid.at(r+1,c)->setEtat(true);
        grid.at(r,c+1)->setEtat(true);
        grid.at(r+1,c+1)->setEtat(true);
    }
}

void Grid::placeBlinker(int r, int c, Grid& grid) {
    if (Cellule* cell = grid.at(r, c)) {
        cell->setEtat(true);
        grid.at(r,c-1)->setEtat(true);
        grid.at(r,c+1)->setEtat(true);
    }
}

void Grid::placeGlider(int r, int c, Grid& grid) {
    if (Cellule* cell = grid.at(r, c)) {
        cell->setEtat(true);
        grid.at(r+1,c+1)->setEtat(true);
        grid.at(r+2,c+1)->setEtat(true);
        grid.at(r+2,c)->setEtat(true);
        grid.at(r+2,c-1)->setEtat(true);
    }
}

void Grid::placeFactory(int r, int c, Grid& grid) {
    if (Cellule* cell = grid.at(r, c)) {
        cell->setEtat(true);
        grid.at(r,c-16)->setEtat(true);
        grid.at(r,c-15)->setEtat(true);
        grid.at(r+1,c-16)->setEtat(true);
        grid.at(r+1,c-15)->setEtat(true);
        grid.at(r,c-6)->setEtat(true);
        grid.at(r+1,c-6)->setEtat(true);
        grid.at(r+2,c-6)->setEtat(true);
        grid.at(r-1,c-5)->setEtat(true);
        grid.at(r+3,c-5)->setEtat(true);
        grid.at(r-2,c-4)->setEtat(true);
        grid.at(r-2,c-3)->setEtat(true);
        grid.at(r+4,c-4)->setEtat(true);
        grid.at(r+4,c-3)->setEtat(true);
        grid.at(r+1,c-2)->setEtat(true);
        grid.at(r-1,c-1)->setEtat(true);
        grid.at(r+3,c-1)->setEtat(true);
        grid.at(r+1,c)->setEtat(true);
        grid.at(r+2,c)->setEtat(true);
        grid.at(r+1,c+1)->setEtat(true);
        grid.at(r,c+4)->setEtat(true);
        grid.at(r,c+5)->setEtat(true);
        grid.at(r-1,c+4)->setEtat(true);
        grid.at(r-1,c+5)->setEtat(true);
        grid.at(r-2,c+4)->setEtat(true);
        grid.at(r-2,c+5)->setEtat(true);
        grid.at(r-3,c+6)->setEtat(true);
        grid.at(r+1,c+6)->setEtat(true);
        grid.at(r-4,c+8)->setEtat(true);
        grid.at(r-3,c+8)->setEtat(true);
        grid.at(r+2,c+8)->setEtat(true);
        grid.at(r+1,c+8)->setEtat(true);
        grid.at(r-1,c+18)->setEtat(true);
        grid.at(r-1,c+19)->setEtat(true);
        grid.at(r-2,c+18)->setEtat(true);
        grid.at(r-2,c+19)->setEtat(true);
    }
}
