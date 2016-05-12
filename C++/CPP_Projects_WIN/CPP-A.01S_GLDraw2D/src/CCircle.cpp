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

CCircle CCircle::operator+(CCircle circ)
{
	float radius = 0;
	CPoint center = cent;
	CPoint direction = circ.cent - cent;

	float delta = sqrtf((float)
		(-cent.x + circ.cent.x)*(-cent.x + circ.cent.x) +
		(-cent.y + circ.cent.y)*(-cent.y + circ.cent.y)
		);

	if(delta < min(rad, circ.rad))
	{
		// circles delta smaller than minimal radius, use existing circle
		if(rad < circ.rad)
		{
			radius = circ.rad;
			center = circ.cent;
		}
		else
		{
			radius = rad;
			center = cent;
		}
	}
	else
	{
		// circles delta greater than minium radius, calculate new circle
		radius = (delta + rad + circ.rad) / 2.0F;
		direction.x = (direction.x / delta) * (radius - rad);
		direction.y = (direction.y / delta) * (radius - rad);
		center = cent + direction;
	}

	return CCircle(center, radius);
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
	return "Circle -> center: " + cent.list() + " Radius: " + to_string(rad);
}

void CCircle::draw()
{
	glPushMatrix();
		glTranslatef((GLfloat)cent.x, (GLfloat)cent.y, 0.0);
		gluDisk(gluNewQuadric(), rad, rad, 100, 1);
	glPopMatrix();
}


int CCircle::listCount()
{
	return ulCount;
}