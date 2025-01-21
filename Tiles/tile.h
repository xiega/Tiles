#ifndef TILE_H
#define TILE_H

#include <QString>

class Tile {
public:
    enum class Color {
        Red, Blue, Green
    };

    enum class Symbol {
        A, B, C
    };

    Tile(Color color, Symbol symbol) : color(color), symbol(symbol) {}

    Color getColor() const { return color; }
    Symbol getSymbol() const { return symbol; }

    QString colorToString() const {
        switch (color) {
        case Color::Red: return "Red";
        case Color::Blue: return "Blue";
        case Color::Green: return "Green";
        }
        return "Unknown";
    }

    QString symbolToString() const {
        switch (symbol) {
        case Symbol::A: return "A";
        case Symbol::B: return "B";
        case Symbol::C: return "C";
        }
        return "Unknown";
    }

private:
    Color color;
    Symbol symbol;
};

#endif // TILE_H
