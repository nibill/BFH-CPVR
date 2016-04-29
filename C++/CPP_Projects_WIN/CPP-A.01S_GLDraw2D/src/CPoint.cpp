#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/CPoint.h"
#include "../inc/Drawing.h"

using namespace std;

unsigned long CPoint::ulCount = 0;

CPoint::CPoint():
	x(0),
	y(0)
{
	ulCount++;
}

CPoint::CPoint(float x, float y):
	x(x),
	y(y)
{
	ulCount++;
}

CPoint::CPoint(const CPoint & point):
	x(point.x),
	y(point.y)
{
	ulCount++;
}

CPoint CPoint::operator+(CPoint point)
{
	return CPoint(x + point.x, y + point.y);
}

CPoint CPoint::operator-(CPoint point)
{
	return CPoint(x - point.x, y - point.y);
}

CPoint::~CPoint()
{
	ulCount--;
}

void CPoint::set(float X, float Y)
{
	x = X;
	y = Y;
}

string CPoint::list()
{
	return "Point -> x: " + to_string(x) + " y: " + to_string(y);
}

void CPoint::draw(void)
{
	// cout << "DEBUG: CPoint::draw() x=" << x << " y=" << y << endl;

	// define the size of cross
	static const float crosslength = 5;

	// draw the cross using two lines
	glBegin(GL_LINES);
	glVertex2f(x - crosslength, y);
	glVertex2f(x + crosslength + 1, y);
	glVertex2f(x, y - (crosslength + 1));
	glVertex2f(x, y + crosslength);
	glEnd();
}

int CPoint::listCount()
{
	return ulCount++;
}
