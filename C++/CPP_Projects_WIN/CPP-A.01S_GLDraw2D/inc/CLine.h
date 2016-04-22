#ifndef CLINE_H
#define CLINE_H

#include "CPoint.h"

class CLine
{
private:
	CPoint p1;
	CPoint p2;
	static unsigned long ulCount;

public:
	CLine();
	CLine(CPoint start, CPoint end);
	CLine(float x1, float y1, float x2, float y2);
	CLine(const CLine& line);
	CLine& operator=(const CLine& line);
	CLine operator+(CLine vector);
	~CLine();

	void set(CPoint, CPoint);
	void set(float x1, float y1, float x2, float y2);
	string list();
	void draw();
	static int listCount();
};

#endif // !CLINE_H

