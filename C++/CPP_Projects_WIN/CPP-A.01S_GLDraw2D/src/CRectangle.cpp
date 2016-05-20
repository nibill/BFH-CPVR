#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>

#include "../inc/CRectangle.h"
#include "../inc/Drawing.h"

#include <GL/glew.h>
//#include <FL/glut.H>

using namespace std;

unsigned long CRectangle::ulCount = 0;

CRectangle::CRectangle() :
	tLeft(),
	bRight()
{
	ulCount++;
}

CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) :
	tLeft(topLeft),
	bRight(bottomRight)
{
	ulCount++;
}

CRectangle::CRectangle(float x1, float y1, float x2, float y2) :
	tLeft(x1, y1),
	bRight(x2, y2)
{
	ulCount++;
}

CRectangle::CRectangle(const CRectangle & rect) :
	tLeft(rect.tLeft),
	bRight(rect.bRight)
{
	ulCount++;
}

CRectangle CRectangle::operator+(CRectangle rect)
{
	CPoint rect1tl = tLeft;
	CPoint rect1br = bRight;
	CPoint rect2tl = rect.tLeft;
	CPoint rect2br = rect.bRight;

	float Rect1P1X = rect1tl.x;
	float Rect1P1Y = rect1tl.y;
	float Rect1P2X = rect1br.x;
	float Rect1P2Y = rect1br.y;

	float Rect2P1X = rect2tl.x;
	float Rect2P1Y = rect2tl.y;
	float Rect2P2X = rect2br.x;
	float Rect2P2Y = rect2br.y;

	CRectangle boundingBox;
	boundingBox.tLeft.x = min({ Rect1P1X, Rect1P2X, Rect2P1X, Rect2P2X });
	boundingBox.tLeft.y = max({ Rect1P1Y, Rect1P2Y, Rect2P1Y, Rect2P2Y });
	boundingBox.bRight.x = max({ Rect1P1X, Rect1P2X, Rect2P1X, Rect2P2X });
	boundingBox.bRight.y = min({ Rect1P1Y, Rect1P2Y, Rect2P1Y, Rect2P2Y });

	return boundingBox;
}

CRectangle::~CRectangle()
{
	ulCount--;
}

void CRectangle::set(CPoint topLeft, CPoint bottomRight)
{
	tLeft = topLeft;
	bRight = bottomRight;
}

void CRectangle::set(float x1, float y1, float x2, float y2)
{
	tLeft = CPoint(x1, y1);
	bRight = CPoint(x2, y2);
}

string CRectangle::list()
{
	return "Rectangle -> TL: " + tLeft.list() + " br: " + bRight.list();
}

void CRectangle::draw()
{
	glRectf(tLeft.x, tLeft.y, bRight.x, bRight.y);
}

unsigned long CRectangle::listCount()
{
	return ulCount;
}
