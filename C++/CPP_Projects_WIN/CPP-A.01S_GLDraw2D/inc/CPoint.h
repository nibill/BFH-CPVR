#ifndef CPOINT_H
#define CPOINT_H

#include <string>

#include "Figure.h"

using namespace std;

class CPoint : public CFigure
{
	friend class CLine;
	friend class CRectangle;
	friend class CCircle;

private:
	float x, y;
	static unsigned long ulCount;
	
public:
	CPoint();
	CPoint(float x, float y);
	CPoint(const CPoint& point);
	CPoint operator+(CPoint point);
	CPoint operator-(CPoint point);
	~CPoint();

	void set(float x, float y);
	string list();
	void draw();
	static int listCount();
};

#endif //CPOINT_H