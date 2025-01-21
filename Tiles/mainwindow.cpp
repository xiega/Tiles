#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupGame() {
    // Tworzenie kafelków
    for (int i = 0; i < 9; ++i) {
        Tile::Color color = static_cast<Tile::Color>(QRandomGenerator::global()->bounded(3));
        Tile::Symbol symbol = static_cast<Tile::Symbol>(QRandomGenerator::global()->bounded(3));
        tiles.append(Tile(color, symbol));
    }

    // Tworzenie przycisków dla kafelków
    for (int i = 0; i < 9; ++i) {
        QPushButton *button = new QPushButton(tiles[i].colorToString() + " - " + tiles[i].symbolToString(), this);
        button->setStyleSheet("background-color: " + tiles[i].colorToString().toLower() + ";");
        connect(button, &QPushButton::clicked, this, [this, i]() { handleTileClick(i); });
        buttons.append(button);
        ui->gridLayout->addWidget(button, i / 3, i % 3);  // Przypisanie przycisków do siatki
    }
}


void MainWindow::handleTileClick(int index) {
    // Implementacja logiki gry: po kliknięciu kafelka
    QLabel *label = new QLabel("Tile clicked: " + tiles[index].colorToString() + " " + tiles[index].symbolToString(), this);
    label->move(150, 350);
    label->show();
}
