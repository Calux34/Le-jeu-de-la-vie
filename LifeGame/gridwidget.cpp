#include "gridwidget.hpp"
#include <QPainter>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>


GridWidget::GridWidget(Grid& g, QWidget* parent)
    : QWidget(parent), grid(g)
{
    setMinimumSize(400,400);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
}

void GridWidget::paintEvent(QPaintEvent*) {
    QPainter p(this);
    int cellW = width() / grid.cols;
    int cellH = height() / grid.rows;

    for (int r = 0; r < grid.rows; r++) {
        for (int c = 0; c < grid.cols; c++) {
            QRect rect(c * cellW, r * cellH, cellW, cellH);
            if (grid.at(r,c)->spe == 1)
                p.fillRect(rect, Qt::red);
            else
                if (grid.at(r, c)->estVivante())
                    p.fillRect(rect, Qt::white);
                else
                    p.fillRect(rect, Qt::black);

            p.drawRect(rect);
        }
    }
}

void GridWidget::mousePressEvent(QMouseEvent* e) {
    int cellW = width() / grid.cols;
    int cellH = height() / grid.rows;
    lastMousePos = e->pos();
    int c = e->pos().x() / cellW;
    int r = e->pos().y() / cellH;

    if (Cellule* cell = grid.at(r, c)) {
        cell->changeState();
        update();
    }
}

void GridWidget::clear() {
    grid.clear();
    update();
}

void GridWidget::randomize() {
    grid.randomize();
    update();
}

Grid* GridWidget::getGrid() {
    return &grid;
}

void GridWidget::keyPressEvent(QKeyEvent *event)
{
    int cellW = width() / grid.cols;
    int cellH = height() / grid.rows;

    int c = lastMousePos.x() / cellW;
    int r = lastMousePos.y() / cellH;

    switch (event->key())
    {
    case Qt::Key_A:
        grid.placeBlock(r, c, grid);
        update();
        break;

    case Qt::Key_Z:
        grid.placeBlinker(r, c, grid);
        update();
        break;

    case Qt::Key_E:
        grid.placeGlider(r, c, grid);
        update();
        break;

    case Qt::Key_R:
        grid.placeFactory(r, c, grid);
        update();
        break;

    case Qt::Key_T:
        if (Cellule* cell = grid.at(r, c)) {
            cell-> spe = cell->spe * -1;
            update();
        }

    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
