#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  int rows, cols;
  int level, score, hiScore;
  char next;
  char **theDisplay;
  
public:
  TextDisplay(int r, int c);
  ~TextDisplay();

  void notify(int r, int c, char ch);
  void update(int lvl, int scr, int hiscr, char type);
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
