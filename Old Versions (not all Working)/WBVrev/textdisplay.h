#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  int rows, cols;
  int level, score, hiScore; // variables for printing
  char next; // marks the next block to display
  char **theDisplay;
  
 public:
  TextDisplay(int r, int c);
  void notify(int r, int c, char ch);
  ~TextDisplay();
  
  void update(int lvl, int scr, int hiscr, char type); // updates level and scores for printing

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td); // prints the TextDisplay
};

#endif
