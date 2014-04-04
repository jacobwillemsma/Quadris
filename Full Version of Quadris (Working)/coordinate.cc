#include "coordinate.h"


/*
This is a very simple (x,y) coordinate class.  Not much explination required here.
Very basic and redimentary.
*/

Coordinate::Coordinate() : x(-1), y(-1) {} // Initially set to (-1, -1) as a check for misassignment.
Coordinate::Coordinate(int x, int y) : x(x), y(y) {}
int Coordinate::getX() { return x; }
int Coordinate::getY() { return y; }
void Coordinate::setX(int x) { this->x = x;}
void Coordinate::setY(int y) { this->y = y;}
void Coordinate::addX(const int n) { x += n;}
void Coordinate::addY(const int n) { y += n;}