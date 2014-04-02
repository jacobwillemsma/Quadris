#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"
#include "display.h"
#include "xwindow.h"

class Grid {
  Cell **theGrid;  // The actual grid.
  TextDisplay *td; // The text display.
  Xwindow *w;

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();
  
  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);
  void init(int r, int c);
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
