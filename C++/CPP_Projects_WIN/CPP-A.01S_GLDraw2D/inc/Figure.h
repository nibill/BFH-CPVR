#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

using namespace std;

class CFigure
{
public:
	virtual void draw(void) = 0;
	virtual string list() = 0;
	
	virtual ~CFigure();
};

inline CFigure::~CFigure() {};
#endif
