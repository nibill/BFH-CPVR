#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/CLine.h"
#include "../inc/Drawing.h"

using namespace std;

unsigned long CLine::ulCount = 0;

CLine::CLine() :
	p1(),
	p2()
{
	ulCount++;
}

CLine::CLine(CPoint start, CPoint end) :
	p1(start),
	p2(end)
{
	ulCount++;
}

CLine::CLine(float x1, float y1, float x2, float y2) :
	p1(x1, y1),
	p2(x2, y2)
{
	ulCount++;
}

CLine::CLine(const CLine & line):
	p1(line.p1),
	p2(line.p2)
{
	ulCount++;
}

CLine& CLine::operator=(const CLine& line)
{
	p1 = line.p1;
	p2 = line.p2;

	return *this;
}

CLine CLine::operator+(CLine vector)
{
	// a + b entspricht a.operator(b)
	float px1 = p1.x, py1 = p1.y, px2 = p2.x, py2 = p2.y;
	float vx1 = vector.p1.x, vy1 = vector.p1.y, vx2 = vector.p2.x, vy2 = vector.p2.y;

	CLine tempLine;
	tempLine.p1.x = px1;
	tempLine.p1.y = py1;
	tempLine.p2.x = px2 + vx2 - vx1;
	tempLine.p2.y = py2 + vy2 - vy1;

	return tempLine;
}

CLine::~CLine()
{
	ulCount--;
}

void CLine::set(CPoint start, CPoint end)
{
	p1 = start;
	p2 = end;
}

void CLine::set(float x1, float y1, float x2, float y2)
{
	p1 = CPoint(x1, y1);
	p2 = CPoint(x2, y2);
}

string CLine::list()
{
	return "p1 (" + p1.list() + "), p2 (" + p2.list() + ")";
}

void CLine::draw(void)
{
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}

int CLine::listCount()
{
	return ulCount;
}
