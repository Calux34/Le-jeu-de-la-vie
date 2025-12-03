#ifndef GRIDWIDGET_HPP
#define GRIDWIDGET_HPP

#include <QWidget>
#include "grid.hpp"

class GridWidget : public QWidget {
    Q_OBJECT
public:
    explicit GridWidget(Grid& g, QWidget* parent = nullptr);

    void clear();        // remet à 0
    void randomize();    // état aléatoire
    Grid* getGrid();     // accès à la grille

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* e) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Grid& grid;
    QPoint lastMousePos;

};

#endif // GRIDWIDGET_HPP
