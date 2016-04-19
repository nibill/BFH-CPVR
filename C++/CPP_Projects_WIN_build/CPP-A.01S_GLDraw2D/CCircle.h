#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CPoint.h"

class CCircle
{
private:
	CPoint center;
	float radius;
	static unsigned long ulCount;

public:
	CCircle();
	CCircle(CPoint center, float radius);
	CCircle(const CCircle& circle);
	~CCircle();
	void set(CPoint center, float radius);
	void set(float x, float y, float r);
	void list();
	static int listCount();
};
#endif //CCIRCLE_H
