#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include "tile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleTileClick(int index);

private:
    Ui::MainWindow *ui;
    QVector<Tile> tiles;
    QVector<QPushButton*> buttons;
    void setupGame();
};

#endif // MAINWINDOW_H
