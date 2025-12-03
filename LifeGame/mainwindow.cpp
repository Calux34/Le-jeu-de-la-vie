#include "mainwindow.hpp"
#include "gridwidget.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    gridData(createGrid(100, 190, true)) // ⚡ grille 100x100 wrap=true
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *layout = new QVBoxLayout(central);

    grid = new GridWidget(gridData, this);
    layout->addWidget(grid);

    startButton = new QPushButton("Démarrer / Arrêter", this);
    layout->addWidget(startButton);

    resetButton = new QPushButton("Réinitialiser", this);
    layout->addWidget(resetButton);

    randomButton = new QPushButton("Aléatoire", this);
    layout->addWidget(randomButton);

    speedSlider = new QSlider(Qt::Horizontal, this);
    speedSlider->setRange(50, 2000);
    speedSlider->setValue(500);
    layout->addWidget(speedSlider);

    timer = new QTimer(this);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startStop);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetGrid);
    connect(randomButton, &QPushButton::clicked, this, &MainWindow::randomizeGrid);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGrid);
    connect(speedSlider, &QSlider::valueChanged, this, [this](int value) {
        timer->setInterval(value);
    });
}

MainWindow::~MainWindow() {}

void MainWindow::startStop() {
    if (timer->isActive())
        timer->stop();
    else
        timer->start(speedSlider->value());
}

void MainWindow::updateGrid() {
    evolve(gridData, true); // ⚡ fait évoluer la grille membre
    grid->update();         // redessine
}

void MainWindow::resetGrid() {
    gridData.clear();
    grid->update();
}

void MainWindow::randomizeGrid() {
    gridData.randomize();
    grid->update();
}


