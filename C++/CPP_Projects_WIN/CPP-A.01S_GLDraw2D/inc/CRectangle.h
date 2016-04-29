#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CPoint.h"
#include <string>
using namespace std;

class CRectangle
{

private:
	CPoint tLeft;
	CPoint bRight;
	static unsigned long ulCount;

public:
	CRectangle();
	CRectangle(CPoint tLeft, CPoint bRight);
	CRectangle(float x1, float y1, float x2, float y2);
	CRectangle(const CRectangle& rect);
	CRectangle operator+(CRectangle rect);
	~CRectangle();

	void set(CPoint tLeft, CPoint bRight);
	void set(float x1, float y1, float x2, float y2);
	string list();
	void draw();
	static unsigned long listCount();
};

#endif //CRECTANGLE_H
