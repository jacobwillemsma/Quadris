#include "coordinate.h"

Coordinate::Coordinate() : x(-1), y(-1) {}
Coordinate::Coordinate(int x, int y) : x(x), y(y) {}
int Coordinate::getX() { return x; }
int Coordinate::getY() { return y; }
void Coordinate::setX(int x) { x = x;}
void Coordinate::setY(int y) { y = y;}