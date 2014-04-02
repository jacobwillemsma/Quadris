#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;
  const int rows;
  const int cols;
  int level; // marks the level
  int score; // current score
  int hiScore; // hiscore
  char nextType; // marks the type of next block
  
 public:
  TextDisplay(int r, int c);

  void notify(int r, int c, char ch); // notifies the TextDisplay of a possible change in char
  void displayUpdate(int lvl, int scr, int hs, char type); // updates variables in the display
  

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td); // prints the TextDisplay
};

#endif
