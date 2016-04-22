#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/CCircle.h"
#include "../inc/Drawing.h"

using namespace std;

using namespace std;
unsigned long CCircle::ulCount = 0;

CCircle::CCircle() :
	cent(),
	rad(0)
{
	ulCount++;
}

CCircle::CCircle(CPoint center, float radius) :
cent(center),
rad(radius)
{
	ulCount++;
}

CCircle::CCircle(float x, float y, float r):
cent(x, y),
rad(r)
{
	ulCount++;
}

CCircle::CCircle(const CCircle& circle) :
	cent(circle.cent),
	rad(circle.rad)
{
	ulCount++;
}

CCircle::~CCircle()
{
	ulCount--;
}

void CCircle::set(CPoint center, float radius)
{
	cent = center;
	rad = radius;
}

void CCircle::set(float x, float y, float r)
{
	cent = CPoint(x, y);
	rad = r;
}

string CCircle::list()
{
	return "center: " + cent.list() + " Radius: " + to_string(rad);
}

int CCircle::listCount()
{
	return ulCount;
}
