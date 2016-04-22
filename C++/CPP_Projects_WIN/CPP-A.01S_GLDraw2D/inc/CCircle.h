#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CPoint.h"

class CCircle
{
private:
	CPoint cent;
	float rad;
	static unsigned long ulCount;

public:
	CCircle();
	CCircle(CPoint cent, float rad);
	CCircle(float x, float y, float r);
	CCircle(const CCircle& circle);
	~CCircle();

	void set(CPoint cent, float rad);
	void set(float x, float y, float r);
	string list();
	void draw();
	static int listCount();
};
#endif //CCIRCLE_H
