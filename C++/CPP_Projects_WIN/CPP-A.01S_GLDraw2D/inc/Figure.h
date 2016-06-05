#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

using namespace std;
class CPoint;

class CFigure
{
private:
	static unsigned long ulCount;
public:
	static void listCount();

	CFigure();
	CFigure(const CFigure&);
	virtual ~CFigure();

	virtual string list(void) = 0;
	virtual void draw(void) = 0;
	virtual void load(std::istream*) = 0;
	virtual void save(std::ostream*) = 0;
};

inline CFigure::~CFigure() {};
#endif
