#ifndef CPOINT_H
#define CPOINT_H

#include <string>

using namespace std;

class CPoint
{
	//warum wird CLine erkannt?
	friend class CLine;
	friend class CRectangle;

private:
	float x, y;
	static unsigned long ulCount;
	
public:
	CPoint();
	CPoint(float x, float y);
	CPoint(const CPoint& point);
	~CPoint();

	void set(float x, float y);
	string list();
	void draw();
	static int listCount();
};

#endif //CPOINT_H