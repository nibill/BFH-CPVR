#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <string>

using namespace std;

class CFigure
{
public:
	virtual void draw(void) = 0;
	virtual void list(void) = 0;

	virtual ~CFigure() = 0;
};

inline CFigure::~CFigure() {};
#endif
