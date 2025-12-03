#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "grid.hpp"   // ⚡ nécessaire pour avoir Grid

class GridWidget;
class QPushButton;
class QSlider;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startStop();
    void updateGrid();
    void resetGrid();
    void randomizeGrid();

private:
    // ⚡ La grille vit aussi longtemps que MainWindow
    Grid gridData;

    GridWidget *grid;
    QPushButton *startButton;
    QPushButton *resetButton;
    QPushButton *randomButton;
    QSlider *speedSlider;
    QTimer *timer;

};

#endif
