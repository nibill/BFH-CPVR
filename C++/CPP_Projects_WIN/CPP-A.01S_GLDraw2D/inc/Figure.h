#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

using namespace std;

class CFigure
{
private:
	static unsigned long ulCount;
public:
	static void listCount();

	virtual void draw(void) = 0;
	virtual string list() = 0;
	virtual void laod(std::iostream*) = 0;
	virtual void save(std::ostream*) = 0;
	
	virtual ~CFigure();
};

inline CFigure::~CFigure() {};
#endif
