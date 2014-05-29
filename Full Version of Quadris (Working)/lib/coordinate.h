#ifndef __COORINDATE_H__
#define __COORINDATE_H__

class Coordinate {
	int x;
	int y;
	
public:
	Coordinate();
	Coordinate(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void addX(const int n);
	void addY(const int n);
};

#endif